/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "core/texture.h"
#include "core/wnd.h"
#include "core/material.h"
#include "core/geometry.h"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"
#include "core/core.h"
#include "STB/stb_image.h"


namespace W2D {

Texture::Texture() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  rotation_ = 0.0f;
  texture_id_ = 0;
  pivot_ = kSpritePivotPoint_Center;
  updateModelMatrix();
}

Texture::~Texture() {}

Texture::Texture(const Texture & copy) {
  position_ = copy.position_;
  size_ = copy.size_;
  rotation_ = copy.rotation_;
  texture_id_ = copy.texture_id_;
  pivot_ = copy.pivot_;
  model_matrix_ = copy.model_matrix_;
}

Texture & Texture::operator=(const Texture & copy) {
  position_ = copy.position_;
  size_ = copy.size_;
  rotation_ = copy.rotation_;
  texture_id_ = copy.texture_id_;
  pivot_ = copy.pivot_;
  model_matrix_ = copy.model_matrix_;
  return *this;
}


/******************************************************************************
***                                  INIT                                   ***
******************************************************************************/
void Texture::init(const char* texture_path) {

  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  rotation_ = 0.0f;

  //Loading the image, we have to do this before generate the identifier:
  int32 channels = 0;

  stbi_set_flip_vertically_on_load(true);
  int32 width, height;
  unsigned char* tmp_texture = stbi_load(texture_path, &width, &height, &channels,
    STBI_rgb_alpha);
  if (tmp_texture) {

    //We can blend the texture to refuse to show the alpha channel.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Once we have loaded the texture, we create the handler and we bind it:
    texture_id_ = 0;
    glGenTextures(1, &texture_id_);
    glBindTexture(GL_TEXTURE_2D, texture_id_);

    // Repeat or clamp to edge work.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //The "internalformat" -third parameter- means the format that OpenGL 
    //should use to store the data internally, this is the format of 
    //the texture. Is different of the "format" -7th parameter-, a parameter
    //which combined with the type defines the layout of the data that 
    //we pass to OpenGL in the last parameter.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
      GL_UNSIGNED_BYTE, tmp_texture);
    glBindTexture(GL_TEXTURE_2D, 0); //Unbind the texture.
                                     //Releasing the image data:
    stbi_image_free(tmp_texture);
    size_ = { (float)width, (float)height };
  }
  else {
    std::string error(" ERROR: Texture incorrect, file \"");
    error += texture_path;
    error += "\" doesn't exists.";
    printf("\n %s", error.c_str());
    //exit(EXIT_FAILURE);
    Texture& t = Core::instance().error_texture_;
    texture_id_ = t.textureID();
    size_ = t.size_;
    rotation_ = t.rotation_;
    pivot_ = t.pivot_;
  }

  updateModelMatrix();
}



/******************************************************************************
***                          SETTERS AND GETTERS                            ***
******************************************************************************/
void Texture::set_position(const glm::vec2 pos) {
  position_ = pos;
  updateModelMatrix();
}

void Texture::set_rotation(const float rotation) {
  rotation_ = rotation;
  updateModelMatrix();
}

void Texture::set_size(const glm::vec2 size) {
  size_ = size;
  updateModelMatrix();
}

void Texture::set_texture_id(const uint32 texture_id) {
  texture_id_ = texture_id;
}

void Texture::set_pivot(const SpritePivotPoint pivot) {
  pivot_ = pivot;
  updateModelMatrix();
}

const glm::vec2 Texture::position() {
  return position_;
}

const glm::vec2 Texture::size() {
  return size_;
}

const float Texture::rotation() {
  return rotation_;
}

const uint32 Texture::textureID() {
  return texture_id_;
}

const SpritePivotPoint Texture::pivot() {
  return pivot_;
}

void Texture::updateModelMatrix() {

  model_matrix_ = glm::mat4(1.0f);
  glm::vec2 position = position_;
  glm::vec2 half_size = size_ * 0.5f;
  switch (pivot_) {
  case W2D::kSpritePivotPoint_UpLeft: {
    position.x = position.x + half_size.x;
    position.y = position.y + half_size.y;
  }break;
  case W2D::kSpritePivotPoint_Up: {
    position.x = position.x;
    position.y = position.y + half_size.y;
  }break;
  case W2D::kSpritePivotPoint_UpRight: {
    position.x = position.x - half_size.x;
    position.y = position.y + half_size.y;
  }break;
  case W2D::kSpritePivotPoint_Right: {
    position.x = position.x - half_size.x;
    position.y = position.y;
  }break;
  case W2D::kSpritePivotPoint_Downight: {
    position.x = position.x - half_size.x;
    position.y = position.y - half_size.y;
  }break;
  case W2D::kSpritePivotPoint_Down: {
    position.x = position.x;
    position.y = position.y - half_size.y;
  }break;
  case W2D::kSpritePivotPoint_DownLeft: {
    position.x = position.x + half_size.x;
    position.y = position.y - half_size.y;
  }break;
  case W2D::kSpritePivotPoint_Left: {
    position.x = position.x + half_size.x;
    position.y = position.y;
  }break;
  }

  model_matrix_ = glm::translate(model_matrix_, glm::vec3(position.x, position.y, 0.0f));
  model_matrix_ = glm::rotate(model_matrix_, rotation_, glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix_ = glm::scale(model_matrix_, glm::vec3(size_.x, size_.y, 1.0f));
}


/******************************************************************************
***                                RENDER                                   ***
******************************************************************************/
void Texture::render() {

  auto& core = Core::instance();
  
  core.material_.render(glm::value_ptr(model_matrix_),
                        glm::value_ptr(core.projection_matrix_),
                        texture_id_);

  core.geometry_.render();
}


void Texture::releaseTexture() {
  if (glIsTexture(texture_id_)) {
    glDeleteTextures(1, &texture_id_);
  }
}



}; /* W2D */