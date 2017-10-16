/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

 
#include <string>
#include "Wolfy2D.h"

namespace W2D {
int32 main() {
  
  Window::Init(1024, 978);

  while (Window::IsOpened()) {
    Window::Clear();
    if (Input::IsKeyboardButtonDown(Input::kKeyboardButton_W)) {      printf("\n W down");    }    if (Input::IsKeyboardButtonPressed(Input::kKeyboardButton_S)) {      printf("\n S pressed");    }    if (Input::IsKeyboardButtonUp(Input::kKeyboardButton_D)) {      printf("\n D up");    }    if (Input::IsMouseButtonDown(Input::kMouseButton_Left)) {      printf("\n Left down");    }    if (Input::IsMouseButtonPressed(Input::kMouseButton_Middle)) {      printf("\n Middle pressed");    }    if (Input::IsMouseButtonUp(Input::kMouseButton_Right)) {      printf("\n Right up");    }    
    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
