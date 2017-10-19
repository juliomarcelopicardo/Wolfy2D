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

/// Locations of the shader uniforms
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
  /// Default class constructor.
  CoreMaterial();
  /// Default class destructor.
  ~CoreMaterial();

/*******************************************************************************
***                            Material methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   render(const float model_matrix[16], const float projection_matrix[16], const uint32 texture_id);
  ///
  /// @brief Uses the material for future renders.
  /// @param model_matrix Model matrix.
  /// @param projection_matrix Projection matrix.
  /// @param texture_id Texture to render ID.
  ///--------------------------------------------------------------------------
  void render(const float model_matrix[16],
              const float projection_matrix[16],
              const uint32 texture_id);

  ///--------------------------------------------------------------------------
  /// @fn   init(const char* lua_path);
  ///
  /// @brief Initializes a material shader from a lua file.
  /// @param lua_path File path.
  ///--------------------------------------------------------------------------
  void init(const char* lua_path);


/*******************************************************************************
***                        Material Setters & Getters                        ***
*******************************************************************************/

/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/
  

 private:

/*******************************************************************************
***                             Private Methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   getShadersCode(const char* lua_path);
  ///
  /// @brief Gets the shader text from a lua file.
  /// @param lua_path File path.
  ///--------------------------------------------------------------------------
  void getShadersCode(const char* lua_path);
  ///--------------------------------------------------------------------------
  /// @fn   createProgram();
  ///
  /// @brief Creates the material program.
  ///--------------------------------------------------------------------------
  void createProgram();
  ///--------------------------------------------------------------------------
  /// @fn   createShaders();
  ///
  /// @brief Creates the material shaders.
  ///--------------------------------------------------------------------------
  void createShaders();
  ///--------------------------------------------------------------------------
  /// @fn   compileShaders();
  ///
  /// @brief Compiles the shaders.
  ///--------------------------------------------------------------------------
  void compileShaders();
  ///--------------------------------------------------------------------------
  /// @fn   attachShaders();
  ///
  /// @brief Attach shaders to the graphic card.
  ///--------------------------------------------------------------------------
  void attachShaders();
  ///--------------------------------------------------------------------------
  /// @fn   detachShaders();
  ///
  /// @brief Detach shaders from the graphic card.
  ///--------------------------------------------------------------------------
  void detachShaders();
  ///--------------------------------------------------------------------------
  /// @fn   deleteShaders();
  ///
  /// @brief Deletes the shader material shaders text.
  ///--------------------------------------------------------------------------
  void deleteShaders();
  ///--------------------------------------------------------------------------
  /// @fn   linkProgram();
  ///
  /// @brief Links the program.
  ///--------------------------------------------------------------------------
  void linkProgram();
  ///--------------------------------------------------------------------------
  /// @fn   saveUniformLocations();
  ///
  /// @brief Saves all the uniform values to optimize.
  ///--------------------------------------------------------------------------
  void saveUniformLocations();

/*******************************************************************************
***                             Error checkings                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   logShaderError(const uint32 shader_id);
  ///
  /// @brief If existing, logs the program errors.
  /// @param shader_id id of the shaders that will be checked.
  ///--------------------------------------------------------------------------
  void logShaderError(const uint32 shader_id);
  ///--------------------------------------------------------------------------
  /// @fn   logProgramError();
  ///
  /// @brief Logs the program errors if existing.
  ///--------------------------------------------------------------------------
  void logProgramError();

/*******************************************************************************
***                           Private attributes                             ***
*******************************************************************************/
 private:
  /// Vertex shader code.
  std::string vertex_shader_code_;
  /// Pixel / fragment shader code.
  std::string fragment_shader_code_;
  /// Vertex shader id handler.
  uint32 vertex_shader_id_;
  /// Fragment shader id handler.
  uint32 fragment_shader_id_;
  /// Locations of the shader uniforms.
  UniformLocation uniform_location_;
  /// Id of the program used by the material.
  uint32 program_id_;

};
};/* W2D */

#endif
