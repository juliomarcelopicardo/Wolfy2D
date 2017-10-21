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

}/* ImGui */
}; /* W2D */