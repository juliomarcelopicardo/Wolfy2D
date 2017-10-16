/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#ifndef __CORE_GEOMETRY_H__
#define __CORE_GEOMETRY_H__ 1

#include "Wolfy2D.h"

namespace W2D {


class CoreGeometry {
 public:

/*******************************************************************************
***                        Constructor and destructor                        ***
*******************************************************************************/
  CoreGeometry();
  ~CoreGeometry();

/*******************************************************************************
***                            Geometry methods                              ***
*******************************************************************************/

  ///--------------------------------------------------------------------------
  /// @fn   init();
  ///
  /// @brief  Initializes the quad geometry which will be used for the sprites.
  ///--------------------------------------------------------------------------
  void init();
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
 
  CoreGeometry(const CoreGeometry& copy);
  CoreGeometry& operator=(const CoreGeometry& copy);

};

};/* W2D */

#endif
