/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "core/input_manager.h"
#include "core/core.h"

namespace W2D {
namespace Input {


/*******************************************************************************
***                             Input getters                                ***
*******************************************************************************/
glm::vec2 MousePosition() {
  return Core::instance().window_.input_.mouse_position_;
}

bool IsMouseButtonDown(MouseButton button) {
  return Core::instance().window_.input_.isMouseButtonDown(button);
}
bool IsMouseButtonUp(MouseButton button) {
  return Core::instance().window_.input_.isMouseButtonUp(button);
}
bool IsMouseButtonPressed(MouseButton button) {
  return Core::instance().window_.input_.isMouseButtonPressed(button);
}

bool IsKeyboardButtonDown(KeyboardButton button) {
  return Core::instance().window_.input_.isKeyboardButtonDown(button);
}
bool IsKeyboardButtonUp(KeyboardButton button) {
  return Core::instance().window_.input_.isKeyboardButtonUp(button);
}
bool IsKeyboardButtonPressed(KeyboardButton button) {
  return Core::instance().window_.input_.isKeyboardButtonPressed(button);
}

}; /* Input */
}; /* W2D */
