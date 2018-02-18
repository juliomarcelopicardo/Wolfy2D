/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_TEXTURE_H__
#define __CORE_TEXTURE_H__ 1

#include "Wolfy2D/globals.h"


namespace W2D {

/// Texture / sprite base class.
class Texture {
 public:


/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

  /// Default class constructor.
  Texture();
  /// Default class destructor.
  ~Texture();
  /// Default copy constructor.
  Texture(const Texture& copy);
  /// Assignment operator.
  Texture& operator=(const Texture& copy);

/*******************************************************************************
***                             Sprite methods                               ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init(const char* texture_path);
  ///
  /// @brief Initializes the base texture / sprite class.
  /// @param texture_path texture path of the original picture.
  ///--------------------------------------------------------------------------
  void init(const char* texture_path);

  ///--------------------------------------------------------------------------
  /// @fn   releaseTexture() const;
  ///
  /// @brief Releases the texture from the gpu memory.
  ///--------------------------------------------------------------------------
  void releaseTexture() const;

  ///--------------------------------------------------------------------------
  /// @fn   set_texture_id(const uint32 texture_id);
  ///
  /// @brief Texture id setter.
  /// @param texture_id Texture gpu handler or id.
  ///--------------------------------------------------------------------------
  void set_texture_id(const uint32 texture_id);

  ///--------------------------------------------------------------------------
  /// @fn   uint32 textureID() const;
  ///
  /// @brief Texture id getter.
  /// @return the id or handler of the texture in the gpu.
  ///--------------------------------------------------------------------------
  uint32 textureID() const;


  

/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/


 private:


/*******************************************************************************
***                          	Private attributes                             ***
*******************************************************************************/

  /// Texture_id or handler.
  uint32 texture_id_;

  
  

};/* Texture class */

}; /* W2D */

#endif