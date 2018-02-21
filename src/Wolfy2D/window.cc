/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "core/wnd.h"
#include "core/core.h"

namespace W2D {
namespace Window {

void Init(const int32 width, const int32 height, const char* display_name) {
  Core::instance().window_.init(width, height, display_name);
}

void InitMaximized(const char * display_name, const bool full_screen_mode) {
  Core::instance().window_.initMaximized(display_name, full_screen_mode);
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
