/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/draw.h"
#include "GL/glew.h"

namespace W2D {
namespace Draw {

void Line(const Vec2 origin, 
          const Vec2 destiny, 
          const Vec4 color, 
          const float32 line_width) {

  glLineWidth(line_width);
  glColor4f(color.x, color.y, color.z, color.w);
  glBegin(GL_LINES);
  glVertex2f(origin.x, origin.y);
  glVertex2f(destiny.x, destiny.y);
  glEnd();
}

}; /* Draw */
}; /* W2D */
