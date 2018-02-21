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

/*
 * This functions is because coordinates in opengl goes from... 
 * (0,0) is the center. 1 and -1 de borders
 */
Vec2 ConvertToLocalScreenCoordinates(const Vec2 value) {
  auto& wnd = Core::instance().window_;
  return{ ((value.x * 2.0f) / wnd.width_) - 1.0f, ((value.y * 2.0f) / wnd.height_) - 1.0f };
}

void Line(const Vec2 origin, 
          const Vec2 destiny, 
          const Vec4 color, 
          const float32 line_width) {

  const Vec2 start = ConvertToLocalScreenCoordinates(origin);
  const Vec2 end = ConvertToLocalScreenCoordinates(destiny);
  glLineWidth(line_width);
  glColor4f(color.x, color.y, color.z, color.w);
  glBegin(GL_LINES);
  glVertex2f(start.x, start.y);
  glVertex2f(end.x, end.y);
  glEnd();
}

void Rect(const Vec2 center_position, 
          const Vec2 size, 
          const Vec4 color, 
          const float32 line_width) {
  
  glLineWidth(line_width);
  glColor4f(color.x, color.y, color.z, color.w);
  auto& wnd = Core::instance().window_;
  const Vec2 half_size = { size.x / (float32)wnd.width_, size.y / (float32)wnd.height_ };
  const Vec2 center = ConvertToLocalScreenCoordinates(center_position);
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
