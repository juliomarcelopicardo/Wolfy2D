/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "core/lua_class.h"
#include "core/material.h"
#include "core/core.h"
#include "core/texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>


namespace W2D {


/*******************************************************************************
***                       Constructor and destructor                         ***
*******************************************************************************/



CoreMaterial::CoreMaterial() {
  uniform_location_ = { 0, 0, 0, 0 };
}

CoreMaterial::~CoreMaterial() {
  if (glIsProgram(program_id_)) {
    glDeleteProgram(program_id_);
  }
}



/*******************************************************************************
***                            Material methods                              ***
*******************************************************************************/

void CoreMaterial::getShadersCode(const char* lua_path) {
  Lua L;
  L.doFile(lua_path);
  vertex_shader_code_ = L.getStringFromTable("Shader", "vertex");
  fragment_shader_code_ = L.getStringFromTable("Shader", "fragment");
}

void CoreMaterial::createProgram() {
  program_id_ = glCreateProgram();
}

void CoreMaterial::createShaders() {
  vertex_shader_id_ = glCreateShader(GL_VERTEX_SHADER);
  fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
}

void CoreMaterial::compileShaders() {
    
  const GLchar* vertex_shader_code = vertex_shader_code_.c_str();
  glShaderSource(vertex_shader_id_, 1, &vertex_shader_code, NULL);
  glCompileShader(vertex_shader_id_);
  logShaderError(vertex_shader_id_);

  const GLchar* fragment_shader_code = fragment_shader_code_.c_str();
  glShaderSource(fragment_shader_id_, 1, &fragment_shader_code, NULL);
  glCompileShader(fragment_shader_id_);
  logShaderError(fragment_shader_id_);
}

void CoreMaterial::attachShaders() {
  glAttachShader(program_id_, vertex_shader_id_);
  glAttachShader(program_id_, fragment_shader_id_);
}


void CoreMaterial::linkProgram() {
  glLinkProgram(program_id_);
  logProgramError();
}


void CoreMaterial::detachShaders() {
  glDetachShader(program_id_, vertex_shader_id_);
  glDetachShader(program_id_, fragment_shader_id_);
}

void CoreMaterial::deleteShaders() {
  glDeleteShader(vertex_shader_id_);
  glDeleteShader(fragment_shader_id_);
}

/* Hacemos esto para optimizar, guardando los uniforms en variables evitamos tener
   que hacer la llamada glGetUniformLocation en cada frame (ya que es muy costosa).
*/
void CoreMaterial::saveUniformLocations() { 

  uint32 program = program_id_;

  glUseProgram(program_id_);

  // Material Uniforms.
  uniform_location_.model_matrix = glGetUniformLocation(program, "u_m_matrix");
  uniform_location_.projection_matrix = glGetUniformLocation(program, "u_p_matrix");
  uniform_location_.time = glGetUniformLocation(program, "u_time");
  uniform_location_.texture = glGetUniformLocation(program, "u_sample");
  
  glUseProgram(0);
}

void CoreMaterial::render(const float model_matrix[16], 
                          const float projection_matrix[16], 
                          const uint32 texture_id) {
  //Estas dos flags son las que van a hacer que todo alpha por debajo
  //de 0.01 sea descartado, y sin usar un discard.
  glAlphaFunc(GL_GREATER, 0.01f);
  glEnable(GL_ALPHA_TEST);

  //Estas dos flags son para que primero se pinte lo que se ha de pintar
  //primero, y no a la inversa.
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_ALWAYS);

  glUseProgram(program_id_);

  glUniformMatrix4fv(uniform_location_.model_matrix, 1, GL_FALSE, model_matrix);
  glUniformMatrix4fv(uniform_location_.projection_matrix, 1, GL_FALSE, projection_matrix);
  glUniform1i(uniform_location_.time, (uint32)Time());
  glActiveTexture(GL_TEXTURE0 + 0);
  glBindTexture(GL_TEXTURE_2D, texture_id);
  glUniform1i(uniform_location_.texture, 0);
}

void CoreMaterial::init(const char* lua_path) {
  getShadersCode(lua_path);
  createProgram();
  createShaders();
  compileShaders();
  attachShaders();
  linkProgram();
  detachShaders();
  deleteShaders();
  saveUniformLocations();
}



/*******************************************************************************
***                            Error checkings                               ***
*******************************************************************************/

void CoreMaterial::logShaderError(const uint32 shader_id_) {
  int32 log_length = 0;
  int32 output = 0;
  glGetShaderiv(shader_id_, GL_COMPILE_STATUS, &output);
  glGetShaderiv(shader_id_, GL_INFO_LOG_LENGTH, &log_length);

  if (output == GL_FALSE || log_length > 0) {
    std::vector<char> error_message(log_length + 1);
    glGetShaderInfoLog(shader_id_, log_length, nullptr, error_message.data());
      
    std::string log_error("Shader ERROR: ");
    log_error += error_message.data();
    printf("\n %s", log_error.c_str());
    exit(EXIT_FAILURE);
  }
}


void CoreMaterial::logProgramError() {
  int32 log_length = 0;
  int32 output = 0;
  glGetProgramiv(program_id_, GL_LINK_STATUS, &output);
  glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &log_length);

  if (output == GL_FALSE || log_length > 0) {
    std::vector<char> error_message(log_length + 1);
    glGetProgramInfoLog(program_id_, log_length, nullptr, error_message.data());
      
    std::string log_error("Shader ERROR: ");
    log_error += error_message.data();
    printf("\n %s", log_error.c_str());
    exit(EXIT_FAILURE);
  }
}

};/* W2D */
