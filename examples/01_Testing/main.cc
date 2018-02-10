/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "Wolfy2D.h"
#include "core\core.h"
#include <map>
#include "core\texture.h"
#include "jmp\jmp.h"


namespace W2D {

void CreateSprite(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  Texture texture;
  texture.init(p[1].text_.c_str());
  texture.set_pivot(kSpritePivotPoint_UpLeft);
  texture.set_position({ 100.0f, 100.0f });
  texture.set_size({ 100.0f, 100.0f });
  core.texture_factory_[p[0].text_] = texture;
}

void RenderSprite(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.texture_factory_.find(p[0].text_) == core.texture_factory_.end()) {
    printf("ERROR: Couldnt find sprite name : \"%s\"", p[0].text_.c_str());
    return;
  }
  core.texture_factory_[p[0].text_].render();
}

void SpriteSetPosition(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.texture_factory_.find(p[0].text_) == core.texture_factory_.end()) {
    printf("ERROR: Couldnt find sprite name : \"%s\"", p[0].text_.c_str());
    return;
  }
  glm::vec2 position = { p[1].float_, p[2].float_ };
  if (p[1].type_ == JMP::kValueType_Integer) { position.x = (float32)p[1].integer_; }
  if (p[2].type_ == JMP::kValueType_Integer) { position.y = (float32)p[2].integer_; }
  core.texture_factory_[p[0].text_].set_position(position);
}

void SpriteSetSize(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.texture_factory_.find(p[0].text_) == core.texture_factory_.end()) {
    printf("ERROR: Couldnt find sprite name : \"%s\"", p[0].text_.c_str());
    return;
  }
  glm::vec2 size = { p[1].float_, p[2].float_ };
  if (p[1].type_ == JMP::kValueType_Integer) { size.x = (float32)p[1].integer_; }
  if (p[2].type_ == JMP::kValueType_Integer) { size.y = (float32)p[2].integer_; }
  core.texture_factory_[p[0].text_].set_size(size);
}

void SpriteSetRotation(std::vector<JMP::Value>& p) {
  auto& core = Core::instance();
  if (core.texture_factory_.find(p[0].text_) == core.texture_factory_.end()) {
    printf("ERROR: Couldnt find sprite name : \"%s\"", p[0].text_.c_str());
    return;
  }
  core.texture_factory_[p[0].text_].set_rotation(p[1].float_);
}


int32 main() {
  system("pause");
  float time = (float32)Time();
  JMP::Machine jmp;
  jmp.processFile("../scripts/config.jmp");
  jmp.registerVariable("time", JMP::kValueType_Float, &time);
  jmp.registerFunction("CreateSprite", &CreateSprite);
  jmp.registerFunction("RenderSprite", &RenderSprite);
  jmp.registerFunction("SpriteSetPosition", &SpriteSetPosition);
  jmp.registerFunction("SpriteSetRotation", &SpriteSetRotation);
  jmp.registerFunction("SpriteSetSize", &SpriteSetSize);

  Window::Init(jmp.getInteger("width", "Window"), jmp.getInteger("height", "Window"));
  jmp.runFunction("Init()");

  while (Window::IsOpened()) {
    Window::Clear();
    time = (float32)Time() * 0.0001f;
    jmp.runFunction("Update()");    if (Input::IsKeyboardButtonDown(Input::kKeyboardButton_SpaceBar)) {      jmp.reload();      jmp.runFunction("Init()");    }    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
