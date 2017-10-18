/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_SPRITE_H__
#define __CORE_SPRITE_H__ 1

#include "GLM/glm.hpp"
#include "Wolfy2D/globals.h"
#include "texture.h"


namespace W2D {

class CoreSprite {
 public:


/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  CoreSprite();
  ~CoreSprite();

/*******************************************************************************
***                             Sprite methods                               ***
*******************************************************************************/

  void init(const CoreTexture& texture);
  void render();

/*******************************************************************************
***                         Sprite Setters & Getters                         ***
*******************************************************************************/
  
  void set_position(const glm::vec2 pos);
  void set_rotation(const float rotation);
  void set_size(const glm::vec2 size);

  const glm::vec2 position();
  const glm::vec2 size();

/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/


/*******************************************************************************
***                          	Private attributes                             ***
*******************************************************************************/
 private:


  glm::vec2 position_;
  glm::vec2 size_;
  glm::vec2 scale_;
  float rotation_;
  glm::vec2 texture_size_;
  uint32 texture_id_;


  CoreSprite(const CoreSprite& copy);
  CoreSprite& operator=(const CoreSprite& copy);
  

};/* Sprite class */

}; /* W2D */

#endif