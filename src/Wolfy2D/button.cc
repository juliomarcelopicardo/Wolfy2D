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

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/

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
  current_texture_id_ = other.current_texture_id_;
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
  current_texture_id_ = other.current_texture_id_;
  is_enabled_ = other.is_enabled_;
}


/*******************************************************************************
***                              Public Methods                              ***
*******************************************************************************/

void Button::init(Sprite& normal, Sprite& hover, Sprite& pressed, Sprite& disabled) {
  
  texture_size_ = { normal.originalTextureSize().x, normal.originalTextureSize().y };
  size_ = texture_size_;
  position_ = { 0.0f, 0.0f };
  normal_texture_id_ = normal.textureID();
  hover_texture_id_ = hover.textureID();
  pressed_texture_id_ = pressed.textureID();
  disabled_texture_id_ = disabled.textureID();
  current_texture_id_ = normal.textureID();
  initialized_ = true;
}




void Button::disable() {
  is_enabled_ = false;
}

void Button::enable() {
  is_enabled_ = true;
}

const bool Button::isClicked() {
  if (Input::IsMouseButtonUp(Input::kMouseButton_Left) && 
      (current_texture_id_ == pressed_texture_id_ ||
       current_texture_id_ == hover_texture_id_)) {
    return true;
  }
  return false;
}

void Button::update() {
  // UPDATE
  if (is_enabled_) {
    current_texture_id_ = normal_texture_id_;
    Vec2 mouse = Input::MousePosition();
    if (mouse.x >= position_.x - size_.x * 0.5f &&
        mouse.x <= position_.x + size_.x * 0.5f &&
        mouse.y >= position_.y - size_.y * 0.5f &&
        mouse.y <= position_.y + size_.y * 0.5f) {
      current_texture_id_ = hover_texture_id_;
      if (Input::IsMouseButtonPressed(Input::kMouseButton_Left)) {
        current_texture_id_ = pressed_texture_id_;
      }
    }
  }
  else {
    current_texture_id_ = disabled_texture_id_;
  }
}

void Button::render() {
  if (initialized_) {
    
    update();

    auto& sprite = Core::instance().sprite_;
    sprite.set_texture_id(current_texture_id_);
    sprite.set_position({ position_.x, position_.y });
    sprite.set_texture_size({ texture_size_.x, texture_size_.y });
    sprite.set_size({ size_.x, size_.y });
    sprite.set_rotation(0.0f);
    sprite.render();
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

const bool Button::is_enabled() {
  return is_enabled_;
}



}; /* W2D */