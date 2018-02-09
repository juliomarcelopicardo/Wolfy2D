/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/sprite.h"
#include "core/core.h"
#include "core/texture.h"

namespace W2D {



/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

Sprite::Sprite() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  rotation_ = 0.0f;
  texture_size_ = { 0.0f, 0.0f };
  texture_id_ = 0;
  release_sprite_when_destroy_ = false;
  pivot_ = kSpritePivotPoint_Center;
}

Sprite::~Sprite() {

}

Sprite& Sprite::operator=(const Sprite& other) {
  position_ = other.position_;
  size_ = other.size_;
  rotation_ = other.rotation_;
  texture_size_ = other.texture_size_;
  texture_id_ = other.texture_id_;
  release_sprite_when_destroy_ = false;
  pivot_ = other.pivot_;
  return *this;
}

Sprite::Sprite(const Sprite& other) {
  position_ = other.position_;
  size_ = other.size_;
  rotation_ = other.rotation_;
  texture_size_ = other.texture_size_;
  texture_id_ = other.texture_id_;
  release_sprite_when_destroy_ = false;
  pivot_ = other.pivot_;
}

/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/

void Sprite::init(const char * image_path) {

}

void Sprite::render() {

}

/*******************************************************************************
***                              Public Setters                              ***
*******************************************************************************/

void Sprite::set_position(const Vec2 position) {
  position_ = position;
}

void Sprite::set_size(const Vec2 size) {
  size_ = size;
}

void Sprite::set_rotation(const float radians) {
  rotation_ = radians;
}

void Sprite::set_pivot(const SpritePivotPoint pivot) {
  pivot_ = pivot;
}

/*******************************************************************************
***                              Public Getters                              ***
*******************************************************************************/

const Vec2 Sprite::size() {
  return size_;
}

const Vec2 Sprite::originalTextureSize() {
  return texture_size_;
}

const float Sprite::rotation() {
  return rotation_;
}

const Vec2 Sprite::position() {
  return position_;
}

const uint32 Sprite::textureID() {
  return texture_id_;
}

const SpritePivotPoint Sprite::pivot() {
  return pivot_;
}


}; /* W2D */