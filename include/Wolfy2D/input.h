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

/// Mouse buttons enum.
enum MouseButton {
  kMouseButton_Left = 0,
  kMouseButton_Right = 1,
  kMouseButton_Middle = 2,
};
/// Keyboard buttons enum.
enum KeyboardButton {
  kKeyboardButton_W = 87,
  kKeyboardButton_A = 65,
  kKeyboardButton_S = 83,
  kKeyboardButton_D = 68,
  kKeyboardButton_Q = 81,
  kKeyboardButton_E = 69,
  kKeyboardButton_Tab = 258,
};

///--------------------------------------------------------------------------
/// @fn   glm::vec2 MousePosition();
///
/// @brief Mouse cursor position getter.
/// @return Position.
///--------------------------------------------------------------------------
glm::vec2 MousePosition();
///--------------------------------------------------------------------------
/// @fn   bool IsMouseButtonDown(MouseButton button);
///
/// @brief Mouse button down info.
/// @param button Mouse button to check
/// @return true if the button is down.
///--------------------------------------------------------------------------
bool IsMouseButtonDown(MouseButton button);
///--------------------------------------------------------------------------
/// @fn   bool IsMouseButtonUp(MouseButton button);
///
/// @brief Mouse button up info.
/// @param button Mouse button to check
/// @return true if the button is up.
///--------------------------------------------------------------------------
bool IsMouseButtonUp(MouseButton button);
///--------------------------------------------------------------------------
/// @fn   bool IsMouseButtonPressed(MouseButton button);
///
/// @brief Mouse button pressed info.
/// @param button Mouse button to check
/// @return true if the button is pressed.
///--------------------------------------------------------------------------
bool IsMouseButtonPressed(MouseButton button);
///--------------------------------------------------------------------------
/// @fn   bool IsKeyboardButtonDown(KeyboardButton button);
///
/// @brief Keyboard button down info.
/// @param button Keyboard button to check
/// @return true if the button is down.
///--------------------------------------------------------------------------
bool IsKeyboardButtonDown(KeyboardButton button);
///--------------------------------------------------------------------------
/// @fn   bool IsKeyboardButtonUp(KeyboardButton button);
///
/// @brief Keyboard button up info.
/// @param button Keyboard button to check
/// @return true if the button is up.
///--------------------------------------------------------------------------
bool IsKeyboardButtonUp(KeyboardButton button);
///--------------------------------------------------------------------------
/// @fn   bool IsKeyboardButtonPressed(KeyboardButton button);
///
/// @brief Keyboard button pressed info.
/// @param button Mouse button to check
/// @return true if the button is pressed.
///--------------------------------------------------------------------------
bool IsKeyboardButtonPressed(KeyboardButton button);

}; /* Input */
}; /* W2D */

#endif
