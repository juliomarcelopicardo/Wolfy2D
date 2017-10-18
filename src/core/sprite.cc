/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "core/sprite.h"
#include "core/texture.h"
#include "core/window.h"
#include "core/material.h"
#include "core/geometry.h"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"
#include "core/core.h"
#include "STB/stb_image.h"


namespace W2D {

CoreSprite::CoreSprite() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  scale_ = { 1.0f, 1.0f };
  rotation_ = 0.0f;
  texture_id_ = 0;
  texture_size_ = { 0.0f, 0.0f };
}

CoreSprite::~CoreSprite() {

}


/******************************************************************************
***                                  INIT                                   ***
******************************************************************************/
void CoreSprite::init(const char* texture_path) {

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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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
void CoreSprite::set_position(const glm::vec2 pos) {
  position_ = pos;
}

void CoreSprite::set_rotation(const float rotation) {
  rotation_ = rotation;
}

void CoreSprite::set_size(const glm::vec2 size) {
  size_ = size;
  scale_.x = size.x / texture_size_.x;
  scale_.y = size.y / texture_size_.y;
}

void CoreSprite::set_texture_id(const uint32 texture_id) {
  texture_id_ = texture_id;
}

const glm::vec2 CoreSprite::position() {
  return position_;
}

const glm::vec2 CoreSprite::size() {
  return size_;
}

const glm::vec2 CoreSprite::textureSize() {
  return texture_size_;
}

const uint32 CoreSprite::textureID() {
  return texture_id_;
}


/******************************************************************************
***                                RENDER                                   ***
******************************************************************************/
void CoreSprite::render() {

  auto& core = Core::instance();
  auto& material = core.material_;
  auto& geometry = core.geometry_;

  glm::vec2 img_size = { size_.x * scale_.x, size_.y * scale_.y };

  glm::mat4 model_matrix(1.0f);
  model_matrix = glm::translate(model_matrix, glm::vec3(position_.x, position_.y, 0.0f));
  model_matrix = glm::rotate(model_matrix, rotation_, glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix = glm::scale(model_matrix, glm::vec3(img_size.x, img_size.y, 1.0f));

  glm::mat4 projection = glm::ortho(0.0f, (float)core.window_.width_, (float)core.window_.height_, 0.0f, -1.0f, 1.0f);



  material.render(glm::value_ptr(model_matrix),
                  glm::value_ptr(projection),
                  texture_id_);

  geometry.render();
}



}; /* W2D */