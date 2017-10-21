/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_SPRITE_H__
#define __WOLFY2D_SPRITE_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

/// Sprite class.
class Sprite {

 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  /// Default class constructor.
  Sprite();
  /// Default class destructor.
  ~Sprite();
  /// Assignment operator.
  Sprite& operator=(const Sprite& other);
  /// Default copy constructor.
  Sprite(const Sprite& other);


/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init(const char* image_path);
  ///
  /// @brief Initializes the base texture / sprite class.
  /// @param image_path texture path of the original picture.
  ///--------------------------------------------------------------------------
  void init(const char* image_path);

  ///--------------------------------------------------------------------------
  /// @fn   render();
  ///
  /// @brief Renderizes the base sprite.
  ///--------------------------------------------------------------------------
  void render();

/*******************************************************************************
***                              Public Setters                              ***
*******************************************************************************/

  

  ///--------------------------------------------------------------------------
  /// @fn   set_position(const Vec2 position);
  ///
  /// @brief Position setter.
  /// @param position Position to set.
  ///--------------------------------------------------------------------------
  void set_position(const Vec2 position);
  ///--------------------------------------------------------------------------
  /// @fn   set_rotation(const float rotation);
  ///
  /// @brief Rotation setter.
  /// @param rotation Radians to set.
  ///--------------------------------------------------------------------------
  void set_rotation(const float rotation);
  ///--------------------------------------------------------------------------
  /// @fn   set_size(const Vec2 size);
  ///
  /// @brief Sprite Size setter.
  /// @param size Size to set.
  ///--------------------------------------------------------------------------
  void set_size(const Vec2 size);

  
/*******************************************************************************
***                              Public Getters                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 size();
  ///
  /// @brief Sprite size getter.
  /// @return size of the sprite.
  ///--------------------------------------------------------------------------
  const Vec2 size();
  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 originalTextureSize();
  ///
  /// @brief Original texture size getter.
  /// @return size of the original texture.
  ///--------------------------------------------------------------------------
  const Vec2 originalTextureSize();
  ///--------------------------------------------------------------------------
  /// @fn   const float color();
  ///
  /// @brief Sprite rotation getter.
  /// @return rotation of the sprite in radians.
  ///--------------------------------------------------------------------------
  const float rotation();
  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 position();
  ///
  /// @brief Text position getter.
  /// @return position of the sprite in the window.
  ///--------------------------------------------------------------------------
  const Vec2 position();
  ///--------------------------------------------------------------------------
  /// @fn   const uint32 textureID();
  ///
  /// @brief Texture id getter.
  /// @return Original texture id in gpu.
  ///--------------------------------------------------------------------------
  const uint32 textureID();

/*******************************************************************************
***                            Private Attributes                            ***
*******************************************************************************/
 private:

   /// Position.
   Vec2 position_;
   /// Size.
   Vec2 size_;
   /// Rotation in radians.
   float rotation_;
   /// Original image size.
   Vec2 texture_size_;
   /// Texture id.
   uint32 texture_id_;
   /// Sets if the texture should be destroyed when the class is destroyed.
   bool release_sprite_when_destroy_;


}; /* SPRITE */
}; /* W2D */

#endif
