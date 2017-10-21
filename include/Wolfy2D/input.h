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
/// @fn   const Vec2 MousePosition();
///
/// @brief Mouse cursor position getter.
/// @return Mouse cursor Position.
///--------------------------------------------------------------------------
const Vec2 MousePosition();
///--------------------------------------------------------------------------
/// @fn   const bool IsMouseButtonDown(MouseButton button);
///
/// @brief Mouse button down info.
/// @param button Mouse button to check
/// @return true if the button is down.
///--------------------------------------------------------------------------
const bool IsMouseButtonDown(MouseButton button);
///--------------------------------------------------------------------------
/// @fn   const bool IsMouseButtonUp(MouseButton button);
///
/// @brief Mouse button up info.
/// @param button Mouse button to check
/// @return true if the button is up.
///--------------------------------------------------------------------------
const bool IsMouseButtonUp(MouseButton button);
///--------------------------------------------------------------------------
/// @fn   const bool IsMouseButtonPressed(MouseButton button);
///
/// @brief Mouse button pressed info.
/// @param button Mouse button to check
/// @return true if the button is pressed.
///--------------------------------------------------------------------------
const bool IsMouseButtonPressed(MouseButton button);
///--------------------------------------------------------------------------
/// @fn   const bool IsKeyboardButtonDown(KeyboardButton button);
///
/// @brief Keyboard button down info.
/// @param button Keyboard button to check
/// @return true if the button is down.
///--------------------------------------------------------------------------
const bool IsKeyboardButtonDown(KeyboardButton button);
///--------------------------------------------------------------------------
/// @fn   const bool IsKeyboardButtonUp(KeyboardButton button);
///
/// @brief Keyboard button up info.
/// @param button Keyboard button to check
/// @return true if the button is up.
///--------------------------------------------------------------------------
const bool IsKeyboardButtonUp(KeyboardButton button);
///--------------------------------------------------------------------------
/// @fn   const bool IsKeyboardButtonPressed(KeyboardButton button);
///
/// @brief Keyboard button pressed info.
/// @param button Mouse button to check
/// @return true if the button is pressed.
///--------------------------------------------------------------------------
const bool IsKeyboardButtonPressed(KeyboardButton button);

}; /* Input */
}; /* W2D */

#endif
