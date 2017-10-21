/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_TEXT_H__
#define __WOLFY2D_TEXT_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

/// Class used to render texts in scene.
class Text {

 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  /// Default class constructor.
  Text();
  /// Default class destructor.
  ~Text();
  /// Default asignment operator.
  Text& operator=(const Text& other);
  /// Default copy constructor.
  Text(const Text& other);

/*******************************************************************************
***                        Public Setters & Getters                          ***
*******************************************************************************/
  
  ///--------------------------------------------------------------------------
  /// @fn   set_position(const Vec2 position);
  ///
  /// @brief Text position setter.
  /// @param position Position to set.
  ///--------------------------------------------------------------------------
  void set_position(const Vec2 position);
  ///--------------------------------------------------------------------------
  /// @fn   set_size(const float size);
  ///
  /// @brief Text size setter.
  /// @param size Position to set.
  ///--------------------------------------------------------------------------
  void set_size(const float size);
  ///--------------------------------------------------------------------------
  /// @fn   set_color(const Vec4 color_rgba);
  ///
  /// @brief Text color setter. (0.0f -> black, 1.0f -> White) 
  /// @param color_rgba Color to set.
  ///--------------------------------------------------------------------------
  void set_color(const Vec4 color_rgba);
  ///--------------------------------------------------------------------------
  /// @fn   render(const char* text_to_render);
  ///
  /// @brief Text render function.
  /// @param text_to_render String that will be rendered.
  ///--------------------------------------------------------------------------
  void render(const char* text_to_render);

  ///--------------------------------------------------------------------------
  /// @fn   const float size();
  ///
  /// @brief Text size getter.
  /// @return size of the text font..
  ///--------------------------------------------------------------------------
  const float size();
  ///--------------------------------------------------------------------------
  /// @fn   const Vec4 color();
  ///
  /// @brief Text color getter.
  /// @return color of the text font.
  ///--------------------------------------------------------------------------
  const Vec4 color();
  ///--------------------------------------------------------------------------
  /// @fn   const Vec2 position();
  ///
  /// @brief Text position getter.
  /// @return position of the text in the screen.
  ///--------------------------------------------------------------------------
  const Vec2 position();
  
 private:

   /// Size of the text font.
   float size_;
   /// Position of the text.
   Vec2 position_;
   /// Color of the text font.
   Vec4 color_;
};



}; /* W2D */

#endif
