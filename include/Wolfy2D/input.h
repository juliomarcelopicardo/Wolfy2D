/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_INPUT_H__
#define __WOLFY2D_INPUT_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {
namespace Input {

enum MouseButton {
  kMouseButton_Left = 0,
  kMouseButton_Right = 1,
  kMouseButton_Middle = 2,
};
enum KeyboardButton {
  kKeyboardButton_W = 87,
  kKeyboardButton_A = 65,
  kKeyboardButton_S = 83,
  kKeyboardButton_D = 68,
  kKeyboardButton_Q = 81,
  kKeyboardButton_E = 69,
  kKeyboardButton_Tab = 258,
};

glm::vec2 MousePosition();
bool IsMouseButtonDown(MouseButton button);
bool IsMouseButtonUp(MouseButton button);
bool IsMouseButtonPressed(MouseButton button);
bool IsKeyboardButtonDown(KeyboardButton button);
bool IsKeyboardButtonUp(KeyboardButton button);
bool IsKeyboardButtonPressed(KeyboardButton button);

}; /* Input */
}; /* W2D */

#endif
