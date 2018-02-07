/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "Wolfy2D.h"
#include "jmp\jmp.h"

namespace W2D {

int32 main() {

  JMP::Machine jmp;
  jmp.processFile("../scripts/config.jmp");

  Window::Init(jmp.getInteger("width", "Window"), jmp.getInteger("height", "Window"));
  
  while (Window::IsOpened()) {
    Window::Clear();
    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
