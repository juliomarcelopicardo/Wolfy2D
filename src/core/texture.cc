/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "core/texture.h"
#include "core/material.h"
#include "core/core.h"
#include "STB/stb_image.h"


namespace W2D {

Texture::Texture() {
  texture_id_ = 0;
}

Texture::~Texture() {}

Texture::Texture(const Texture & copy) {
  texture_id_ = copy.texture_id_;
}

Texture & Texture::operator=(const Texture & copy) {
  texture_id_ = copy.texture_id_;
  return *this;
}


/******************************************************************************
***                                  INIT                                   ***
******************************************************************************/
void Texture::init(const char* texture_path) {

  //Loading the image, we have to do this before generate the identifier:
  int32 channels = 0;

  //stbi_set_flip_vertically_on_load(true);
  int32 width, height;
  unsigned char* tmp_texture = stbi_load(texture_path, &width, &height, &channels, STBI_rgb_alpha);
  if (tmp_texture) {

    //We can blend the texture to refuse to show the alpha channel.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Once we have loaded the texture, we create the handler and we bind it:
    texture_id_ = 0;
    glGenTextures(1, &texture_id_);
    glBindTexture(GL_TEXTURE_2D, texture_id_);

    // Repeat or clamp to edge work.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //The "internalformat" -third parameter- means the format that OpenGL 
    //should use to store the data internally, this is the format of 
    //the texture. Is different of the "format" -7th parameter-, a parameter
    //which combined with the type defines the layout of the data that 
    //we pass to OpenGL in the last parameter.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
      GL_UNSIGNED_BYTE, tmp_texture);

    //Unbind the texture.
    glBindTexture(GL_TEXTURE_2D, 0); 
    
    //Releasing the image data:
    stbi_image_free(tmp_texture);
  }
  else {
    std::string error(" WARNING: Loading Texture, file \"");
    error += texture_path;
    error += "\" doesn't exists.";
    printf("\n %s", error.c_str());
    //exit(EXIT_FAILURE);
    texture_id_ = Core::instance().error_texture_.textureID();
  }

}



void Texture::set_texture_id(const uint32 texture_id) {
  texture_id_ = texture_id;
}


uint32 Texture::textureID() const {
  return texture_id_;
}

void Texture::releaseTexture() const {
  if (glIsTexture(texture_id_)) {
    glDeleteTextures(1, &texture_id_);
  }
}



}; /* W2D */