/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "Wolfy2D.h"
#include "core/core.h"
#include <map>



namespace W2D {

void DrawText(std::vector<JMP::Value>& p) {
  auto& text = Core::instance().text_;
  text.set_position({ p[1].getAsFloat(), p[2].getAsFloat() });
  text.set_size(40);
  text.render(p[0].text_.c_str());
}

void CreateSprite(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();

  if (core.sprite_factory_.find(p[0].text_) == core.sprite_factory_.end()) {
    Sprite sprite;
    sprite.init(p[1].text_.c_str());
    core.sprite_factory_[p[0].text_] = sprite;;
    return;
  }
  std::string warning = "Sprite name : \"";
  warning.append(p[0].text_ + "\", multiple creation");
  core.user_interface_.log_.AddLog_W(warning);
}

void RenderSprite(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.sprite_factory_.find(p[0].text_) == core.sprite_factory_.end()) {
    std::string warning = "RenderSprite: Couldnt find sprite name : \"";
    warning.append(p[0].text_ + "\"");
    core.user_interface_.log_.AddLog_W(warning);
    return;
  }
  core.sprite_factory_[p[0].text_].render();
}

void SpriteSetPosition(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.sprite_factory_.find(p[0].text_) == core.sprite_factory_.end()) {
    std::string warning = "SpriteSetPosition: Couldnt find sprite name : \"";
    warning.append(p[0].text_ + "\"");
    core.user_interface_.log_.AddLog_W(warning);
    return;
  }
  const glm::vec2 position = { p[1].getAsFloat(), p[2].getAsFloat() };
  core.sprite_factory_[p[0].text_].set_position(position);
}

void SpriteSetSize(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.sprite_factory_.find(p[0].text_) == core.sprite_factory_.end()) {
    std::string warning = "SpriteSetSize: Couldnt find sprite name : \"";
    warning.append(p[0].text_ + "\"");
    core.user_interface_.log_.AddLog_W(warning);
    return;
  }
  const glm::vec2 size = { p[1].getAsFloat(), p[2].getAsFloat() };
  core.sprite_factory_[p[0].text_].set_size(size);
}

void SpriteSetRotation(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.sprite_factory_.find(p[0].text_) == core.sprite_factory_.end()) {
    std::string warning = "SpriteSetRotation: Couldnt find sprite name : \"";
    warning.append(p[0].text_ + "\"");
    core.user_interface_.log_.AddLog_W(warning);
    return;
  }
  core.sprite_factory_[p[0].text_].set_rotation(p[1].float_);
}

void DrawLine(std::vector<JMP::Value>& p) {
  const Vec2 origin = { p[0].getAsFloat(), p[1].getAsFloat() };
  const Vec2 destiny = { p[2].getAsFloat(), p[3].getAsFloat() };
  Draw::Line(origin, destiny);
}

int32 main() {
  
  auto& core = Core::instance();
  JMP::Machine& jmp = core.machine_;
  jmp.processFile(kScriptFilename);
  strncpy_s(core.script_code_, SCRIPT_CODE_MAX_LENGTH, jmp.getCurrentScript().c_str(), SCRIPT_CODE_MAX_LENGTH);
  float32 time = (float32)Time();

  jmp.registerVariable("time", JMP::kValueType_Float, &time);
  jmp.registerFunction("LoadSprite", &CreateSprite);
  jmp.registerFunction("Render", &RenderSprite);
  jmp.registerFunction("SetPosition", &SpriteSetPosition);
  jmp.registerFunction("SetRotation", &SpriteSetRotation);
  jmp.registerFunction("SetSize", &SpriteSetSize);
  jmp.registerFunction("DrawLine", &DrawLine);
  jmp.registerFunction("DrawText", &DrawText);

  Window::InitMaximized("Wolfy2D Engine: JMP A Scripting Language for Game Engines - Demo.", false);
  Vec2 window_size = { (float32)Window::Width(), (float32)Window::Height() };
  jmp.registerVariable("width", JMP::kValueType_Float, &window_size.x);
  jmp.registerVariable("height", JMP::kValueType_Float, &window_size.y);
  Vec2 screen_center = { window_size.x * 0.5f, window_size.y * 0.5f };
  jmp.registerVariable("center_x", JMP::kValueType_Float, &screen_center.x);
  jmp.registerVariable("center_y", JMP::kValueType_Float, &screen_center.y);



  jmp.runFunction("Init()");
  
  while (Window::IsOpened() && 
         !Input::IsKeyboardButtonDown(Input::kKeyboardButton_Escape)) {

    Window::Clear();
    time = (float32)Time();
    jmp.runFunction("Update()");    Window::Frame();
  }

  Window::Close();


  return 0;
}

}; /* W2D */
