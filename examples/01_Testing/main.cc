/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

 
#include <string>
#include "Wolfy2D.h"

namespace W2D {
  int32 main() {

    Window::Init(1024, 978);

    Sprite cat, mario;
    Text green_text, text;
    Sprite walk[4];
    walk[0].init("./../data/right1.png");
    walk[1].init("./../data/right2.png");
    walk[2].init("./../data/right3.png");
    walk[3] = walk[1];
    Animation animation;
    animation.init(walk, 4);
    animation.set_position({ 500.0f, 200.0f });
    animation.set_size({ 50.0f, 50.0f });
    animation.set_speed(100);

    Text::SetFont("./../data/DigitFont.ttf");
    cat.init("./../data/texture.png");
    mario.init("./../data/mario.png");
    green_text.set_color({ 0.0f, 1.0f, 0.0f, 1.0f });
    text.set_position({ 200.0f, 200.0f });
    text.set_size(50);
    cat.set_position({ 300.0f, 300.0f });
    mario.set_size({250, 250});
    mario.set_rotation(0.3f);
    mario.set_position({ 555, 444 });
    

  while (Window::IsOpened()) {
    Window::Clear();
    ImGuiEditor::SetupSprite(mario, "SuperMario");
    ImGuiEditor::SetupText(text, "PACO");
        cat.render();    mario.render();    mario.set_rotation(Time() * 0.001f);    text.render("PAQUITORRR");    green_text.render("PAAAAAAAAAAAAAAAACO");        if (Input::IsKeyboardButtonDown(Input::kKeyboardButton_W)) {      printf("\n W down");    }    if (Input::IsKeyboardButtonPressed(Input::kKeyboardButton_S)) {      printf("\n S pressed");    }    if (Input::IsKeyboardButtonUp(Input::kKeyboardButton_D)) {      printf("\n D up");    }    if (Input::IsMouseButtonDown(Input::kMouseButton_Left)) {      printf("\n Left down");    }    if (Input::IsMouseButtonPressed(Input::kMouseButton_Middle)) {      printf("\n Middle pressed");    }    if (Input::IsMouseButtonUp(Input::kMouseButton_Right)) {      printf("\n Right up");    }    Draw::Line({ 0.0f, 0.0f }, { 1020, 970 });    animation.render();    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
