/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_WINDOW_H__
#define __WOLFY2D_WINDOW_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {
namespace Window {

void Init(const int32 width = 800,
                const int32 height = 600,
                const bool mouse_cursor_visible = true,
                const char* display_name = "Wolfy2D Window");
bool IsOpened();
void Clear(float red = 0.3f, float green = 0.3f, float blue = 0.6f);
void Close();
void Frame();
int32 Height();
int32 Width();

}; /* Window */
}; /* W2D */

#endif
