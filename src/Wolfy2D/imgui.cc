/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/imgui.h"
#include "core/imgui_class.h"

namespace W2D {
namespace ImGuiEditor {

void SetupSprite(Sprite& sprite, const char* display_name) {
  Vec2 position = sprite.position();
  Vec2 size = sprite.size();
  float rotation = sprite.rotation();
  
  ImGui::PushID(&sprite);
  if (ImGui::TreeNode(display_name)) {
    ImGui::DragFloat2(" Position", &position.x);
    ImGui::DragFloat2(" Size", &size.x);
    ImGui::SliderAngle(" Rotation", &rotation);
    ImGui::TreePop();
  }
  ImGui::PopID();

  sprite.set_position(position);
  sprite.set_rotation(rotation);
  sprite.set_size(size);
}

void SetupText(Text & text, const char * display_name) {
  Vec2 position = text.position();
  float size = text.size();
  Vec4 color = text.color();

  ImGui::PushID(&text);
  if (ImGui::TreeNode(display_name)) {
    ImGui::DragFloat2(" Position", &position.x);
    ImGui::DragFloat(" Size", &size, 1.0f, 10.0f, 70.0f);
    ImGui::ColorEdit4(" Color", &color.x);
    ImGui::TreePop();
  }
  ImGui::PopID();

  text.set_position(position);
  text.set_color(color);
  text.set_size(size);
}

void SetupButton(Button& button, const char * display_name) {
  Vec2 position = button.position();
  Vec2 size = button.size();

  ImGui::PushID(&button);
  if (ImGui::TreeNode(display_name)) {
    ImGui::DragFloat2(" Position", &position.x);
    ImGui::DragFloat2(" Size", &size.x);
    if (button.is_enabled()) {
      if (ImGui::Button("DISABLE")) { button.disable(); }
    }
    else {
      if (ImGui::Button("ENABLE")) { button.enable(); }
    }
    ImGui::TreePop();
  }
  ImGui::PopID();

  button.set_position(position);
  button.set_size(size);
}


void SetupAnimation(Animation& animation, const char* display_name) {
  Vec2 position = animation.position();
  Vec2 size = animation.size();
  float rotation = animation.rotation();
  int32 ms = (int32)animation.speed();

  ImGui::PushID(&animation);
  if (ImGui::TreeNode(display_name)) {
    ImGui::DragFloat2(" Position", &position.x);
    ImGui::DragFloat2(" Size", &size.x);
    ImGui::SliderAngle(" Rotation", &rotation);
    ImGui::DragInt(" Speed - MS per change", &ms, 10.0f, 10, 1000);
    ImGui::TreePop();
  }
  ImGui::PopID();

  animation.set_position(position);
  animation.set_size(size);
  animation.set_rotation(rotation);
  animation.set_speed((uint64)ms);
}


}/* ImGui */
}; /* W2D */