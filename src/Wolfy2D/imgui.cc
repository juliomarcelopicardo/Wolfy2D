/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#include "Wolfy2D/imgui.h"
#include "core/imgui_class.h"

namespace W2D {
namespace ImGuiEditor {

  void SetupSprite(Sprite& sprite, const char* sprite_name) {
    glm::vec2 position = sprite.position();
    glm::vec2 size = sprite.size();
  float rotation = sprite.rotation();
  
  ImGui::PushID(&sprite);
  if (ImGui::TreeNode(sprite_name)) {
    ImGui::DragFloat2(" Position", &position.x);
    ImGui::DragFloat2(" Size", &size.x);
    ImGui::DragFloat(" Rotation", &rotation);
    ImGui::TreePop();
  }
  ImGui::PopID();

  sprite.set_position(position);
  sprite.set_rotation(rotation);
  sprite.set_size(size);

}

}/* ImGui */
}; /* W2D */