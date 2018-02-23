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
#include <fstream>


namespace W2D {


/*******************************************************************************
***                       Constructor And Destructor                         ***
*******************************************************************************/

UserInterface::UserInterface() {
  top_bar_height_ = 0.0f;
  bottom_bar_height_ = 30.0f;
  save_mode_ = 0;
  log_.set_active(true);
}


UserInterface::~UserInterface() {}

/*******************************************************************************
***                            Public Methods                                ***
*******************************************************************************/

void UserInterface::init() const {
  setupInputKeys();
  setupColors();
  setupStyle();
}

void UserInterface::update() {
  updateTopBar();
  updateEditorLayout();
  updateBottomBar();
}



/*******************************************************************************
***                            Private Methods                                ***
*******************************************************************************/

void UserInterface::setupColors() const {

  ImVec4* colors = ImGui::GetStyle().Colors;

  colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
  colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
  colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
  colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 1.00f);
  colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(0.79f, 0.32f, 0.00f, 0.78f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
  colors[ImGuiCol_CheckMark] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_SliderGrab] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(0.79f, 0.32f, 0.00f, 0.78f);
  colors[ImGuiCol_Button] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.79f, 0.32f, 0.00f, 0.78f);
  colors[ImGuiCol_Header] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_HeaderActive] = ImVec4(0.79f, 0.32f, 0.00f, 0.78f);
  colors[ImGuiCol_Separator] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.79f, 0.32f, 0.00f, 0.95f);
  colors[ImGuiCol_CloseButton] = ImVec4(0.92f, 1.00f, 0.00f, 1.00f);
  colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
  colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
  colors[ImGuiCol_PlotLines] = ImVec4(0.92f, 1.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.92f, 1.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.92f, 1.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.92f, 1.00f, 0.00f, 1.00f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.79f, 0.32f, 0.00f, 1.00f);
  colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.92f, 1.00f, 0.00f, 1.00f);
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

void UserInterface::setupStyle() const {
  
  ImGuiStyle& style = ImGui::GetStyle();

  // Editor style
  style.FrameRounding = 6.0f;
  style.WindowRounding = 7.0f;
  style.ChildRounding = 0.0f;
  style.ScrollbarRounding = 9.0f;
  style.GrabRounding = 6.0f;
  style.PopupRounding = 16.0f;

  style.WindowPadding = { 8.0f, 8.0f };
  style.FramePadding = { 4.0f, 3.0f };
  style.TouchExtraPadding = { 0.0f, 0.0f };

  style.ItemSpacing = { 8.0f, 4.0f };
  style.ItemInnerSpacing = { 4.0f, 4.0f };
  style.IndentSpacing = 24.0f;

  style.ScrollbarSize = 15.0f;
  style.GrabMinSize = 12.0f;
  style.WindowBorderSize = 1.0f;
  style.ChildBorderSize = 1.0f;
  style.PopupBorderSize = 1.0f;
  style.FrameBorderSize = 0.0f;

  style.WindowTitleAlign = { 0.0f, 0.5f };
  style.ButtonTextAlign = { 0.5f, 0.5f };
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
      showLastItemDescriptionTooltip("Exit application and closes window");
      ImGui::EndMenu();
    }
    
    /*
  
    if (ImGui::BeginMenu("Script")) {
      if (ImGui::MenuItem("Save")) {
        log_.AddLog_I("SAVING FILE");
      }
      if (ImGui::MenuItem("Recompile")) {
        log_.AddLog_I("RECOMPILE FILE");
        core.machine_.reloadFromString(core.script_code_);
        core.machine_.runFunction("Init()");
      }
      ImGui::EndMenu();
    }
     */

    if (ImGui::BeginMenu("Editor")) {
      if (ImGui::MenuItem("Save Layout")) {
        ImGui::SaveDock();
        log_.AddLog_I("Editor layout style saved.");
      }
      showLastItemDescriptionTooltip("Saves the editor layout in a configuration file.\n"
                                     "So next time that we execute the program, this last\n"
                                     "configuration saved will be loaded.");
      ImGui::EndMenu();
    }


    ImGui::EndMainMenuBar();
  }
}

void UserInterface::updateEditorLayout() {

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

    /* 
     
    if (ImGui::BeginDock("EditorConfig")) {
      ImGui::ShowStyleEditor();
    }
    ImGui::EndDock();
    */

    if (ImGui::BeginDock("Log")) {
      log_.Draw("Wolfy2D log");
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
  ImGui::TextColored({ 202,81,0,255 }, "Wolfy2D & JMP Scripting Language Project"); ImGui::SameLine();
  ImGui::Text("    "); ImGui::SameLine();
  ImGui::Text("Author: Julio Marcelo Picardo Pena"); ImGui::SameLine();
  ImGui::Text("    "); ImGui::SameLine();
  ImGui::Text("Contact: juliomarcelopicardo@gmail.com"); ImGui::SameLine();
  ImGui::Text("    "); ImGui::SameLine();
  ImGui::Text("Student Number: 27026027"); ImGui::SameLine();
  ImGui::Text("    "); ImGui::SameLine();
  ImGui::Text("BSc in Computer Science for Games - Sheffield Hallam University"); ImGui::SameLine();
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

void UserInterface::updateScriptDock() {

  auto& core = Core::instance();
  std::string text = "Compiles and executes the existing code";

  if (ImGui::BeginDock("JMP Scripting Language")) {

    if (ImGui::Button("Compile")) {
      log_.AddLog_I("Compiling and executing script...");
      core.texture_factory_.clear();
      core.sprite_factory_.clear();
      core.machine_.reloadFromString(core.script_code_);
      core.machine_.runFunction("Init()");
    }
    showLastItemDescriptionTooltip(text.c_str());
    
    ImGui::SameLine();
    if (ImGui::Button("Save")) {
      if (save_mode_ == 0) {
        ImGui::SetClipboardText(core.script_code_);
        log_.AddLog_I("Script copied to clipboard.");
      }
      else {
        std::ofstream file(kScriptFilename, std::ios_base::out);
        if (file.is_open()) {
          file << core.script_code_;
        }
        file.close();
        // log
        std::string info = "Script saved into file: \"";
        info = info + kScriptFilename;
        info = info + '\"';
        log_.AddLog_I(info);
      }
    }
    text = "Save mode: \nClipbard - Will copy the whole script text into the clipboard\nFile - Save and overwrite file \"";
    text = text + kScriptFilename;
    text = text + '\"';
    showLastItemDescriptionTooltip(text.c_str());
    ImGui::SameLine();
    ImGui::Combo("##destination", (int*)&save_mode_, "Clipboard\0File\0");

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

void UserInterface::showLastItemDescriptionTooltip(const char* description) const {
  if (ImGui::IsItemHovered()) {
    ImGui::BeginTooltip();
    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
    ImGui::TextUnformatted(description);
    ImGui::PopTextWrapPos();
    ImGui::EndTooltip();
  }
}

}; /* W2D */
