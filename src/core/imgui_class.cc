/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/


#include "core/imgui_class.h"
#include "imgui/imgui_dock.h"
#include "imgui.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "core/core.h"
#include "core/texture.h"
#include <map>

namespace W2D {


#pragma region IMGUI FUNCTIONS
/*******************************************************************************
***                            IMGUI FUNCTIONS                               ***
*******************************************************************************/

void InitImGui() {

  auto& user_interface = Core::instance().user_interface_;

  user_interface.init();
  ImGui::LoadDock();

  ImGuiIO& io = ImGui::GetIO();
  io.Fonts->AddFontFromFileTTF(kFontFilename, 18);

  io.RenderDrawListsFn = RenderDrawListsImGui; // Alternatively you can set this to NULL and call ImGui::GetDrawData() after ImGui::Render() to get the same ImDrawData pointer.
  io.SetClipboardTextFn = SetClipboardTextImGui;
  io.GetClipboardTextFn = GetClipboardTextImGui;
  io.ClipboardUserData = Core::instance().window_.glfw_window_;
}

void FrameImGui() {

  auto& core = Core::instance();

  if (!core.imgui_.font_texture){ CreateDeviceObjectsImGui(); }
   
  ImGuiIO& io = ImGui::GetIO();

  // Setup display size (every frame to accommodate for window resizing)
  int32 w, h;
  int32 display_w, display_h;
  glfwGetWindowSize(core.window_.glfw_window_, &w, &h);
  glfwGetFramebufferSize(core.window_.glfw_window_, &display_w, &display_h);
  io.DisplaySize = ImVec2((float)w, (float)h);
  io.DisplayFramebufferScale = ImVec2(w > 0 ? ((float)display_w / w) : 0, h > 0 ? ((float)display_h / h) : 0);

  // Setup time step
  double current_time = glfwGetTime();
  io.DeltaTime = core.imgui_.global_time > 0.0 ? (float)(current_time - core.imgui_.global_time) : (float)(1.0f / 60.0f);
  core.imgui_.global_time = current_time;

  // Setup inputs
  // (we already got mouse wheel, keyboard keys & characters from glfw callbacks polled in glfwPollEvents())
  if (glfwGetWindowAttrib(core.window_.glfw_window_, GLFW_FOCUSED)) {
    double mouse_x, mouse_y;
    glfwGetCursorPos(core.window_.glfw_window_, &mouse_x, &mouse_y);
    io.MousePos = ImVec2((float)mouse_x, (float)mouse_y);   // Mouse position in screen coordinates (set to -1,-1 if no mouse / on another screen, etc.)
  }
  else {
    io.MousePos = ImVec2(-1, -1);
  }

  for (int32 i = 0; i < 3; ++i) {
    // If a mouse press event came, always pass it as "mouse held this frame", so we don't miss click-release events that are shorter than 1 frame.
    io.MouseDown[i] = core.window_.input_.mouse_button_[i].is_down
      || glfwGetMouseButton(core.window_.glfw_window_, i) != 0;
    //core.window_.data_->mouse_button[i].is_down = false;
  }

  io.MouseWheel = core.window_.input_.mouse_wheel_;
  core.window_.input_.mouse_wheel_ = 0.0f;

  // Hide OS mouse cursor if ImGui is drawing it
  glfwSetInputMode(core.window_.glfw_window_, GLFW_CURSOR, io.MouseDrawCursor ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);

  // Start the frame
  ImGui::NewFrame();
  
  core.user_interface_.update();

}

void ShutdownImGui() {
  InvalidateObjectsImGui();
  ImGui::Shutdown();
}

void RenderImGui() {
  ImGui::Render();
}



#pragma endregion

#pragma region IMGUI PROPERTIES FUNCTIONS

bool CreateFontTextureImGui() {

  Core& core = Core::instance();
  // Build texture atlas
  ImGuiIO& io = ImGui::GetIO();
  unsigned char* pixels;
  int32 width, height;
  io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);   // Load as RGBA 32-bits (75% of the memory is wasted, but default font is so small) because it is more likely to be compatible with user's existing shaders. If your ImTextureId represent a higher-level concept than just a GL texture id, consider calling GetTexDataAsAlpha8() instead to save on GPU memory.

                                                            // Upload texture to graphics system
  GLint last_texture;
  glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
  glGenTextures(1, &core.imgui_.font_texture);
  glBindTexture(GL_TEXTURE_2D, core.imgui_.font_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

  // Store our identifier
  io.Fonts->TexID = (void *)(intptr_t)core.imgui_.font_texture;

  // Restore state
  glBindTexture(GL_TEXTURE_2D, last_texture);

  return true;
}

bool CreateDeviceObjectsImGui() {

  Core& core = Core::instance();
  // Backup GL state
  GLint last_texture, last_array_buffer, last_vertex_array;
  glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
  glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &last_array_buffer);
  glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &last_vertex_array);

  const GLchar *vertex_shader =
    "#version 330\n"
    "uniform mat4 ProjMtx;\n"
    "in vec2 Position;\n"
    "in vec2 UV;\n"
    "in vec4 Color;\n"
    "out vec2 Frag_UV;\n"
    "out vec4 Frag_Color;\n"
    "void main()\n"
    "{\n"
    "	Frag_UV = UV;\n"
    "	Frag_Color = Color;\n"
    "	gl_Position = ProjMtx * vec4(Position.xy,0,1);\n"
    "}\n";

  const GLchar* fragment_shader =
    "#version 330\n"
    "uniform sampler2D Texture;\n"
    "in vec2 Frag_UV;\n"
    "in vec4 Frag_Color;\n"
    "out vec4 Out_Color;\n"
    "void main()\n"
    "{\n"
    "	Out_Color = Frag_Color * texture( Texture, Frag_UV.st);\n"
    "}\n";

  core.imgui_.shader_handle = glCreateProgram();
  core.imgui_.vert_handle = glCreateShader(GL_VERTEX_SHADER);
  core.imgui_.frag_handle = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(core.imgui_.vert_handle, 1, &vertex_shader, 0);
  glShaderSource(core.imgui_.frag_handle, 1, &fragment_shader, 0);
  glCompileShader(core.imgui_.vert_handle);
  glCompileShader(core.imgui_.frag_handle);
  glAttachShader(core.imgui_.shader_handle, core.imgui_.vert_handle);
  glAttachShader(core.imgui_.shader_handle, core.imgui_.frag_handle);
  glLinkProgram(core.imgui_.shader_handle);

  core.imgui_.attrib_location_tex = glGetUniformLocation(core.imgui_.shader_handle, "Texture");
  core.imgui_.attrib_location_proj_mtx = glGetUniformLocation(core.imgui_.shader_handle, "ProjMtx");
  core.imgui_.attrib_location_position = glGetAttribLocation(core.imgui_.shader_handle, "Position");
  core.imgui_.attrib_location_uv = glGetAttribLocation(core.imgui_.shader_handle, "UV");
  core.imgui_.attrib_location_color = glGetAttribLocation(core.imgui_.shader_handle, "Color");

  glGenBuffers(1, &core.imgui_.vbo_handle);
  glGenBuffers(1, &core.imgui_.elements_handle);

  glGenVertexArrays(1, &core.imgui_.vao_handle);
  glBindVertexArray(core.imgui_.vao_handle);
  glBindBuffer(GL_ARRAY_BUFFER, core.imgui_.vbo_handle);
  glEnableVertexAttribArray(core.imgui_.attrib_location_position);
  glEnableVertexAttribArray(core.imgui_.attrib_location_uv);
  glEnableVertexAttribArray(core.imgui_.attrib_location_color);

#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
  glVertexAttribPointer(core.imgui_.attrib_location_position, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)OFFSETOF(ImDrawVert, pos));
  glVertexAttribPointer(core.imgui_.attrib_location_uv, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)OFFSETOF(ImDrawVert, uv));
  glVertexAttribPointer(core.imgui_.attrib_location_color, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ImDrawVert), (GLvoid*)OFFSETOF(ImDrawVert, col));
#undef OFFSETOF

  CreateFontTextureImGui();

  // Restore modified GL state
  glBindTexture(GL_TEXTURE_2D, last_texture);
  glBindBuffer(GL_ARRAY_BUFFER, last_array_buffer);
  glBindVertexArray(last_vertex_array);

  return true;
}

void InvalidateObjectsImGui() {

  Core& core = Core::instance();

  if (core.imgui_.vao_handle) glDeleteVertexArrays(1, &core.imgui_.vao_handle);
  if (core.imgui_.vbo_handle) glDeleteBuffers(1, &core.imgui_.vbo_handle);
  if (core.imgui_.elements_handle) glDeleteBuffers(1, &core.imgui_.elements_handle);
  core.imgui_.vao_handle = core.imgui_.vbo_handle = core.imgui_.elements_handle = 0;

  if (core.imgui_.shader_handle && core.imgui_.vert_handle) glDetachShader(core.imgui_.shader_handle, core.imgui_.vert_handle);
  if (core.imgui_.vert_handle) glDeleteShader(core.imgui_.vert_handle);
  core.imgui_.vert_handle = 0;

  if (core.imgui_.shader_handle && core.imgui_.frag_handle) glDetachShader(core.imgui_.shader_handle, core.imgui_.frag_handle);
  if (core.imgui_.frag_handle) glDeleteShader(core.imgui_.frag_handle);
  core.imgui_.frag_handle = 0;

  if (core.imgui_.shader_handle) glDeleteProgram(core.imgui_.shader_handle);
  core.imgui_.shader_handle = 0;

  if (core.imgui_.font_texture) {
    glDeleteTextures(1, &core.imgui_.font_texture);
    ImGui::GetIO().Fonts->TexID = 0;
    core.imgui_.font_texture = 0;
  }
}


void RenderDrawListsImGui(ImDrawData* draw_data) {

  Core& core = Core::instance();

  // Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
  ImGuiIO& io = ImGui::GetIO();
  int32 fb_width = (int32)(io.DisplaySize.x * io.DisplayFramebufferScale.x);
  int32 fb_height = (int32)(io.DisplaySize.y * io.DisplayFramebufferScale.y);
  if (fb_width == 0 || fb_height == 0)
    return;
  draw_data->ScaleClipRects(io.DisplayFramebufferScale);

  // Backup GL state
  GLint last_program; glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
  GLint last_texture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
  GLint last_active_texture; glGetIntegerv(GL_ACTIVE_TEXTURE, &last_active_texture);
  GLint last_array_buffer; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &last_array_buffer);
  GLint last_element_array_buffer; glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &last_element_array_buffer);
  GLint last_vertex_array; glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &last_vertex_array);
  GLint last_blend_src; glGetIntegerv(GL_BLEND_SRC, &last_blend_src);
  GLint last_blend_dst; glGetIntegerv(GL_BLEND_DST, &last_blend_dst);
  GLint last_blend_equation_rgb; glGetIntegerv(GL_BLEND_EQUATION_RGB, &last_blend_equation_rgb);
  GLint last_blend_equation_alpha; glGetIntegerv(GL_BLEND_EQUATION_ALPHA, &last_blend_equation_alpha);
  GLint last_viewport[4]; glGetIntegerv(GL_VIEWPORT, last_viewport);
  GLint last_scissor_box[4]; glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);
  GLboolean last_enable_blend = glIsEnabled(GL_BLEND);
  GLboolean last_enable_cull_face = glIsEnabled(GL_CULL_FACE);
  GLboolean last_enable_depth_test = glIsEnabled(GL_DEPTH_TEST);
  GLboolean last_enable_scissor_test = glIsEnabled(GL_SCISSOR_TEST);

  // Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled
  glEnable(GL_BLEND);
  glBlendEquation(GL_FUNC_ADD);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDisable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_SCISSOR_TEST);
  glActiveTexture(GL_TEXTURE0);

  // Setup viewport, orthographic projection matrix
  glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
  const float ortho_projection[4][4] =
  {
    { 2.0f / io.DisplaySize.x, 0.0f,                   0.0f, 0.0f },
    { 0.0f,                  2.0f / -io.DisplaySize.y, 0.0f, 0.0f },
    { 0.0f,                  0.0f,                  -1.0f, 0.0f },
    { -1.0f,                  1.0f,                   0.0f, 1.0f },
  };
  glUseProgram(core.imgui_.shader_handle);
  glUniform1i(core.imgui_.attrib_location_tex, 0);
  glUniformMatrix4fv(core.imgui_.attrib_location_proj_mtx, 1, GL_FALSE, &ortho_projection[0][0]);
  glBindVertexArray(core.imgui_.vao_handle);

  for (int32 n = 0; n < draw_data->CmdListsCount; n++)
  {
    const ImDrawList* cmd_list = draw_data->CmdLists[n];
    const ImDrawIdx* idx_buffer_offset = 0;

    glBindBuffer(GL_ARRAY_BUFFER, core.imgui_.vbo_handle);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), (GLvoid*)cmd_list->VtxBuffer.Data, GL_STREAM_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, core.imgui_.elements_handle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx), (GLvoid*)cmd_list->IdxBuffer.Data, GL_STREAM_DRAW);

    for (int32 cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
    {
      const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
      if (pcmd->UserCallback)
      {
        pcmd->UserCallback(cmd_list, pcmd);
      }
      else
      {
        glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
        glScissor((int32)pcmd->ClipRect.x, (int32)(fb_height - pcmd->ClipRect.w), (int32)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int32)(pcmd->ClipRect.w - pcmd->ClipRect.y));
        glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer_offset);
      }
      idx_buffer_offset += pcmd->ElemCount;
    }
  }

  // Restore modified GL state
  glUseProgram(last_program);
  glActiveTexture(last_active_texture);
  glBindTexture(GL_TEXTURE_2D, last_texture);
  glBindVertexArray(last_vertex_array);
  glBindBuffer(GL_ARRAY_BUFFER, last_array_buffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, last_element_array_buffer);
  glBlendEquationSeparate(last_blend_equation_rgb, last_blend_equation_alpha);
  glBlendFunc(last_blend_src, last_blend_dst);
  if (last_enable_blend) glEnable(GL_BLEND); else glDisable(GL_BLEND);
  if (last_enable_cull_face) glEnable(GL_CULL_FACE); else glDisable(GL_CULL_FACE);
  if (last_enable_depth_test) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
  if (last_enable_scissor_test) glEnable(GL_SCISSOR_TEST); else glDisable(GL_SCISSOR_TEST);
  glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
  glScissor(last_scissor_box[0], last_scissor_box[1], (GLsizei)last_scissor_box[2], (GLsizei)last_scissor_box[3]);
}

const char* GetClipboardTextImGui(void* user_data) {
  return glfwGetClipboardString((GLFWwindow*)user_data);
}

void SetClipboardTextImGui(void* user_data, const char* text) {
  glfwSetClipboardString((GLFWwindow*)user_data, text);
}

#pragma endregion


}; /* W2D */
