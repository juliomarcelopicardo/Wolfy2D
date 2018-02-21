/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "core/input_manager.h"
#include "core/core.h"

namespace W2D {
namespace Input {


/*******************************************************************************
***                             Input getters                                ***
*******************************************************************************/
const Vec2 MousePosition() {
  return{ Core::instance().window_.input_.mouse_position_.x ,
          Core::instance().window_.input_.mouse_position_.y };
}

const bool IsMouseButtonDown(MouseButton button) {
  return Core::instance().window_.input_.isMouseButtonDown(button);
}
const bool IsMouseButtonUp(MouseButton button) {
  return Core::instance().window_.input_.isMouseButtonUp(button);
}
const bool IsMouseButtonPressed(MouseButton button) {
  return Core::instance().window_.input_.isMouseButtonPressed(button);
}

const bool IsKeyboardButtonDown(KeyboardButton button) {
  return Core::instance().window_.input_.isKeyboardButtonDown(button);
}
const bool IsKeyboardButtonUp(KeyboardButton button) {
  return Core::instance().window_.input_.isKeyboardButtonUp(button);
}
const bool IsKeyboardButtonPressed(KeyboardButton button) {
  return Core::instance().window_.input_.isKeyboardButtonPressed(button);
}

}; /* Input */
}; /* W2D */
