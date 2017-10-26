/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_SPRITE_H__
#define __CORE_SPRITE_H__ 1

#include "GLM/glm.hpp"
#include "Wolfy2D/globals.h"
#include "Wolfy2D/sprite.h"


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
  /// @fn   render();
  ///
  /// @brief Renderizes the base sprite.
  ///--------------------------------------------------------------------------
  void render();
  ///--------------------------------------------------------------------------
  /// @fn   calculateProjectionMatrix();
  ///
  /// @brief Calculates the camera projection matrix.
  ///--------------------------------------------------------------------------
  void calculateProjectionMatrix();
  ///--------------------------------------------------------------------------
  /// @fn   releaseTexture();
  ///
  /// @brief Releases the texture from the gpu memory.
  ///--------------------------------------------------------------------------
  void releaseTexture();

/*******************************************************************************
***                         Sprite Setters & Getters                         ***
*******************************************************************************/
  
  ///--------------------------------------------------------------------------
  /// @fn   set_position(const glm::vec2 position);
  ///
  /// @brief Position setter.
  /// @param position Position to set.
  ///--------------------------------------------------------------------------
  void set_position(const glm::vec2 pos);
  ///--------------------------------------------------------------------------
  /// @fn   set_rotation(const float rotation);
  ///
  /// @brief Rotation setter.
  /// @param rotation Radians to set.
  ///--------------------------------------------------------------------------
  void set_rotation(const float rotation);
  ///--------------------------------------------------------------------------
  /// @fn   set_size(const glm::vec2 size);
  ///
  /// @brief Sprite Size setter.
  /// @param size Size to set.
  ///--------------------------------------------------------------------------
  void set_size(const glm::vec2 size);
  ///--------------------------------------------------------------------------
  /// @fn   set_size(const glm::vec2 texture_size);
  ///
  /// @brief Texture Size setter.
  /// @param size Size to set.
  ///--------------------------------------------------------------------------
  void set_texture_size(const glm::vec2 texture_size);
  ///--------------------------------------------------------------------------
  /// @fn   set_texture_id(const uint32 texture_id);
  ///
  /// @brief Texture id setter.
  /// @param texture_id Texture gpu handler or id.
  ///--------------------------------------------------------------------------
  void set_texture_id(const uint32 texture_id);
  ///--------------------------------------------------------------------------
  /// @fn   set_pivot(const SpritePivotPoint pivot);
  ///
  /// @brief Pivot setter.
  /// @param pivot Pivot or origin of the sprite.
  ///--------------------------------------------------------------------------
  void set_pivot(const SpritePivotPoint pivot);

  ///--------------------------------------------------------------------------
  /// @fn   const glm::vec2 position();
  ///
  /// @brief Position getter.
  /// @return the position.
  ///--------------------------------------------------------------------------
  const glm::vec2 position();
  ///--------------------------------------------------------------------------
  /// @fn   const glm::vec2 size();
  ///
  /// @brief Size getter.
  /// @return the size.
  ///--------------------------------------------------------------------------
  const glm::vec2 size();
  ///--------------------------------------------------------------------------
  /// @fn   const glm::vec2 textureSize();
  ///
  /// @brief Texture size getter.
  /// @return the size of the texture.
  ///--------------------------------------------------------------------------
  const glm::vec2 textureSize();
  ///--------------------------------------------------------------------------
  /// @fn   const float rotation();
  ///
  /// @brief Rotation getter )in radians).
  /// @return the rotation in radians.
  ///--------------------------------------------------------------------------
  const float rotation();
  ///--------------------------------------------------------------------------
  /// @fn   const uint32 textureID();
  ///
  /// @brief Texture id getter.
  /// @return the id or handler of the texture in the gpu.
  ///--------------------------------------------------------------------------
  const uint32 textureID();
  ///--------------------------------------------------------------------------
  /// @fn   const SpritePivotPoint pivot();
  ///
  /// @brief Pivot id getter.
  /// @return the pivot or origin of the texture in the gpu.
  ///--------------------------------------------------------------------------
  const SpritePivotPoint pivot();
  

/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/


/*******************************************************************************
***                          	Private attributes                             ***
*******************************************************************************/
 private:

  /// Sprite position.
  glm::vec2 position_;
  /// Sprite size
  glm::vec2 size_;
  /// Sprite scale.
  glm::vec2 scale_;
  /// Sprite rotation in radians.
  float rotation_;
  /// Original texture size.
  glm::vec2 texture_size_;
  /// Texture_id or handler.
  uint32 texture_id_;
  /// Camera ortographic projection matrix.
  glm::mat4 projection_matrix_;
  /// Sets the pivot or local origin of the texture.
  SpritePivotPoint pivot_;
  
  /// Default copy constructor.
  Texture(const Texture& copy);
  /// Assignment operator.
  Texture& operator=(const Texture& copy);
  

};/* Texture class */

}; /* W2D */

#endif