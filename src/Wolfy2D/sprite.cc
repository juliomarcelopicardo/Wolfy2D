/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/sprite.h"
#include "core/core.h"
#include "core/sprite.h"

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
  position_ = sprite.position();
  texture_size_ = sprite.textureSize();
  size_ = sprite.size();
  rotation_ = sprite.rotation();
  texture_id_ = sprite.textureID();
  release_sprite_when_destroy_ = true;
}

void Sprite::set_position(const glm::vec2 position) {
  position_ = position;
}

void Sprite::set_size(const glm::vec2 size) {
  size_ = size;
}

void Sprite::set_rotation(const float radians) {
  rotation_ = radians;
}


void Sprite::render() {
  auto& sprite = Core::instance().sprite_;
  sprite.set_texture_id(texture_id_);
  sprite.set_position(position_);
  sprite.set_texture_size(texture_size_);
  sprite.set_size(size_);
  sprite.set_rotation(rotation_);
  sprite.render();
}




}; /* W2D */