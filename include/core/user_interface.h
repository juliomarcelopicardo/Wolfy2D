/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __CORE_IMGUI_USER_INTERFACE_H__
#define __CORE_IMGUI_USER_INTERFACE_H__ 1

#include "Wolfy2D/globals.h"


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
  /// @fn   init() const;
  ///
  /// @brief Initializes the setup of the editor.
  ///--------------------------------------------------------------------------
  void init() const;

  ///--------------------------------------------------------------------------
  /// @fn   update();
  ///
  /// @brief Updates the editor.
  ///--------------------------------------------------------------------------
  void update();

/*******************************************************************************
***                           Public attributes                              ***
*******************************************************************************/

  /// Interface script save mode
  int32 save_mode_;

private:

/*******************************************************************************
***                            Private methods                               ***
*******************************************************************************/

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

  ///--------------------------------------------------------------------------
  /// @fn   setupStyle() const;
  ///
  /// @brief Setup the editor Style.
  ///--------------------------------------------------------------------------
  void setupStyle() const;

  ///--------------------------------------------------------------------------
  /// @fn   updateTopBar();
  ///
  /// @brief Updates the top bar of the editor.
  ///--------------------------------------------------------------------------
  void updateTopBar();

  ///--------------------------------------------------------------------------
  /// @fn   updateBottomBar() const;
  ///
  /// @brief Updates the bottom bar of the editor.
  ///--------------------------------------------------------------------------
  void updateBottomBar() const;

  ///--------------------------------------------------------------------------
  /// @fn   updateEditor() const;
  ///
  /// @brief Updates the editor layout.
  ///--------------------------------------------------------------------------
  void updateEditorLayout() const;

  ///--------------------------------------------------------------------------
  /// @fn   updateSceneDock() const;
  ///
  /// @brief Updates the scene dock, from the editor layout.
  ///--------------------------------------------------------------------------
  void updateSceneDock() const;

  ///--------------------------------------------------------------------------
  /// @fn   updateHierarchyDock() const;
  ///
  /// @brief Updates the hierarchy dock, from the editor layout.
  ///--------------------------------------------------------------------------
  void updateHierarchyDock() const;

  ///--------------------------------------------------------------------------
  /// @fn   updateScriptDock() const;
  ///
  /// @brief Updates the JMP script dock, from the editor layout.
  ///--------------------------------------------------------------------------
  void updateScriptDock() const;

  ///--------------------------------------------------------------------------
  /// @fn   showLastItemDescriptionTooltip(const char* description) const;
  ///
  /// @brief Shows a tooltip when the last imgui item added is hovered.
  ///--------------------------------------------------------------------------
  void showLastItemDescriptionTooltip(const char* description) const ;

/*******************************************************************************
***                          	Private attributes                             ***
*******************************************************************************/

  /// Height or size in Y axis of the top bar.
  float32 top_bar_height_;
  /// Height or size in Y axis of the bottom bar.
  float32 bottom_bar_height_;




};/* UserInterface class */

}; /* W2D */

#endif