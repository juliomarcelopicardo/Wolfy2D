/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_SPRITE_H__
#define __CORE_SPRITE_H__ 1

#include "GLM/glm.hpp"
#include "Wolfy2D/globals.h"


namespace W2D {

/// Sprite / sprite base class.
class Sprite {
public:

/// It only affects to the position.
  enum PivotPoint {
    kPivotPoint_Center = 0,
    kPivotPoint_UpLeft,
    kPivotPoint_Up,
    kPivotPoint_UpRight,
    kPivotPoint_Right,
    kPivotPoint_Downight,
    kPivotPoint_Down,
    kPivotPoint_DownLeft,
    kPivotPoint_Left,
  };

  /*******************************************************************************
  ***                        Constructor and destructor                        ***
  *******************************************************************************/

  /// Default class constructor.
  Sprite();
  /// Default class destructor.
  ~Sprite();
  /// Default copy constructor.
  Sprite(const Sprite& copy);
  /// Assignment operator.
  Sprite& operator=(const Sprite& copy);

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


  /*******************************************************************************
  ***                         Sprite Setters & Getters                         ***
  *******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   set_position(const glm::vec2 position);
  ///
  /// @brief Position setter.
  /// @param position Position to set.
  ///--------------------------------------------------------------------------
  void set_position(const glm::vec2 position);
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
  /// @fn   set_texture_id(const uint32 texture_id);
  ///
  /// @brief Sprite id setter.
  /// @param texture_id Sprite gpu handler or id.
  ///--------------------------------------------------------------------------
  void set_texture_id(const uint32 texture_id);
  ///--------------------------------------------------------------------------
  /// @fn   set_pivot(const PivotPoint pivot);
  ///
  /// @brief Pivot setter.
  /// @param pivot Pivot or origin of the sprite.
  ///--------------------------------------------------------------------------
  void set_pivot(const PivotPoint pivot);

  ///--------------------------------------------------------------------------
  /// @fn   glm::vec2 position() const;
  ///
  /// @brief Position getter.
  /// @return the position.
  ///--------------------------------------------------------------------------
  glm::vec2 position() const;
  ///--------------------------------------------------------------------------
  /// @fn   glm::vec2 size() const;
  ///
  /// @brief Size getter.
  /// @return the size.
  ///--------------------------------------------------------------------------
  glm::vec2 size() const;
  ///--------------------------------------------------------------------------
  /// @fn   float rotation() const;
  ///
  /// @brief Rotation getter )in radians).
  /// @return the rotation in radians.
  ///--------------------------------------------------------------------------
  float rotation() const;
  ///--------------------------------------------------------------------------
  /// @fn   uint32 textureID() const;
  ///
  /// @brief Sprite id getter.
  /// @return the id or handler of the texture in the gpu.
  ///--------------------------------------------------------------------------
  uint32 textureID() const;
  ///--------------------------------------------------------------------------
  /// @fn   PivotPoint pivot() const;
  ///
  /// @brief Pivot id getter.
  /// @return the pivot or origin of the texture in the gpu.
  ///--------------------------------------------------------------------------
  PivotPoint pivot() const;
  ///--------------------------------------------------------------------------
  /// @fn   glm::mat4 model_matrix() const;
  ///
  /// @brief Model matrix id getter.
  /// @return the model_matrix with the transform of the sprite
  ///--------------------------------------------------------------------------
  glm::mat4 model_matrix() const;


  /*******************************************************************************
  ***                          	Public attributes                              ***
  *******************************************************************************/


private:

  /*******************************************************************************
  ***                          	Private attributes                             ***
  *******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   updateModelMatrix();
  ///
  /// @brief Renderizes the base sprite.
  ///--------------------------------------------------------------------------
  void updateModelMatrix();

  /*******************************************************************************
  ***                          	Private attributes                             ***
  *******************************************************************************/

  /// Sprite position.
  glm::vec2 position_;
  /// Sprite size
  glm::vec2 size_;
  /// Sprite rotation in radians.
  float rotation_;
  /// Sprite_id or handler.
  uint32 texture_id_;
  /// Sets the pivot or local origin of the texture.
  PivotPoint pivot_;
  /// Model matrix
  glm::mat4 model_matrix_;



};/* Sprite class */

}; /* W2D */

#endif