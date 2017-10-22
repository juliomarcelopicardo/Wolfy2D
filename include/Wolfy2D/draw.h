/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_DRAW_H__
#define __WOLFY2D_DRAW_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {
namespace Draw {

///--------------------------------------------------------------------------
/// @fn   Line(const Vec2 origin, const Vec2 destiny,
///            const Vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f },
///            const float32 line_width = 2.0f);
///
/// @brief  Draws a line in the screen.
/// @param  origin Line origin position.
/// @param  destiny Line destiny position.
/// @param  color Line color.
/// @param  line_width Line width.
///--------------------------------------------------------------------------
void Line(const Vec2 origin, const Vec2 destiny,
          const Vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f },
          const float32 line_width = 2.0f);

///--------------------------------------------------------------------------
/// @fn   Rect(const Vec2 center_position, const Vec2 size,
///            const Vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f },
///            const float32 line_width = 2.0f);
///
/// @brief  Draws a rectangle in the screen.
/// @param  center_position Position where the center of the polygon will be.
/// @param  size Width and height of the rectangle.
/// @param  color Line color.
/// @param  line_width Line width.
///--------------------------------------------------------------------------
void Rect(const Vec2 center_position, const Vec2 size, 
          const Vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f },
          const float32 line_width = 2.0f);



}; /* Draw */
}; /* W2D */

#endif
