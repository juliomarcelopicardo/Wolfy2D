/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <time.h>
#include "core/wnd.h"
#include "core/core.h"


/*******************************************************************************
********************************************************************************
***                                                                          ***
***                              MAIN FUNCTION                               ***
***                                                                          ***
********************************************************************************
*******************************************************************************/

#pragma region MAIN

W2D::int32 main(int argc, char** argv) {

  auto& core = W2D::Core::instance();

  core.start_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

  W2D::int32 main_return = W2D::main();

  return main_return;
}

#pragma endregion 
