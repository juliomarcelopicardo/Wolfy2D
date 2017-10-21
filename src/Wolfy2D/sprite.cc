/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/sprite.h"
#include "core/core.h"
#include "core/texture.h"

namespace W2D {

Sprite::Sprite() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  rotation_ = 0.0f;
  texture_size_ = { 0.0f, 0.0f };
  texture_id_ = 0;
  release_sprite_when_destroy_ = false;
}

Sprite::~Sprite() {
  if (release_sprite_when_destroy_) {
    Core::instance().sprite_.set_texture_id(texture_id_);
    Core::instance().sprite_.releaseTexture();
  }
}

Sprite& Sprite::operator=(const Sprite& other) {
  position_ = other.position_;
  size_ = other.size_;
  rotation_ = other.rotation_;
  texture_size_ = other.texture_size_;
  texture_id_ = other.texture_id_;
  release_sprite_when_destroy_ = false;
  return *this;
}

Sprite::Sprite(const Sprite& other) {
  position_ = other.position_;
  size_ = other.size_;
  rotation_ = other.rotation_;
  texture_size_ = other.texture_size_;
  texture_id_ = other.texture_id_;
  release_sprite_when_destroy_ = false;
}

void Sprite::init(const char * image_path) {
  auto& sprite = Core::instance().sprite_;

  sprite.init(image_path);
  position_ = { sprite.position().x, sprite.position().y };
  texture_size_ = { sprite.textureSize().x, sprite.textureSize().y };
  size_ = { sprite.size().x, sprite.size().y };
  rotation_ = sprite.rotation();
  texture_id_ = sprite.textureID();
  release_sprite_when_destroy_ = true;
}



void Sprite::render() {
  auto& sprite = Core::instance().sprite_;
  sprite.set_texture_id(texture_id_);
  sprite.set_position({ position_.x, position_.y });
  sprite.set_texture_size({ texture_size_.x, texture_size_.y });
  sprite.set_size({ size_.x, size_.y });
  sprite.set_rotation(rotation_);
  sprite.render();
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


}; /* W2D */