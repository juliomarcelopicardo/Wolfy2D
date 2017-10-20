/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_IMGUI_H__
#define __WOLFY2D_IMGUI_H__ 1

#include "Wolfy2D/globals.h"
#include "Wolfy2D/text.h"
#include "Wolfy2D/sprite.h"

namespace W2D {
namespace ImGuiEditor {


/*******************************************************************************
***                        Public Setters & Getters                          ***
*******************************************************************************/
  
  ///--------------------------------------------------------------------------
  /// @fn   SetupSprite(const Sprite& sprite, const char* sprite_name);;
  ///
  /// @brief Setup and render all the sprite properties using ImGui.
  /// @param sprite Sprite which properties we want to see in the ImGui app.
  /// @param display_name Sprite name to identify this sprite in the list.
  ///--------------------------------------------------------------------------
  void SetupSprite(Sprite& sprite, const char* display_name);

  ///--------------------------------------------------------------------------
  /// @fn   SetupText(const Text& text, const char* text_name);;
  ///
  /// @brief Setup and render all the text properties using ImGui.
  /// @param text Text which properties we want to see in the ImGui app.
  /// @param display_name Text name to identify this text in the list.
  ///--------------------------------------------------------------------------
  void SetupText(Text& text, const char* display_name);


}; /* ImGuiEditor */
}; /* W2D */

#endif
