/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "core/geometry.h"
#include "core/core.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>


namespace W2D {

/*******************************************************************************
***                       Constructor and destructor                         ***
*******************************************************************************/

Geometry::Geometry() {
  num_vertices_ = 6;
  uv_buffer_ = 0;
  position_buffer_ = 0;
  vertices_id_[0] = 0;
  vertices_id_[1] = 0;
}

Geometry::~Geometry() {
  if (glIsVertexArray(vertices_id_[0])) {
    glDeleteVertexArrays(2, vertices_id_);
  }
  if (glIsBuffer(position_buffer_)) {
    glDeleteBuffers(1, &position_buffer_);
  }
  if (glIsBuffer(uv_buffer_)) {
    glDeleteBuffers(1, &uv_buffer_);
  }
}


/*******************************************************************************
***                          Predefined Geometries                           ***
*******************************************************************************/

/*********************************************
***                   QUAD                 ***
*********************************************/

void Geometry::init() {

  num_vertices_ = 6;

  glGenVertexArrays(2, vertices_id_);

  // POSICIONES
  glBindVertexArray(vertices_id_[0]);
  glm::vec3 positions[6] = {
    {-0.5f,  0.5f , 0.0f}, // Superior Izquierda
    {-0.5f, -0.5f , 0.0f}, // Inferior Izquierda
    { 0.5f, -0.5f , 0.0f}, // Inferior Derecha
    { 0.5f, -0.5f , 0.0f}, // Inferior Derecha
    { 0.5f,  0.5f , 0.0f}, // Superior Derecha
    {-0.5f,  0.5f , 0.0f}  // Superior Izquierda
  };


  glGenBuffers(1, &position_buffer_);
  glBindBuffer(GL_ARRAY_BUFFER, position_buffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * 6, positions, GL_STATIC_DRAW);

  // UVS
  glBindVertexArray(vertices_id_[2]);
  glm::vec2 uvs[6] = {
    {0.0f, 0.0f},
    {0.0f, 1.0f},
    {1.0f, 1.0f},
    {1.0f, 1.0f},
    {1.0f, 0.0f},
    {0.0f, 0.0f}
  };
  glGenBuffers(1, &uv_buffer_);
  glBindBuffer(GL_ARRAY_BUFFER, uv_buffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 6, uvs, GL_STATIC_DRAW);

    // Para desbindear el ultimo vertex y buffer y array utilizados.
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void Geometry::render() {
  //Posiciones
  glEnableVertexAttribArray(0); // 1.
  glBindBuffer(GL_ARRAY_BUFFER, vertices_id_[0]); // 2. 
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // 3.

  //UV:
  glEnableVertexAttribArray(1); // 1.
  glBindBuffer(GL_ARRAY_BUFFER, vertices_id_[1]); // 2.
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0); // 3.

  glDrawArrays(GL_TRIANGLES, 0, 6);

  glDisableVertexAttribArray(0); //Posiciones
  glDisableVertexAttribArray(1); //UV:

  glBindBuffer(GL_ARRAY_BUFFER, 0); //Unbind buffers.
  glUseProgram(0);
}


};/* W2D */
