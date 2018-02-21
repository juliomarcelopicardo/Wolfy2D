/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_IMGUI_USER_INTERFACE_H__
#define __CORE_IMGUI_USER_INTERFACE_H__ 1

#include "Wolfy2D/globals.h"
#include "imgui/imgui.h"


namespace W2D {

/// UserInterface / Imgui user interface editor.
class UserInterface {
public:


/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

  /// Default class constructor.
  UserInterface();
  /// Default class destructor.
  ~UserInterface();
  /// Default copy constructor.
  UserInterface(const UserInterface& copy) = delete;
  /// Assignment operator.
  UserInterface& operator=(const UserInterface& copy) = delete;

/*******************************************************************************
***                         User Interface methods                           ***
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

  ///--------------------------------------------------------------------------
  /// @fn   setupColors() const;
  ///
  /// @brief Setup the editor colors.
  ///--------------------------------------------------------------------------
  void setupColors() const;

  ///--------------------------------------------------------------------------
  /// @fn   setupInputKeys() const;
  ///
  /// @brief Setup the input keys.
  ///--------------------------------------------------------------------------
  void setupInputKeys() const;

/*******************************************************************************
***                     UserInterface Setters & Getters                      ***
*******************************************************************************/



/*******************************************************************************
***                          	Public attributes                             ***
*******************************************************************************/


private:

/*******************************************************************************
***                            Private methods                               ***
*******************************************************************************/



/*******************************************************************************
***                          	Private attributes                             ***
*******************************************************************************/





};/* UserInterface class */

}; /* W2D */

#endif