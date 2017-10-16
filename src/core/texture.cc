/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "core/texture.h"
#include "core/core.h"
#include <stdio.h>
#include <string>
#include "STB/stb_image.h"

namespace W2D {

/*******************************************************************************
***                     Global methods for gpu commands                      ***
*******************************************************************************/


/*******************************************************************************
***                              TEXTURE CLASS                               ***
*******************************************************************************/

CoreTexture::CoreTexture() {
  width_ = 0;
  height_ = 0;
  texture_id_ = 0;
  wrap_mode_ = kTextureWrap_Repeat;
}

CoreTexture::~CoreTexture() {
  if (glIsTexture(texture_id_)) {
    glDeleteTextures(1, &texture_id_);
  }
}

void CoreTexture::init(const char* path, const TextureWrap wrap_mode) {

  //Loading the image, we have to do this before generate the identifier:
  int32 channels = 0;

  stbi_set_flip_vertically_on_load(true);
  unsigned char* tmp_texture = stbi_load(path, &width_, &height_, &channels, 
                                          STBI_rgb_alpha);
  if (tmp_texture) {

    //We can blend the texture to refuse to show the alpha channel.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Once we have loaded the texture, we create the handler and we bind it:
    texture_id_ = 0;
    glGenTextures(1, &texture_id_);
    glBindTexture(GL_TEXTURE_2D, texture_id_);
    wrap_mode_ = wrap_mode;

    set_info();

    //The "internalformat" -third parameter- means the format that OpenGL 
    //should use to store the data internally, this is the format of 
    //the texture. Is different of the "format" -7th parameter-, a parameter
    //which combined with the type defines the layout of the data that 
    //we pass to OpenGL in the last parameter.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, tmp_texture);
    glBindTexture(GL_TEXTURE_2D, 0); //Unbind the texture.
    //Releasing the image data:
    stbi_image_free(tmp_texture);

  }
  else {
    std::string error(" ERROR: Texture incorrect, file \"");
    error += path;
    error += "\" doesn't exists.";
    printf("\n %s", error.c_str());
    exit(EXIT_FAILURE);
  }


}





void CoreTexture::enable(const uint32 program_id, const char* text_name, const uint32 texture_slot) {

    glActiveTexture(GL_TEXTURE0 + texture_slot);
    glBindTexture(GL_TEXTURE_2D, texture_id_);
    glUniform1i(glGetUniformLocation(program_id, text_name), texture_slot);

}

void CoreTexture::enable(const uint32 uniform_location, const uint32 texture_slot) {
    glActiveTexture(GL_TEXTURE0 + texture_slot);
    glBindTexture(GL_TEXTURE_2D, texture_id_);
    glUniform1i(uniform_location, texture_slot);
}

void CoreTexture::set_info() {
  switch (wrap_mode_) {
  case kTextureWrap_Repeat:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    break;
  case kTextureWrap_MirrorRepeat:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    break;
  case kTextureWrap_ClampToEdge:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    break;
  case kTextureWrap_ClampToBorder:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    break;
  }
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void CoreTexture::set_color(const float* color) {
  glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
}


};/* W2D */