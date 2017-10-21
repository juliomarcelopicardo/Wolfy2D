/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/button.h"
#include "Wolfy2D/input.h"
#include "core/core.h"
#include "core/texture.h"

namespace W2D {

Button::Button() {
  position_ = { 0.0f, 0.0f };
  size_ = { 0.0f, 0.0f };
  texture_size_ = { 0.0f, 0.0f };
  initialized_ = false;
  normal_texture_id_ = 0;
  hover_texture_id_ = 0;
  pressed_texture_id_ = 0;
  disabled_texture_id_ = 0;
  is_enabled_ = true;
}

Button::~Button() {}

Button& Button::operator=(const Button& other) {
  position_ = other.position_;
  size_ = other.size_;
  texture_size_ = other.texture_size_;
  initialized_ = other.initialized_;
  normal_texture_id_ = other.normal_texture_id_;
  hover_texture_id_ = other.hover_texture_id_;
  pressed_texture_id_ = other.pressed_texture_id_;
  disabled_texture_id_ = other.disabled_texture_id_;
  is_enabled_ = other.is_enabled_;
  return *this;
}

Button::Button(const Button& other) {
  position_ = other.position_;
  size_ = other.size_;
  texture_size_ = other.texture_size_;
  initialized_ = other.initialized_;
  normal_texture_id_ = other.normal_texture_id_;
  hover_texture_id_ = other.hover_texture_id_;
  pressed_texture_id_ = other.pressed_texture_id_;
  disabled_texture_id_ = other.disabled_texture_id_;
  is_enabled_ = other.is_enabled_;
}

void Button::init(Sprite& normal, Sprite& hover, Sprite& pressed, Sprite& disabled) {
  
  texture_size_ = { normal.originalTextureSize().x, normal.originalTextureSize().y };
  size_ = texture_size_;
  position_ = { 0.0f, 0.0f };
  normal_texture_id_ = normal.textureID();
  hover_texture_id_ = hover.textureID();
  pressed_texture_id_ = pressed.textureID();
  disabled_texture_id_ = disabled.textureID();
  initialized_ = true;
}

void Button::render() {
  if (initialized_) {
    // UPDATE
    uint32 texture = normal_texture_id_;
    if (is_enabled_) {
      Vec2 mouse = Input::MousePosition();
      if (mouse.x >= position_.x && mouse.x <= position_.x + size_.x &&
          mouse.y >= position_.y && mouse.y <= position_.y + size_.y) {
        texture = hover_texture_id_;
        if (Input::IsMouseButtonPressed(Input::kMouseButton_Left)) {
          texture = pressed_texture_id_;
        }
      }
      // RENDER
      auto& sprite = Core::instance().sprite_;
      sprite.set_position({ position_.x, position_.y });
      sprite.set_texture_size({ texture_size_.x, texture_size_.y });
      sprite.set_size({ size_.x, size_.y });
      sprite.render();
    }
    else {
      texture = disabled_texture_id_;
    }
    Core::instance().sprite_.set_texture_id(texture);
  }
  else {
    printf(" ERROR: There aren't any sprites asigned to this button.\n");
  }
}


/*******************************************************************************
***                              Public Setters                              ***
*******************************************************************************/

void Button::set_position(const Vec2 position) {
  position_ = position;
}

void Button::set_size(const Vec2 size) {
  size_ = size;
}


/*******************************************************************************
***                              Public Getters                              ***
*******************************************************************************/

const Vec2 Button::size() {
  return size_;
}

const Vec2 Button::position() {
  return position_;
}



}; /* W2D */