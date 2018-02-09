/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_CORE_H__
#define __WOLFY2D_CORE_H__ 1

#include "Wolfy2D.h"
#include "core/wnd.h"
#include "core/geometry.h"
#include "core/material.h"
#include "core/texture.h"
#include "core/txt.h"
#include "core/imgui_class.h"
#include <stdio.h>
#include <map>


namespace W2D {
  

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
  /// Sprites created.
  std::map <std::string, Texture> texture_factory_;
  /// Camera ortographic projection matrix.
  glm::mat4 projection_matrix_;
  /// Time when the application starts.
  uint64 start_time_;


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
