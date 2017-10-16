/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "core/input.h"
#include "core/core.h"
#include "core/window.h"

namespace W2D {




#pragma region INPUT

/*******************************************************************************
********************************************************************************
***                                                                          ***
***                           WOLFY2D INPUT CLASS                            ***
***                                                                          ***
********************************************************************************
*******************************************************************************/


/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

CoreInput::CoreInput() {
  mouse_wheel_ = 0.0f;
}

CoreInput::~CoreInput() {}


/*******************************************************************************
***                               Public methods                             ***
*******************************************************************************/

ButtonStatus * CoreInput::getButton(const int32 glfw_key_id) {

  switch (glfw_key_id) {
    case W2D::Input::kKeyboardButton_W: return &keyboard_W_button_; break;
    case W2D::Input::kKeyboardButton_A: return &keyboard_A_button_; break;
    case W2D::Input::kKeyboardButton_S: return &keyboard_S_button_; break;
    case W2D::Input::kKeyboardButton_D: return &keyboard_D_button_; break;
    case W2D::Input::kKeyboardButton_Q: return &keyboard_Q_button_; break;
    case W2D::Input::kKeyboardButton_E: return &keyboard_E_button_; break;
    case W2D::Input::kKeyboardButton_Tab: return &keyboard_Tab_button_; break;
  }
  return nullptr;
}

void CoreInput::resetInputButtonsStatus() {
  mouse_button_[Input::kMouseButton_Left].resetStatus();
  mouse_button_[Input::kMouseButton_Right].resetStatus();
  mouse_button_[Input::kMouseButton_Middle].resetStatus();
  keyboard_A_button_.resetStatus();
  keyboard_W_button_.resetStatus();
  keyboard_S_button_.resetStatus();
  keyboard_D_button_.resetStatus();
  keyboard_Q_button_.resetStatus();
  keyboard_E_button_.resetStatus();
  keyboard_Tab_button_.resetStatus();
}



void CoreInput::refreshButtonsUp() {
  mouse_button_[Input::kMouseButton_Left].is_up = false;
  mouse_button_[Input::kMouseButton_Right].is_up = false;
  mouse_button_[Input::kMouseButton_Middle].is_up = false;
  keyboard_A_button_.is_up = false;
  keyboard_W_button_.is_up = false;
  keyboard_S_button_.is_up = false;
  keyboard_D_button_.is_up = false;
  keyboard_Q_button_.is_up = false;
  keyboard_E_button_.is_up = false;
  keyboard_Tab_button_.is_up = false;
}

bool CoreInput::isMouseButtonDown(Input::MouseButton button) {
  if (mouse_button_[button].is_down) {
    mouse_button_[button].is_down = false;
    return true;
  }
  return false;
}

bool CoreInput::isMouseButtonUp(Input::MouseButton button) {
  return mouse_button_[button].is_up;
}

bool CoreInput::isMouseButtonPressed(Input::MouseButton button) {
  return mouse_button_[button].is_pressed;
}

bool CoreInput::isKeyboardButtonDown(Input::KeyboardButton button) {
  switch (button) {
  case Input::kKeyboardButton_W:
    if (keyboard_W_button_.is_down) {
      keyboard_W_button_.is_down = false;
      return true;
    }
    break;
  case Input::kKeyboardButton_A:
    if (keyboard_A_button_.is_down) {
      keyboard_A_button_.is_down = false;
      return true;
    }
    break;
  case Input::kKeyboardButton_S:
    if (keyboard_S_button_.is_down) {
      keyboard_S_button_.is_down = false;
      return true;
    }
    break;
  case Input::kKeyboardButton_D:
    if (keyboard_D_button_.is_down) {
      keyboard_D_button_.is_down = false;
      return true;
    }
    break;
  case Input::kKeyboardButton_E:
    if (keyboard_E_button_.is_down) {
      keyboard_E_button_.is_down = false;
      return true;
    }
    break;
  case Input::kKeyboardButton_Q:
    if (keyboard_Q_button_.is_down) {
      keyboard_Q_button_.is_down = false;
      return true;
    }
    break;
  case Input::kKeyboardButton_Tab:
    if (keyboard_Tab_button_.is_down) {
      keyboard_Tab_button_.is_down = false;
      return true;
    }
    break;
  }
  return false;
}

bool CoreInput::isKeyboardButtonUp(Input::KeyboardButton button) {
  switch (button) {
  case Input::kKeyboardButton_W: return keyboard_W_button_.is_up; break;
  case Input::kKeyboardButton_A: return keyboard_A_button_.is_up; break;
  case Input::kKeyboardButton_S: return keyboard_S_button_.is_up; break;
  case Input::kKeyboardButton_D: return keyboard_D_button_.is_up; break;
  case Input::kKeyboardButton_Q: return keyboard_Q_button_.is_up; break;
  case Input::kKeyboardButton_E: return keyboard_E_button_.is_up; break;
  case Input::kKeyboardButton_Tab: return keyboard_Tab_button_.is_up; break;
  }
  return false;
}

bool CoreInput::isKeyboardButtonPressed(Input::KeyboardButton button) {
  switch (button) {
  case Input::kKeyboardButton_W: return keyboard_W_button_.is_pressed; break;
  case Input::kKeyboardButton_A: return keyboard_A_button_.is_pressed; break;
  case Input::kKeyboardButton_S: return keyboard_S_button_.is_pressed; break;
  case Input::kKeyboardButton_D: return keyboard_D_button_.is_pressed; break;
  case Input::kKeyboardButton_Q: return keyboard_Q_button_.is_pressed; break;
  case Input::kKeyboardButton_E: return keyboard_E_button_.is_pressed; break;
  case Input::kKeyboardButton_Tab: return keyboard_Tab_button_.is_pressed; break;
  }
  return false;
}

void CoreInput::checkCursorPosition() {

  if (mouse_position_.x < 0.0) {
    mouse_position_.x = 0.0;
  }
  if (mouse_position_.x < 0.0) {
    mouse_position_.x = 0.0;
  }

  auto& window = Core::instance().window_;
  if (mouse_position_.x > window.width_) {
    mouse_position_.x = window.width_;
  }
  if (mouse_position_.x > window.height_) {
    mouse_position_.x = window.height_;
  }
}

#pragma endregion
  
}; /* W2D */