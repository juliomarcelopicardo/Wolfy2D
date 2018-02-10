/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/


#ifndef __IMGUI_CLASS_H__
#define __IMGUI_CLASS_H__ 1

#include "Wolfy2D/globals.h"
#include "imgui.h"

namespace W2D {


/*******************************************************************************
***                            IMGUI FUNCTIONS                               ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   InitImGui();
  ///
  /// @brief  Initializes Imgui application.
  ///--------------------------------------------------------------------------
  void InitImGui();
  ///--------------------------------------------------------------------------
  /// @fn   FrameImGui();
  ///
  /// @brief  End of Frame of the Imgui application.
  ///--------------------------------------------------------------------------
  void FrameImGui();
  ///--------------------------------------------------------------------------
  /// @fn   ShutdownImGui();
  ///
  /// @brief  Ends Imgui application.
  ///--------------------------------------------------------------------------
  void ShutdownImGui();
  ///--------------------------------------------------------------------------
  /// @fn   RenderImGui();
  ///
  /// @brief  Renders Imgui application.
  ///--------------------------------------------------------------------------
  void RenderImGui();
  ///--------------------------------------------------------------------------
  /// @fn   SetupSprites();
  ///
  /// @brief  Setup all the sprites found in the engine.
  ///--------------------------------------------------------------------------
  void SetupSprites();

/*******************************************************************************
***                            IMGUI PROPERTIES                              ***
*******************************************************************************/

/// Imgui properties struct.
struct ImGuiProperties {
  ImGuiProperties() : font_texture(0),
                      shader_handle(0),
                      vert_handle(0),
                      frag_handle(0),
                      attrib_location_tex(0),
                      attrib_location_proj_mtx(0),
                      attrib_location_position(0),
                      attrib_location_uv(0),
                      attrib_location_color(0),
                      vbo_handle(0),
                      vao_handle(0),
                      elements_handle(0),
                      global_time(0.0) {}

  /// Texture used for the fonts.
  uint32 font_texture;
  /// Shader handle.
  int32 shader_handle;
  /// Vertex shader handle.
  int32 vert_handle;
  /// Fragment shader handle.
  int32 frag_handle;
  /// Texture gpu location.
  int32 attrib_location_tex;
  /// Projection matrix location.
  int32 attrib_location_proj_mtx;
  /// Position location.
  int32 attrib_location_position;
  /// UV location.
  int32 attrib_location_uv;
  /// Color location.
  int32 attrib_location_color;
  /// VBO handle.
  uint32 vbo_handle;
  /// VAO hanlde.
  uint32 vao_handle;
  /// Indices/elements handle.
  uint32 elements_handle;
  /// Global time in miliseconds.
  double global_time;
};

///--------------------------------------------------------------------------
/// @fn   bool CreateFontTextureImGui();
///
/// @brief  Creates the texture of the font.
/// @retunr true if succesful. False is there's any error.
///--------------------------------------------------------------------------
bool CreateFontTextureImGui();
///--------------------------------------------------------------------------
/// @fn   InvalidateObjectsImGui();
///
/// @brief  Invalidates all the objects used by imgui.
///--------------------------------------------------------------------------
void InvalidateObjectsImGui();
///--------------------------------------------------------------------------
/// @fn   CreateDeviceObjectsImGui();
///
/// @brief  Creates all the objects used by imgui.
///--------------------------------------------------------------------------
bool CreateDeviceObjectsImGui();
///--------------------------------------------------------------------------
/// @fn   RenderDrawListsImGui(ImDrawData* draw_data);
///
/// @brief Render all the draw lists.
/// @param draw_data Data to render.
///--------------------------------------------------------------------------
void RenderDrawListsImGui(ImDrawData* draw_data);
///--------------------------------------------------------------------------
/// @fn   const char* GetClipboardTextImGui(void* user_data);
///
/// @brief Clipboard text getter.
/// @param user_data User data where to extract the texts.
/// @return Clipboard texts.
///--------------------------------------------------------------------------
const char* GetClipboardTextImGui(void* user_data);
///--------------------------------------------------------------------------
/// @fn   SetClipboardTextImGui(void* user_data, const char* text);
///
/// @brief Clipboard text setter.
/// @param user_data User data where to create the texts.
/// @param text texts to set in the clipboard.
///--------------------------------------------------------------------------
void SetClipboardTextImGui(void* user_data, const char* text);




}; /* W2D */


#endif 