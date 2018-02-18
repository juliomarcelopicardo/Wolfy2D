/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#include <stdio.h>
#include <string.h>
#define FONTSTASH_IMPLEMENTATION
#include "FONTSTASH/fontstash.h"
#include "GL/glew.h"
#include <GLFW/glfw3.h>
#define GLFONTSTASH_IMPLEMENTATION
#include "FONTSTASH/glfontstash.h"
#include "core/txt.h"
#include "core/core.h"
#include <string>
#include <map>
#include <vector>



namespace W2D {

  

  /**************************************************************************
  ***                              TEXT CLASS                             ***
  **************************************************************************/

  Txt::Txt() {
    position_ = { 0.0f, 0.0f };
    color_ = { 1.0f, 1.0f, 1.0f, 1.0f };
    regular_ = FONS_INVALID;
    font_ = nullptr;
    size_ = 30.0f;

  }

  Txt::~Txt() {
    release_font();
  }



  /**************************************************************************
  ***                              INITIALIZE                             ***
  **************************************************************************/
  void Txt::init(const char* path) {

    release_font();

    //Esta variable que voy a inicializar es como el libro donde yo voy a 
    //guardar las tipograf�as de la familia que yo he nombrado por par�metros.
    font_ = glfonsCreate(512, 512, FONS_ZERO_TOPLEFT);
    if (font_ == NULL) {
      std::string log_error(" ERROR: Couldn't create a face for the font: \"");
      log_error = log_error + path + "\"";
      printf("\n %s", log_error.c_str());
      exit(EXIT_FAILURE);
    }

    //Una vez que he creado el libro, lo que hago es ir creando "handler" a
    //las distintas p�ginas en las que he ido insertando las distintas fuentes.
    //Tenemos tres fuentes: "regular" (default), "italic" y "bold".
    regular_ = fonsAddFont(font_, "DigitFont", path);
    if (regular_ == FONS_INVALID) {
      std::string log_error(" ERROR: Couldn't initialize the regular of the font: \"");
      log_error = log_error + path + "\"";
      printf("\n %s", log_error.c_str());
      exit(EXIT_FAILURE);
    }
  }

  void Txt::release_font() {
    //Eliminamos el libro de fuentes de la familia:
    if (font_) {
      glfonsDelete(font_);
      font_ = nullptr;
    }
  }


  /**************************************************************************
  ***                               SETTERS                               ***
  **************************************************************************/

  void Txt::set_position(const glm::vec2 position) {
    position_ = position;
  }

  void Txt::set_size(const float size) {
    if (size >= 1.0f) {
      size_ = size;
    }
    else {
      size_ = 1.0f;
    }
  }

  void Txt::set_color(const glm::vec4 color) {
    color_ = color;
  }


  /**************************************************************************
  ***                               RENDER                                ***
  **************************************************************************/
  void Txt::render(const char* text) {
    glm::i32vec2 window_size = { Core::instance().window_.width_, Core::instance().window_.height_ };

    if (font_) {
      glViewport(0, 0, window_size.x, window_size.y);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glDisable(GL_TEXTURE_2D);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(0.0f, window_size.x, window_size.y, 0.0f, -1, 1);

      fonsClearState(font_);
      uint32 color = glfonsRGBA((uint32)(color_.x * 255.0f), (uint32)(color_.y * 255.0f),
                                (uint32)(color_.z * 255.0f), (uint32)(color_.w * 255.0f));

      fonsSetSize(font_, size_);
      fonsSetFont(font_, regular_);
      fonsSetColor(font_, color);
      fonsSetAlign(font_, FONS_ALIGN_TOP | FONS_ALIGN_LEFT);
      fonsDrawText(font_, position_.x, position_.y, text, NULL);
    }
    else {
      // ERROR FOR THE USER... TO HELP HIM.
      printf(" ERROR: Set a font for the texts..."
             " Use Text::SetFont(\"MyFontName.ttf\"); function.\n");
    }
  }


};/* W2D */