/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/draw.h"
#include "GL/glew.h"
#include "core/wnd.h"
#include "core/core.h"

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

void Rect(const Vec2 center, 
          const Vec2 size, 
          const Vec4 color, 
          const float32 line_width) {
  
  glLineWidth(line_width);
  glColor4f(color.x, color.y, color.z, color.w);
  auto& wnd = Core::instance().window_;
  const Vec2 half_size = { size.x / (float32)wnd.width_, size.y / (float32)wnd.height_ };

  glBegin(GL_LINES);
  glVertex2f(center.x - half_size.x, center.y + half_size.y);
  glVertex2f(center.x - half_size.x, center.y - half_size.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(center.x - half_size.x, center.y - half_size.y);
  glVertex2f(center.x + half_size.x, center.y - half_size.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(center.x + half_size.x, center.y - half_size.y);
  glVertex2f(center.x + half_size.x, center.y + half_size.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(center.x + half_size.x, center.y + half_size.y);
  glVertex2f(center.x - half_size.x, center.y + half_size.y);
  glEnd();
}

void Path(const Vec2* points, 
          const uint32 num_points, 
          const Vec4 color, 
          const float32 line_width) {
  if (num_points < 3 || !points) {
    printf("\n ERROR: More than 2 points needed to draw a path.");
  }
  else {
    glLineWidth(line_width);
    glColor4f(color.x, color.y, color.z, color.w);
    Vec2 point = { 0.0f, 0.0f };
    Line(points[0], points[num_points - 1], color, line_width);
    for (uint32 i = 1; i < num_points; ++i) {
      Line(points[i-1], points[i], color, line_width);
    }
  }
}

}; /* Draw */
}; /* W2D */
