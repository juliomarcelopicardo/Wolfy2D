/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_GLOBALS_H__
#define __WOLFY2D_GLOBALS_H__ 1

#include <stdint.h>

namespace W2D {

  /*******************************************************************************
  ***                                 TYPES                                    ***
  *******************************************************************************/

  /// char
  typedef char char8;
  typedef char16_t char16;
  typedef char32_t char32;

  /// unsigned char
  typedef unsigned char uchar8;

  /// integer
  typedef int8_t int8;
  typedef int16_t int16;
  typedef int32_t int32;
  typedef int64_t int64;

  /// unsigned integer
  typedef uint8_t uint8;
  typedef uint16_t uint16;
  typedef uint32_t uint32;
  typedef uint64_t uint64;

  /// precision
  typedef float float32;
  typedef double float64;

  /// Vectors
  typedef struct {
    float32 x;
    float32 y;
  }Vec2;

  typedef struct {
    float32 x;
    float32 y;
    float32 z;
  }Vec3;

  typedef struct {
    float32 x;
    float32 y;
    float32 z;
    float32 w;
  }Vec4;

  // MAIN DECLARATION
  int32 main();

}; /* W2D */

#endif
