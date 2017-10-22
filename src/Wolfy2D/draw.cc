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

void Rect(const Vec2 center_position, 
          const Vec2 size, 
          const Vec4 color, 
          const float32 line_width) {
  
  glLineWidth(line_width);
  glColor4f(color.x, color.y, color.z, color.w);
  Vec2 half_size = { size.x * 0.5f, size.y * 0.5f };
  glBegin(GL_LINES);
  glVertex2f(center_position.x - half_size.x, center_position.y + half_size.y);
  glVertex2f(center_position.x - half_size.x, center_position.y - half_size.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(center_position.x - half_size.x, center_position.y - half_size.y);
  glVertex2f(center_position.x + half_size.x, center_position.y - half_size.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(center_position.x + half_size.x, center_position.y - half_size.y);
  glVertex2f(center_position.x + half_size.x, center_position.y + half_size.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(center_position.x + half_size.x, center_position.y + half_size.y);
  glVertex2f(center_position.x - half_size.x, center_position.y + half_size.y);
  glEnd();
}

}; /* Draw */
}; /* W2D */
