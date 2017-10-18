/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_TEXTURE_H__
#define __CORE_TEXTURE_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

class CoreTexture {

 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  CoreTexture();
  ~CoreTexture();

/*******************************************************************************
***                             Texture methods                              ***
*******************************************************************************/
  
//Font textures for texts need to be "clamped to the edge", but normal 
  //textures should be normally repeated.
  void init(const char* path);
  

  
/*******************************************************************************
***                        Texture Setters & Getters                         ***
*******************************************************************************/


/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/

  uint32 texture_id_;
  int32 width_;
  int32 height_;

 protected:
  void set_info();
  CoreTexture(const CoreTexture& copy);
  CoreTexture& operator=(const CoreTexture& copy);

}; /* Texture Class */

};/* W2D */

#endif