/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_TEXT_H__
#define __WOLFY2D_TEXT_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

class Text {

 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  Text();
  ~Text();
  Text& operator=(const Text& other);
  Text(const Text& other);

/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/
  void set_position(const glm::vec2 position);
  void set_size(const float size);
  void set_color(const glm::vec4 color_rgba);
  void render(const char* text_to_render);
  
 private:

   float size_;
   glm::vec2 position_;
   glm::vec4 color_;
};



}; /* W2D */

#endif
