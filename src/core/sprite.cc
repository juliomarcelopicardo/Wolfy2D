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
void CoreSprite::init(const CoreTexture& texture) {
  position_ = { 0.0f, 0.0f };
  scale_ = { 1.0f, 1.0f };
  rotation_ = 0.0f;
  texture_size_ = { (float)texture.width_, (float)texture.height_ };
  set_size(texture_size_);
  texture_id_ = texture.texture_id_;
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

const glm::vec2 CoreSprite::position() {
  return position_;
}

const glm::vec2 CoreSprite::size() {
  return size_;
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