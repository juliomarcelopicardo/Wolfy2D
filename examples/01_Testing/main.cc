/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


 
#include <string>
#include "Wolfy2D.h"
#include "chipmunk.h"

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
    Sprite normal, hover, pressed, disabled;
    normal.init("./../data/normal.png");
    hover.init("./../data/hover.png");
    pressed.init("./../data/pressed.png");
    disabled.init("./../data/disabled.png");
    Button button;
    button.init(normal, hover, pressed, disabled);
    button.set_position({ 500.0f, 800.0f });
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
    cat.set_position({ 0.0f, 0.0f });
    mario.set_size({250, 250});
    mario.set_rotation(0.3f);
    mario.set_position({ 555, 444 });

    Vec2 path[5] = { { 100.0f, 100.0f },{ 900.0f, 100.0f },{ 900.0f, 900.0f },
                     { 100.0f, 900.0f },{ 100.0f, 100.0f }};


    Sprite::SetPivot(kSpritePivotPoint_UpLeft);


    /* EJEMPLO */
    cpSpace* world = cpSpaceNew();
    cpSpaceSetGravity(world, { 0, 0.00098 });
    printf("\n Gravity - (%f, %f)", cpSpaceGetGravity(world).x, cpSpaceGetGravity(world).y);

    // Creams un cuerpo en el     mundo,        masa, momento de inercia
    cpBody* body = cpSpaceAddBody(world, cpBodyNew(0, 0));
    cpBody* floor_body = cpSpaceAddBody(world, cpBodyNewStatic());
    cpBodySetPosition(floor_body, { 0, 968 });
    cpBodySetPosition(body, { 0, 0 });

    // Creamos una forma en el       mundo,
    // Parametros de cpboxshape (b,w,h,r) -> body, ancho, alto, radio de erro.
    // CONVIENE NO PONER EL RADIO DE ERROR A 0, recomendable 1 unidad(pixel).
    // La shape o collider se crea en el centro de masas del body.
    // Un body puede tener varias shapes, cada una con su masa.
    cpShape* shape = cpSpaceAddShape(world, cpBoxShapeNew(body, 50, 50, 1));
    cpShape* floor_shape = cpSpaceAddShape(world, cpBoxShapeNew(floor_body, 40, 40, 1));
    cpShapeSetMass(shape, 100);
    printf("\n Masa del box - %f", cpShapeGetMass(shape));

    /* EJEMPLO */

  while (Window::IsOpened()) {
    Window::Clear();
    ImGuiEditor::SetupSprite(mario, "SuperMario");
    ImGuiEditor::SetupText(text, "PACO");
    ImGuiEditor::SetupButton(button, "Button");
        cat.render();    mario.render();    mario.set_rotation(Time() * 0.001f);    text.render("PAQUITORRR");    green_text.render("PAAAAAAAAAAAAAAAACO");    button.render();    if (button.isClicked()) {      printf(" Button clicked\n");    }        Draw::Rect({ 400, 400 }, { 200, 100 });    Draw::Line({ 0.0f, 0.0f }, { 1020, 970 });    animation.render();    Draw::Path(path, 5, { 1.0f, 1.0f, 0.0f, 1.0f }, 2.0f);    cpSpaceStep(world, 16.6);
    cat.set_position({ (float)cpBodyGetPosition(body).x, (float)cpBodyGetPosition(body).y});    Window::Frame();
  }

  Window::Close();

  return 0;
}

}; /* W2D */
