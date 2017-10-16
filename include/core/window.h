/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __CORE_WINDOW_H__
#define __CORE_WINDOW_H__ 1

#include "Wolfy2D.h"
#include "core/input.h"

#include "GLFW/glfw3.h"
#include "GLM/glm.hpp"
#include <stdio.h>
#include <stdlib.h>

namespace W2D {

class CoreWindow {

 public:

  /*******************************************************************************
  ***                        Public Attributes                                 ***
  *******************************************************************************/

  /// Window width.
  int32 width_;
  /// Window height.
  int32 height_;
  /// Window state.
  bool is_opened_;
  /// Glfw window pointer.
  GLFWwindow *glfw_window_;
  /// Initialized state.
  bool is_already_initialized_;
  /// Input instance.
  CoreInput input_;

  /*******************************************************************************
  ***                        Constructor and destructor                        ***
  *******************************************************************************/

  /// Default class constructor.
  CoreWindow();
  
  /// Default class destructor.
  ~CoreWindow();

  /*******************************************************************************
  ***                               Public methods                             ***
  *******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init(const int32 width, const int32 height, const char* name);
  ///
  /// @brief  Initializes the window with the specified width, height and window name.
  /// @param  width width of the window.
  /// @param  height height of the window.
  /// @param  name name of the window.
  ///--------------------------------------------------------------------------
  void init(const int32 width, const int32 height, const char* name);

  ///--------------------------------------------------------------------------
  /// @fn   close();
  ///
  /// @brief  Deallocates all the elements related to window such as imgui.
  ///--------------------------------------------------------------------------
  void close();

  ///--------------------------------------------------------------------------
  /// @fn   frame();
  ///
  /// @brief  Ends a frame rendering.
  ///--------------------------------------------------------------------------
  void frame();

  ///--------------------------------------------------------------------------
  /// @fn   clear(float red, float green, float blue);
  ///
  /// @brief  Clears the window with the specified color.
  /// @param  red Red color component.
  /// @param  green Green color component.
  /// @param  blue Blue color component.
  ///--------------------------------------------------------------------------
  void clear(float red, float green, float blue);


 private:

/*******************************************************************************
***                         Private Copy Constructor                         ***
*******************************************************************************/

private:

  CoreWindow(const CoreWindow& copy);
  CoreWindow& operator=(const CoreWindow& copy);


/*******************************************************************************
***                             Error checkings                              ***
*******************************************************************************/
void checkResolution();
void checkWindow();
void checkCursorPosition();

}; /* WINDOW */

}; /* W2D */

#endif
