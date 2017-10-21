/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/



#ifndef __CORE_TEXT_H__
#define __CORE_TEXT_H__ 1



#include "Wolfy2D/globals.h"
#include "GLM/glm.hpp"

namespace W2D {

/**************************************************************************
***                             TEXT CLASS                              ***
**************************************************************************/

/// Class to manage the base text.
class Txt {

 public:

  /// Default class constructor.
  Txt();
  /// Default class destructor.
  ~Txt();

  ///--------------------------------------------------------------------------
  /// @fn   init(const char* font_name);
  ///
  /// @brief Initializes the text base class.
  /// @param font_path Path of the ttf font file.
  ///--------------------------------------------------------------------------
  void init(const char* font_path);
  ///--------------------------------------------------------------------------
  /// @fn   set_position(const glm::vec2 position);
  ///
  /// @brief Text position setter.
  /// @param position Position to set.
  ///--------------------------------------------------------------------------
  void set_position(const glm::vec2 position);
  ///--------------------------------------------------------------------------
  /// @fn   set_size(const float size);
  ///
  /// @brief Text size setter.
  /// @param size Position to set.
  ///--------------------------------------------------------------------------
  void set_size(const float size);
  ///--------------------------------------------------------------------------
  /// @fn   set_color(const glm::vec4 color);
  ///
  /// @brief Text color setter.
  /// @param color Color to set.
  ///--------------------------------------------------------------------------
  void set_color(const glm::vec4 color);
  ///--------------------------------------------------------------------------
  /// @fn   render(const char* text);
  ///
  /// @brief Renderizes a text.
  /// @param text Text to render.
  ///--------------------------------------------------------------------------
  void render(const char* text);
  
 private:

  /// Index or handler of the regular font.
  int32 regular_;
  /// Font content.
  struct FONScontext* font_;
  /// Text position.
  glm::vec2 position_;
  /// Font color.
  glm::vec4 color_; 
  /// Font size.
  float size_;

  ///--------------------------------------------------------------------------
  /// @fn   release_font();
  ///
  /// @brief Releases a font from the gpu.
  ///--------------------------------------------------------------------------
  void release_font();

  /// Copy constructor.
  Txt(const Txt& copy);
  /// Assignment operator.
  Txt& operator=(const Txt& copy);

}; /* Text class */

}; /* W2D */

#endif