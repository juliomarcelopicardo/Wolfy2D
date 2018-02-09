/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/animation.h"
#include "core/core.h"

namespace W2D {

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

Animation::Animation() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  rotation_ = 0.0f;
  texture_size_ = { 0.0f, 0.0f };
  timer_ = 0;
  milliseconds_per_change_ = 300;
  texture_id_.clear();
  texture_id_list_length_ = 0;
  index_ = 0;
  initialized_ = false;
}

Animation::~Animation() {
  texture_id_.clear();
}

Animation& Animation::operator=(const Animation& other) {
  position_ = other.position_;
  size_ = other.size_;
  rotation_ = other.rotation_;
  texture_size_ = other.texture_size_;
  texture_id_ = other.texture_id_;
  timer_ = other.timer_;
  milliseconds_per_change_ = other.milliseconds_per_change_;
  texture_id_list_length_ = other.texture_id_list_length_;
  index_ = other.index_;
  initialized_ = other.initialized_;
  return *this;
}

Animation::Animation(const Animation& other) {
  position_ = other.position_;
  size_ = other.size_;
  rotation_ = other.rotation_;
  texture_size_ = other.texture_size_;
  texture_id_ = other.texture_id_;
  timer_ = other.timer_;
  milliseconds_per_change_ = other.milliseconds_per_change_;
  texture_id_list_length_ = other.texture_id_list_length_;
  index_ = other.index_;
  initialized_ = other.initialized_;
}

/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/

void Animation::init(Sprite* sprite_list, const uint32 number_of_sprites) {
  

  if (sprite_list && number_of_sprites > 1) {
    texture_size_ = sprite_list[0].originalTextureSize();
    size_ = texture_size_;
    rotation_ = sprite_list[0].rotation();
    texture_id_.clear();
    texture_id_.resize(number_of_sprites);
    texture_id_list_length_ = number_of_sprites;
    index_ = 0;
    for (uint32 i = 0; i < texture_id_list_length_; ++i) {
      texture_id_[i] = sprite_list[i].textureID();
    }
    initialized_ = true;
  }
  else {
    initialized_ = false;
    printf(" ERROR: Can't create animation without more than 1 sprites.\n");
  }
}

void Animation::render() {
  if (initialized_) {
    // UPDATE
    if (Time() - timer_ > milliseconds_per_change_) {
      index_ += 1;
      if (index_ >= texture_id_list_length_) { index_ = 0; }
      timer_ = Time();
    }
    // RENDER

  }
  else {
    printf(" ERROR: There aren't any sprites asigned to this animation.\n");
  }
}

/*******************************************************************************
***                              Public Setters                              ***
*******************************************************************************/

void Animation::set_position(const Vec2 position) {
  position_ = position;
}

void Animation::set_size(const Vec2 size) {
  size_ = size;
}

void Animation::set_rotation(const float radians) {
  rotation_ = radians;
}

void Animation::set_speed(const uint64 milliseconds_per_change) {
  milliseconds_per_change_ = milliseconds_per_change;
}

/*******************************************************************************
***                              Public Getters                              ***
*******************************************************************************/

const Vec2 Animation::size() {
  return size_;
}

const float Animation::rotation() {
  return rotation_;
}

const Vec2 Animation::position() {
  return position_;
}

const uint64 Animation::speed() {
  return milliseconds_per_change_;
}

}; /* W2D */
