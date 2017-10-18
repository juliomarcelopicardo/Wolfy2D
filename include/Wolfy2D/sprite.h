/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_SPRITE_H__
#define __WOLFY2D_SPRITE_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

class Sprite {

 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  Sprite();
  ~Sprite();
  Sprite& operator=(const Sprite& other);
  Sprite(const Sprite& other);

/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/
  void init(const char* image_path);
  void set_position(const glm::vec2 position);
  void set_size(const glm::vec2 size);
  void set_rotation(const float radians);
  void render();
  
 private:

   glm::vec2 position_;
   glm::vec2 size_;
   float rotation_;
   glm::vec2 texture_size_;
   uint32 texture_id_;
   bool release_sprite_when_destroy_;
};



}; /* W2D */

#endif
