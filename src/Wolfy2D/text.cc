/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D\text.h"
#include "core/core.h"
#include "core/text.h"

namespace W2D {

Text::Text() {
  size_ = 30.0f;
  position_ = { 0.0f, 0.0f };
  color_ = { 1.0f, 1.0f, 1.0f, 1.0f };
}

Text::~Text() {}

Text& Text::operator=(const Text& other) {
  size_ = other.size_;
  position_ = other.position_;
  color_ = other.color_;
  return *this;
}

Text::Text(const Text& other) {
  size_ = other.size_;
  position_ = other.position_;
  color_ = other.color_;
}

void Text::set_position(const glm::vec2 position) {
  position_ = position;
}

void Text::set_size(const float size) {
  size_ = size;
}

void Text::set_color(const glm::vec4 color_rgba) {
  color_ = color_rgba;
}

void Text::render(const char * text_to_render) {
  auto& text = Core::instance().text_;
  text.set_color(color_);
  text.set_position(position_);
  text.set_size(size_);
  text.render(text_to_render);
}




}; /* W2D */