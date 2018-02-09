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

void CreateSprite(std::vector<JMP::Value>& param) {
  auto& core = Core::instance();
  if (core.texture_factory_.find(param[0].text_) == core.texture_factory_.end()) {
    Texture texture;
    texture.init(param[1].text_.c_str());
    texture.set_pivot(kSpritePivotPoint_UpLeft);
    texture.set_position({ 100.0f, 100.0f });
    texture.set_size({ 100.0f, 100.0f });
    core.texture_factory_[param[0].text_] = texture;
  }
}

void RenderSprite(std::vector<JMP::Value>& param) {
  auto& core = Core::instance();
  if (core.texture_factory_.find(param[0].text_) == core.texture_factory_.end()) {
    printf("ERROR: Couldnt find sprite name : \"%s\"", param[0].text_.c_str());
    return;
  }
  core.texture_factory_[param[0].text_].render();
}

int32 main() {

  JMP::Machine jmp;
  jmp.processFile("../scripts/config.jmp");
  jmp.registerFunction("CreateSprite", &CreateSprite);
  jmp.registerFunction("RenderSprite", &RenderSprite);

  Window::Init(jmp.getInteger("width", "Window"), jmp.getInteger("height", "Window"));
  jmp.runFunction("Init()");

  while (Window::IsOpened()) {
    Window::Clear();
    jmp.runFunction("Update()");    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
