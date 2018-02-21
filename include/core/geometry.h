/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#ifndef __CORE_GEOMETRY_H__
#define __CORE_GEOMETRY_H__ 1

#include "Wolfy2D.h"

namespace W2D {

/// Quad geometry class used to renderize sprites.
class Geometry {
 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  /// Default class constructor.
  Geometry();
  /// Default class destructor.
  ~Geometry();

/*******************************************************************************
***                            Geometry methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init();
  ///
  /// @brief  Initializes the quad geometry which will be used for the sprites.
  ///--------------------------------------------------------------------------
  void init();

  ///--------------------------------------------------------------------------
  /// @fn   render();
  ///
  /// @brief  Renders the quad geometry which will be used for the sprites.
  ///--------------------------------------------------------------------------
  void render();

/*******************************************************************************
***                          	Public attributes                              ***
*******************************************************************************/
  /// Vertices Position buffer
  uint32 position_buffer_;
  /// Vertices uv buffer
  uint32 uv_buffer_;
  /// Number of vertices of the geometry
  uint32 num_vertices_;
  /// Vertices VAO
  uint32 vertices_id_[2];

/*******************************************************************************
***                          Private attributes                              ***
*******************************************************************************/
 private:
 
  /// Copy constructor
  Geometry(const Geometry& copy);
  /// Assignment operator.
  Geometry& operator=(const Geometry& copy);

};

};/* W2D */

#endif
