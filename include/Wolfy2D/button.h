/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_BUTTON_H__
#define __WOLFY2D_BUTTON_H__ 1

#include "Wolfy2D/globals.h"
#include "Wolfy2D/sprite.h"

namespace W2D {

/// Button class.
class Button {

 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  /// Default class constructor.
  Button();
  /// Default class destructor.
  ~Button();
  /// Assignment operator.
  Button& operator=(const Button& other);
  /// Default copy constructor.
  Button(const Button& other);

/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init(Sprite& normal,
  ///            Sprite& hover,
  ///            Sprite& pressed,
  ///            Sprite& disabled);
  ///
  /// @brief Initializes the button class, with all the pictures.
  /// @param image_path texture path of the original picture.
  ///--------------------------------------------------------------------------
  void init(Sprite& normal, Sprite& hover, Sprite& pressed, Sprite& disabled);
  ///--------------------------------------------------------------------------
  /// @fn   disable();
  ///
  /// @brief Disables the button.
  ///--------------------------------------------------------------------------
  void disable();
  ///--------------------------------------------------------------------------
  /// @fn   disable();
  ///
  /// @brief Disables the button.
  ///--------------------------------------------------------------------------
  void enable();
  ///--------------------------------------------------------------------------
  /// @fn   render();
  ///
  /// @brief Renderizes the base button.
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
  /// @fn   set_size(const Vec2 size);
  ///
  /// @brief Button Size setter.
  /// @param size Size to set.
  ///--------------------------------------------------------------------------
  void set_size(const Vec2 size);

  
/*******************************************************************************
***                              Public Getters                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 size();
  ///
  /// @brief Button size getter.
  /// @return size of the button.
  ///--------------------------------------------------------------------------
  const Vec2 size();
  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 position();
  ///
  /// @brief Text position getter.
  /// @return position of the button in the window.
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
   /// Original image size.
   Vec2 texture_size_;
   /// Normal texture id.
   uint32 normal_texture_id_;
   /// Hover texture id.
   uint32 hover_texture_id_;
   /// Pressed Texture id.
   uint32 pressed_texture_id_;
   /// Disabled texture id.
   uint32 disabled_texture_id_;
   /// True if initialized.
   bool initialized_;
   /// True if active or enabled.
   bool is_enabled_;


}; /* Button */
}; /* W2D */

#endif
