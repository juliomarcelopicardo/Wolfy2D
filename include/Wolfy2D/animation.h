/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_ANIMATION_H__
#define __WOLFY2D_ANIMATION_H__ 1

#include "Wolfy2D/globals.h"
#include "Wolfy2D/sprite.h"
#include <vector>

namespace W2D {

/// Animation class.
class Animation {

public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  /// Default class constructor.
  Animation();
  /// Default class destructor.
  ~Animation();
  /// Assignment operator.
  Animation& operator=(const Animation& other);
  /// Default copy constructor.
  Animation(const Animation& other);


/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init(Sprite* sprite_list, const uint32 number_of_sprites);
  ///
  /// @brief Initializes the class using several sprites.
  /// @param image_path texture path of the original picture.
  ///--------------------------------------------------------------------------
  void init(Sprite* sprite_list, const uint32 number_of_sprites);
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
  /// @brief Animation Size setter.
  /// @param size Size to set.
  ///--------------------------------------------------------------------------
  void set_size(const Vec2 size);
  ///--------------------------------------------------------------------------
  /// @fn   set_speed(const uint64 milliseconds_per_change);
  ///
  /// @brief Animation speed, time between each sprite transition setter.
  /// @param milliseconds_per_change Time between sprites.
  ///--------------------------------------------------------------------------
  void set_speed(const uint64 milliseconds_per_change);

/*******************************************************************************
***                              Public Getters                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 size();
  ///
  /// @brief Animation size getter.
  /// @return size of the sprite.
  ///--------------------------------------------------------------------------
  const Vec2 size();
  ///--------------------------------------------------------------------------
  /// @fn   const float color();
  ///
  /// @brief Animation rotation getter.
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
  /// chronometer.
  uint64 timer_;
  /// Milliseconds to next transition.
  uint64 milliseconds_per_change_;
  /// sprite texture id list.
  std::vector<uint32> texture_id_;
  /// Sprite id list length.
  uint32 texture_id_list_length_;
  /// Current sprite index in the list.
  uint32 index_;
  /// True if initialized.
  bool initialized_;

}; /* Animation */
}; /* W2D */

#endif
