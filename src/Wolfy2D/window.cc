/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "core/window.h"
#include "core/core.h"

namespace W2D {
namespace Window {

void Init(const int32 width,
          const int32 height,
          const bool mouse_cursor_visible,
          const char* display_name) {

  Core::instance().window_.init(width, height, display_name);
}

void Close() {
  Core::instance().window_.close();
}

void Clear(float red, float green, float blue) {
  Core::instance().window_.clear(red, green, blue);
}

void Frame() {
  Core::instance().window_.frame();
}

int32 Height() {
  return Core::instance().window_.height_;
}

int32 Width() {
  return Core::instance().window_.width_;
}

bool IsOpened() {
  return Core::instance().window_.is_opened_;
}

}; /* Window */
}; /* W2D */