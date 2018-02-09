/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "core/core.h"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"


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

void Core::calculateProjectionMatrix() {
  projection_matrix_ = glm::ortho(0.0f,
                       (float)Core::instance().window_.width_,
                       (float)Core::instance().window_.height_,
                       0.0f,
                       -1.0f,
                       1.0f);
}

};/* JI */
