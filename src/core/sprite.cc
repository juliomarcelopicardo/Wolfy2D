/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#include "core/sprite.h"
#include "core/wnd.h"
#include "core/material.h"
#include "core/geometry.h"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"
#include "core/core.h"


namespace W2D {

Sprite::Sprite() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  rotation_ = 0.0f;
  texture_id_ = 0;
  pivot_ = kPivotPoint_Center;
  updateModelMatrix();
}

Sprite::~Sprite() {}

Sprite::Sprite(const Sprite & copy) {
  position_ = copy.position_;
  size_ = copy.size_;
  rotation_ = copy.rotation_;
  texture_id_ = copy.texture_id_;
  pivot_ = copy.pivot_;
  model_matrix_ = copy.model_matrix_;
}

Sprite & Sprite::operator=(const Sprite & copy) {
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
void Sprite::init(const char* texture_path) {

  auto& core = Core::instance();

  // If the texture doesnt exists we will create a new one.
  if (core.texture_factory_.find(texture_path) == core.texture_factory_.end()) {
    Texture texture;
    texture.init(texture_path);
    core.texture_factory_[texture_path] = texture;
  }

  texture_id_ = core.texture_factory_[texture_path].textureID();
  position_ = { core.window_.width_ * 0.5f, core.window_.height_ * 0.5f };
  size_ = { 50.0f, 50.0f };
  rotation_ = 0.0f;


  updateModelMatrix();
}



/******************************************************************************
***                          SETTERS AND GETTERS                            ***
******************************************************************************/
void Sprite::set_position(const glm::vec2 position) {
  position_ = position;
  updateModelMatrix();
}

void Sprite::set_rotation(const float rotation) {
  rotation_ = rotation;
  updateModelMatrix();
}

void Sprite::set_size(const glm::vec2 size) {
  size_ = size;
  updateModelMatrix();
}

void Sprite::set_texture_id(const uint32 texture_id) {
  texture_id_ = texture_id;
}

void Sprite::set_pivot(const PivotPoint pivot) {
  pivot_ = pivot;
  updateModelMatrix();
}

glm::vec2 Sprite::position() const {
  return position_;
}

glm::vec2 Sprite::size() const {
  return size_;
}

float Sprite::rotation() const {
  return rotation_;
}

uint32 Sprite::textureID() const {
  return texture_id_;
}

Sprite::PivotPoint Sprite::pivot() const {
  return pivot_;
}

void Sprite::updateModelMatrix() {

  model_matrix_ = glm::mat4(1.0f);
  glm::vec2 position = position_;
  const glm::vec2 half_size = size_ * 0.5f;
  switch (pivot_) {
    case kPivotPoint_UpLeft: {
      position.x = position.x + half_size.x;
      position.y = position.y + half_size.y;
    }break;
    case kPivotPoint_Up: {
      position.y = position.y + half_size.y;
    }break;
    case kPivotPoint_UpRight: {
      position.x = position.x - half_size.x;
      position.y = position.y + half_size.y;
    }break;
    case kPivotPoint_Right: {
      position.x = position.x - half_size.x;
    }break;
    case kPivotPoint_Downight: {
      position.x = position.x - half_size.x;
      position.y = position.y - half_size.y;
    }break;
    case kPivotPoint_Down: {
      position.y = position.y - half_size.y;
    }break;
    case kPivotPoint_DownLeft: {
      position.x = position.x + half_size.x;
      position.y = position.y - half_size.y;
    }break;
    case kPivotPoint_Left: {
      position.x = position.x + half_size.x;
    }break;
    case kPivotPoint_Center: {} break;
    default: {};
  }

  model_matrix_ = glm::translate(model_matrix_, glm::vec3(position.x, position.y, 0.0f));
  model_matrix_ = glm::rotate(model_matrix_, rotation_, glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix_ = glm::scale(model_matrix_, glm::vec3(size_.x, size_.y, 1.0f));
}


/******************************************************************************
***                                RENDER                                   ***
******************************************************************************/
void Sprite::render() {

  auto& core = Core::instance();
  
  core.material_.render(glm::value_ptr(model_matrix_),
                        glm::value_ptr(core.projection_matrix_),
                        texture_id_);

  core.geometry_.render();
}





}; /* W2D */