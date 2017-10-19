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

///--------------------------------------------------------------------------
/// @fn   init(const int32 width, const int32 height, const char* name);
///
/// @brief  Initializes the window with the specified width, height and window name.
/// @param  width width of the window.
/// @param  height height of the window.
/// @param  name name of the window.
///--------------------------------------------------------------------------
void Init(const int32 width = 800,
          const int32 height = 600,
          const char* display_name = "Wolfy2D Window");

///--------------------------------------------------------------------------
/// @fn   bool IsOpened();
///
/// @brief  Opened status getter.
/// @return true if the window is still opened.
///--------------------------------------------------------------------------
bool IsOpened();
///--------------------------------------------------------------------------
/// @fn   clear(float red, float green, float blue);
///
/// @brief  Clears the window with the specified color.
/// @param  red Red color component.
/// @param  green Green color component.
/// @param  blue Blue color component.
///--------------------------------------------------------------------------
void Clear(float red = 0.3f, float green = 0.3f, float blue = 0.1f);
///--------------------------------------------------------------------------
/// @fn   close();
///
/// @brief  Deallocates all the elements related to window such as imgui.
///--------------------------------------------------------------------------
void Close();
///--------------------------------------------------------------------------
/// @fn   frame();
///
/// @brief  Ends a frame rendering.
///--------------------------------------------------------------------------
void Frame();

///--------------------------------------------------------------------------
/// @fn   int32 Height();
///
/// @brief  Window height getter.
/// @return Window height.
///--------------------------------------------------------------------------
int32 Height();
///--------------------------------------------------------------------------
/// @fn   int32 Width();
///
/// @brief  Window width getter.
/// @return Window width.
///--------------------------------------------------------------------------
int32 Width();

}; /* Window */
}; /* W2D */

#endif
