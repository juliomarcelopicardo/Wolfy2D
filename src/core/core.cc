/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "core/core.h"

namespace W2D {


/*******************************************************************************
********************************************************************************
***                                                                          ***
***                                  CORE                                    ***
***                                                                          ***
********************************************************************************
*******************************************************************************/

/*******************************************************************************
***                       Constructor and destructor                         ***
*******************************************************************************/

Core& Core::instance() {
  static Core* singleton = new Core();
  return *singleton;
}

Core::Core() {}

Core::~Core() {}

};/* JI */
