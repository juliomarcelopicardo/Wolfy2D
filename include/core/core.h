/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_CORE_H__
#define __WOLFY2D_CORE_H__ 1

#include "core/wnd.h"
#include "core/geometry.h"
#include "core/material.h"
#include "core/texture.h"
#include "core/sprite.h"
#include "core/txt.h"
#include "core/imgui_class.h"
#include "core/user_interface.h"
#include "jmp/include/jmp.h"
#include <map>

#define SCRIPT_CODE_MAX_LENGTH 10240

namespace W2D {
  
const char kScriptFilename[] = "../scripts/config.jmp";

/*******************************************************************************
********************************************************************************
***                                                                          ***
***                           WOLFY2D CORE CLASS                             ***
***                                                                          ***
********************************************************************************
*******************************************************************************/

class Core {

 public:

  /// Singleton instance.
  static Core& instance();

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

  /// Default class constructor.
  Core();
  /// Default class destructor.
  ~Core();

/*******************************************************************************
***                              Core Methods                                ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   calculateProjectionMatrix();
  ///
  /// @brief Calculates the camera projection matrix.
  ///--------------------------------------------------------------------------
  void calculateProjectionMatrix();

/*******************************************************************************
***                               Attributes                                 ***
*******************************************************************************/
  /// Default window instance.
  Wnd window_;
  /// Sprites quad geometry.
  Geometry geometry_;
  /// Sprites material.
  Material material_;
  /// Texts base object.
  Txt text_;
  /// Sprite error object, default texture if anyone is not loaded properly.
  Texture error_texture_;
  /// Imgui properties and manager.
  ImGuiProperties imgui_;
  /// Textures created.
  std::map <std::string, Texture> texture_factory_;
  /// Sprites created.
  std::map <std::string, Sprite> sprite_factory_;
  /// Camera ortographic projection matrix.
  glm::mat4 projection_matrix_;
  /// Time when the application starts.
  uint64 start_time_;

///////////////////////////// IMGUI USER INTERFACE /////////////////////////////

  /// ImGui User interface 
  UserInterface user_interface_;
  
///////////////////////////////////// DEMO /////////////////////////////////////

  /// JMP scripting language machine.
  JMP::Machine machine_;
  /// Code from the JMP script loaded using the machine. Edited using imgui.
  char8 script_code_[SCRIPT_CODE_MAX_LENGTH];

 private:

   

/*******************************************************************************
***                         Private Copy Constructor                         ***
*******************************************************************************/


  /// Copy constructor.
  Core(const Core& copy);
  /// Assignment operator.
  Core& operator=(const Core& copy);

}; /* CORE */
}; /* W2D */

#endif
