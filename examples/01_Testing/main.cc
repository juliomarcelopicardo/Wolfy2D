/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

 
#include <string>
#include "Wolfy2D.h"
#include "core\texture.h"
#include "core\sprite.h"

namespace W2D {
  int32 main() {

    Window::Init(1024, 978);

    CoreTexture pepe, mario;
    pepe.init("./../data/texture.png");
    mario.init("./../data/mario.png");
    CoreSprite sprite, sprite2;
    sprite.init(pepe);
    sprite2.init(mario);
    sprite.set_position({ 300.0f, 300.0f });
    sprite2.set_size({250, 250});
    sprite2.set_rotation(0.3f);
    sprite2.set_position({ 555, 444 });

  while (Window::IsOpened()) {
    Window::Clear();
    sprite.render();    sprite2.render();    sprite2.set_rotation(Time() * 0.001f);    if (Input::IsKeyboardButtonDown(Input::kKeyboardButton_W)) {      printf("\n W down");    }    if (Input::IsKeyboardButtonPressed(Input::kKeyboardButton_S)) {      printf("\n S pressed");    }    if (Input::IsKeyboardButtonUp(Input::kKeyboardButton_D)) {      printf("\n D up");    }    if (Input::IsMouseButtonDown(Input::kMouseButton_Left)) {      printf("\n Left down");    }    if (Input::IsMouseButtonPressed(Input::kMouseButton_Middle)) {      printf("\n Middle pressed");    }    if (Input::IsMouseButtonUp(Input::kMouseButton_Right)) {      printf("\n Right up");    }    
    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
