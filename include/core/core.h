/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_CORE_H__
#define __WOLFY2D_CORE_H__ 1

#include "Wolfy2D.h"
#include "core/window.h"
#include "core/geometry.h"
#include "core/material.h"
#include "core/sprite.h"
#include "core/text.h"
#include <stdio.h>


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
***                               Attributes                                 ***
*******************************************************************************/
  /// Default window instance.
  Wnd window_;
  /// Sprites quad geometry.
  Geometry geometry_;
  /// Sprites material.
  CoreMaterial material_;
  /// Texts base object.
  CoreText text_;
  /// Sprite base object.
  CoreSprite sprite_;

  /// Time when the application starts.
  uint64 start_time_;

/*******************************************************************************
***                         Private Copy Constructor                         ***
*******************************************************************************/
 private:

  /// Copy constructor.
  Core(const Core& copy);
  /// Assignment operator.
  Core& operator=(const Core& copy);

}; /* CORE */
}; /* W2D */

#endif
