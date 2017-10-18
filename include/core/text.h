/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/



#ifndef __CORE_TEXT_H__
#define __CORE_TEXT_H__ 1



#include "Wolfy2D/globals.h"

namespace W2D {

/**************************************************************************
***                             TEXT CLASS                              ***
**************************************************************************/
class CoreText {

 public:


  CoreText();
  ~CoreText();

  void init(const char* font_name);
  void set_position(const glm::vec2 position);
  void set_size(const float size);
  void set_color(const glm::vec4 color);
  void render(const char* text);
  
 private:

  int32 regular_;
  struct FONScontext* font_;
  glm::vec2 position_;
  glm::vec4 color_; 
  float size_;

  void release_font();
  CoreText(const CoreText& copy);
  CoreText& operator=(const CoreText& copy);

}; /* Text class */

}; /* W2D */

#endif