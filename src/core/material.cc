/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "core/material.h"
#include "core/core.h"
#include "imgui/logger_module.h"
#include <string>
#include <vector>


namespace W2D {


/*******************************************************************************
***                       Constructor and destructor                         ***
*******************************************************************************/



Material::Material() {
  uniform_location_ = { 0, 0, 0, 0 };
}

Material::~Material() {
  if (glIsProgram(program_id_)) {
    glDeleteProgram(program_id_);
  }
}



/*******************************************************************************
***                            Material methods                              ***
*******************************************************************************/

void Material::saveShadersCode() {

  vertex_shader_code_.clear();
  fragment_shader_code_.clear();
  vertex_shader_code_ =
    "#version 330\n"
    "layout(location = 0) in vec3 a_position;\n"
    "layout(location = 1) in vec2 a_uv;\n"
    "uniform mat4 u_m_matrix;\n"
    "uniform mat4 u_p_matrix;\n"
    "uniform int u_time;\n"
    "out vec3 normal;\n"
    "out vec2 uv;\n"
    "void main() {\n"
    "  uv = a_uv;\n"
    "  gl_Position = u_p_matrix* u_m_matrix * vec4(a_position, 1.0);\n}";

  fragment_shader_code_ =
    "#version 330\n"
    "in vec2 uv;\n"
    "uniform sampler2D u_sample;\n"
    "out vec4 fragColor;\n"
    "void main() {\n"
    "  fragColor = texture(u_sample, uv);\n"
    "}\n";
}

void Material::createProgram() {
  program_id_ = glCreateProgram();
}

void Material::createShaders() {
  vertex_shader_id_ = glCreateShader(GL_VERTEX_SHADER);
  fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
}

void Material::compileShaders() {
    
  const GLchar* vertex_shader_code = vertex_shader_code_.c_str();
  glShaderSource(vertex_shader_id_, 1, &vertex_shader_code, NULL);
  glCompileShader(vertex_shader_id_);
  logShaderError(vertex_shader_id_);

  const GLchar* fragment_shader_code = fragment_shader_code_.c_str();
  glShaderSource(fragment_shader_id_, 1, &fragment_shader_code, NULL);
  glCompileShader(fragment_shader_id_);
  logShaderError(fragment_shader_id_);
}

void Material::attachShaders() {
  glAttachShader(program_id_, vertex_shader_id_);
  glAttachShader(program_id_, fragment_shader_id_);
}


void Material::linkProgram() {
  glLinkProgram(program_id_);
  logProgramError();
}


void Material::detachShaders() {
  glDetachShader(program_id_, vertex_shader_id_);
  glDetachShader(program_id_, fragment_shader_id_);
}

void Material::deleteShaders() {
  glDeleteShader(vertex_shader_id_);
  glDeleteShader(fragment_shader_id_);
}

/* Hacemos esto para optimizar, guardando los uniforms en variables evitamos tener
   que hacer la llamada glGetUniformLocation en cada frame (ya que es muy costosa).
*/
void Material::saveUniformLocations() { 

  uint32 program = program_id_;

  glUseProgram(program_id_);

  // Material Uniforms.
  uniform_location_.model_matrix = glGetUniformLocation(program, "u_m_matrix");
  uniform_location_.projection_matrix = glGetUniformLocation(program, "u_p_matrix");
  uniform_location_.time = glGetUniformLocation(program, "u_time");
  uniform_location_.texture = glGetUniformLocation(program, "u_sample");
  
  glUseProgram(0);
}

void Material::render(const float model_matrix[16], 
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

void Material::init(const char* lua_path) {
  saveShadersCode();
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

void Material::logShaderError(const uint32 shader_id_) {
  int32 log_length = 0;
  int32 output = 0;
  glGetShaderiv(shader_id_, GL_COMPILE_STATUS, &output);
  glGetShaderiv(shader_id_, GL_INFO_LOG_LENGTH, &log_length);

  if (output == GL_FALSE || log_length > 0) {
    std::vector<char> error_message(log_length + 1);
    glGetShaderInfoLog(shader_id_, log_length, nullptr, error_message.data());
      
    std::string log_error("Shader ERROR: ");
    log_error += error_message.data();
    Core::instance().user_interface_.log_.AddLog_E(log_error);
    exit(EXIT_FAILURE);
  }
}


void Material::logProgramError() {
  int32 log_length = 0;
  int32 output = 0;
  glGetProgramiv(program_id_, GL_LINK_STATUS, &output);
  glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &log_length);

  if (output == GL_FALSE || log_length > 0) {
    std::vector<char> error_message(log_length + 1);
    glGetProgramInfoLog(program_id_, log_length, nullptr, error_message.data());
      
    std::string log_error("Shader ERROR: ");
    log_error += error_message.data();
    Core::instance().user_interface_.log_.AddLog_E(log_error);
    exit(EXIT_FAILURE);
  }
}

};/* W2D */
