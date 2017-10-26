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
  scale_ = { 1.0f, 1.0f };
  rotation_ = 0.0f;
  texture_id_ = 0;
  texture_size_ = { 0.0f, 0.0f };
  pivot_ = kSpritePivotPoint_Center;
}

Texture::~Texture() {}


/******************************************************************************
***                                  INIT                                   ***
******************************************************************************/
void Texture::init(const char* texture_path) {

  position_ = { 0.0f, 0.0f };
  scale_ = { 1.0f, 1.0f };
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

  }
  else {
    std::string error(" ERROR: Texture incorrect, file \"");
    error += texture_path;
    error += "\" doesn't exists.";
    printf("\n %s", error.c_str());
    exit(EXIT_FAILURE);
  }

  texture_size_ = { (float)width, (float)height };
  size_ = texture_size_;
}



/******************************************************************************
***                          SETTERS AND GETTERS                            ***
******************************************************************************/
void Texture::set_position(const glm::vec2 pos) {
  position_ = pos;
}

void Texture::set_rotation(const float rotation) {
  rotation_ = rotation;
}

void Texture::set_size(const glm::vec2 size) {
  size_ = size;
  scale_.x = size.x / texture_size_.x;
  scale_.y = size.y / texture_size_.y;
}

void Texture::set_texture_size(const glm::vec2 texture_size) {
  texture_size_ = texture_size;
}

void Texture::set_texture_id(const uint32 texture_id) {
  texture_id_ = texture_id;
}

void Texture::set_pivot(const SpritePivotPoint pivot) {
  pivot_ = pivot;
}

const glm::vec2 Texture::position() {
  return position_;
}

const glm::vec2 Texture::size() {
  return size_;
}

const glm::vec2 Texture::textureSize() {
  return texture_size_;
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


/******************************************************************************
***                                RENDER                                   ***
******************************************************************************/
void Texture::render() {

  auto& core = Core::instance();
  auto& material = core.material_;
  auto& geometry = core.geometry_;

  glm::vec2 img_size = { size_.x * scale_.x, size_.y * scale_.y };

  glm::vec2 position = position_;
  glm::vec2 half_size = img_size * 0.5f;
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

  glm::mat4 model_matrix(1.0f);
  model_matrix = glm::translate(model_matrix, glm::vec3(position.x, position.y, 0.0f));
  model_matrix = glm::rotate(model_matrix, rotation_, glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix = glm::scale(model_matrix, glm::vec3(img_size.x, img_size.y, 1.0f));
  
  material.render(glm::value_ptr(model_matrix),
                  glm::value_ptr(projection_matrix_),
                  texture_id_);

  geometry.render();
}

void Texture::calculateProjectionMatrix() {
  projection_matrix_ = glm::ortho(0.0f, 
                                  (float)Core::instance().window_.width_, 
                                  (float)Core::instance().window_.height_, 
                                  0.0f, 
                                  -1.0f,
                                  1.0f);
}

void Texture::releaseTexture() {
  if (glIsTexture(texture_id_)) {
    glDeleteTextures(1, &texture_id_);
  }
}



}; /* W2D */