/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "STB/stb_image.h"
#include "core/frame_buffer.h"
#include "core\core.h"

namespace W2D {

  FrameBuffer::FrameBuffer() {
    texture_ = 0;
    frame_buffer_ = 0;
  }

  FrameBuffer::~FrameBuffer() {
    if (glIsTexture(texture_)) {
      glDeleteTextures(1, &texture_);
    }
    if (glIsFramebuffer(frame_buffer_)) {
      glDeleteFramebuffers(1, &frame_buffer_);
    }
  }



  void FrameBuffer::init() {

    auto& window = Core::instance().window_;


    glEnable(GL_DEPTH_TEST);

    //1st: Preparamos la textura de color:
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);
    //El cuarto y quinto par�metros han de ser el ancho y alto de la ventana,
    //accesibles desde el singleton, y el tercer y s�ptimo pueden ser GL_RGB.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, window.width_, window.height_,
      0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    //2nd: texture settings:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //3rd: Desbindeamos la textura.
    glBindTexture(GL_TEXTURE_2D, 0);

    // Luego inicializo el framebuffer
    glGenFramebuffers(1, &frame_buffer_);
    glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer_);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);


    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
      exit(EXIT_FAILURE);
    }

  }

  void FrameBuffer::begin() {
    auto& window = Core::instance().window_;
    //Defino el viewport con el tama�o de la window:

    glViewport(0, 0, window.width_, window.height_);
    glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer_);

    //Ahora mismo, en este punto, no estamos empleando buffer de stencil:
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  unsigned int FrameBuffer::texture() const {
    return texture_;
  }


  /*******************************************************************************
  ***                            Depth & Shadows                               ***
  *******************************************************************************/

  void FrameBuffer::close() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
  }

  /*******************************************************************************
  ***                            Error checkings                               ***
  *******************************************************************************/




}; /* W2D */