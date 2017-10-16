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

    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
