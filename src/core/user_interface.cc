/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/



#include "core/user_interface.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_dock.h"
#include "core/core.h"


namespace W2D {


/*******************************************************************************
***                       Constructor And Destructor                         ***
*******************************************************************************/

UserInterface::UserInterface() {
  top_bar_height_ = 0.0f;
  bottom_bar_height_ = 30.0f;
}


UserInterface::~UserInterface() {


}

/*******************************************************************************
***                            Public Methods                                ***
*******************************************************************************/


void UserInterface::setupColors() const {

  ImVec4* colors = ImGui::GetStyle().Colors;
  
  colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
  colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
  colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
  colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
  colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
  colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
  colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
  colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
  colors[ImGuiCol_CloseButton] = ImVec4(0.41f, 0.41f, 0.41f, 0.50f);
  colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
  colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
  colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
  colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
  colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
}

void UserInterface::setupInputKeys() const {
  
  ImGuiIO& io = ImGui::GetIO();

  io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
  io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
  io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
  io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
  io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
  io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
  io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
  io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
  io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
  io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
  io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
  io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
  io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
  io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
  io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
  io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
  io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
  io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
  io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
}



void UserInterface::updateTopBar() {
  auto& core = Core::instance();

  if (ImGui::BeginMainMenuBar()) {

    top_bar_height_ = ImGui::GetWindowSize().y;
    bottom_bar_height_ = top_bar_height_ + 8.0f;

    if (ImGui::BeginMenu("Application")) {
      if (ImGui::MenuItem("Quit", "ESC")) {
        core.window_.is_opened_ = false;
      }
      ImGui::EndMenu();
    }
    
    if (ImGui::BeginMenu("Script")) {
      if (ImGui::MenuItem("Save")) {
        printf("SAVING FILE");
        ImGui::SaveDock();
      }
      if (ImGui::MenuItem("Recompile")) {
        printf("RECOMPILE FILE");
        core.machine_.reloadFromString(core.script_code_);
        core.machine_.runFunction("Init()");
      }
      ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Layout")) {
      if (ImGui::MenuItem("Save")) {
        ImGui::SaveDock();
        printf("EDITOR STYLE SAVED");
      }
      ImGui::EndMenu();
    }


    ImGui::EndMainMenuBar();
  }
}

void UserInterface::updateEditorLayout() const {

  auto& core = Core::instance();
  ImVec2 editor_size = ImGui::GetIO().DisplaySize;
  editor_size.y -= top_bar_height_ + bottom_bar_height_;

  ImGui::SetWindowPos("UserInterface", { 0.0f, top_bar_height_ });
  ImGui::SetWindowSize("UserInterface", editor_size);

  const ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize |
                                        ImGuiWindowFlags_NoTitleBar |
                                        ImGuiWindowFlags_NoMove;

  if (ImGui::Begin("UserInterface", nullptr, window_flags)) {
    // dock layout by hard-coded or .ini file
    ImGui::BeginDockspace();

    updateSceneDock();
    updateScriptDock();
    updateHierarchyDock();

    if (ImGui::BeginDock("EditorConfig")) {
      ImGui::ShowStyleEditor();
    }
    ImGui::EndDock();



    ImGui::EndDockspace();
  }
  ImGui::End();
}

void UserInterface::updateBottomBar() const {

  const ImVec2 display_size = ImGui::GetIO().DisplaySize;
  const ImGuiWindowFlags flags = ImGuiWindowFlags_NoBringToFrontOnFocus |
                                 ImGuiWindowFlags_NoResize |
                                 ImGuiWindowFlags_NoTitleBar |
                                 ImGuiWindowFlags_NoSavedSettings;

  ImGui::SetNextWindowPos({ 0.0f, display_size.y - bottom_bar_height_ }, ImGuiSetCond_Always);
  ImGui::SetNextWindowSize({ display_size.x, bottom_bar_height_ }, ImGuiSetCond_Always);
  ImGui::Begin("statusbar", nullptr, flags);
  ImGui::Text("FPS: %f", ImGui::GetIO().Framerate);
  ImGui::End();


}


void UserInterface::updateHierarchyDock() const {

  if (ImGui::BeginDock("SceneHierarchy")) {
    auto& map = Core::instance().sprite_factory_;
    for (const auto& pair : map) {
      ImGui::PushID(&pair.second);
      if (ImGui::TreeNode(pair.first.c_str())) {
        auto& sprite = map[pair.first];
        ImGui::Image((ImTextureID)sprite.textureID(), { 50.0f, 50.0f });
        glm::vec2 temp = sprite.position();
        if (ImGui::DragFloat2("Position", &temp.x)) { sprite.set_position(temp); }
        temp = sprite.size();
        if (ImGui::DragFloat2("Size", &temp.x)) { sprite.set_size(temp); }
        temp.x = sprite.rotation();
        if (ImGui::DragFloat("Rotation", &temp.x, 0.01f)) { sprite.set_rotation(temp.x); }
        ImGui::TreePop();
      }
      ImGui::PopID();
    }
  }
  ImGui::EndDock();
}

void UserInterface::updateScriptDock() const {

  if (ImGui::BeginDock("JMP Scripting Language")) {
    ImGui::Text("config.jmp");
    ImGui::InputTextMultiline("", Core::instance().script_code_, SCRIPT_CODE_MAX_LENGTH, ImGui::GetContentRegionAvail());
  }
  ImGui::EndDock();
}

void UserInterface::updateSceneDock() const {

  if (ImGui::BeginDock("Scene")) {
    ImGui::Image((ImTextureID)Core::instance().window_.frame_buffer_.texture(), ImGui::GetContentRegionAvail());
  }
  ImGui::EndDock();
}

}; /* W2D */
