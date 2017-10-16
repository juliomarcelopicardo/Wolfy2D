/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#ifndef __CORE_MATERIAL_H__
#define __CORE_MATERIAL_H__ 1

#include "Wolfy2D.h"
#include <string>

namespace W2D {

/// 
struct UniformLocation {
  uint32 model_matrix;
  uint32 projection_matrix;
  uint32 time;
  uint32 texture;
};

class CoreMaterial {
 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  CoreMaterial();
  ~CoreMaterial();

/*******************************************************************************
***                            Material methods                              ***
*******************************************************************************/

  void render(const float model_matrix[16],
              const float projection_matrix[16],
              const uint32 texture_id);

  void init(const char* lua_path);


/*******************************************************************************
***                        Material Setters & Getters                        ***
*******************************************************************************/

/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/
  
  std::string vertex_shader_code_;
  std::string fragment_shader_code_;
  uint32 program_id_;
  uint32 vertex_shader_id_;
  uint32 fragment_shader_id_;
  UniformLocation uniform_location_;

 private:

/*******************************************************************************
***                             Private Methods                              ***
*******************************************************************************/
  void getShadersCode(const char* lua_path);
  void createProgram();
  void createShaders();
  void compileShaders();
  void attachShaders();
  void detachShaders();
  void deleteShaders();
  void linkProgram();
  void saveUniformLocations();

/*******************************************************************************
***                             Error checkings                              ***
*******************************************************************************/

  void logShaderError(const uint32 shader_id);
  void logProgramError();

/*******************************************************************************
***                           Private attributes                             ***
*******************************************************************************/

};
};/* W2D */

#endif
