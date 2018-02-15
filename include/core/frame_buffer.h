/** Copyright Julio Marcelo Picardo. 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/


#ifndef __FRAME_BUFFER_H__
#define __FRAME_BUFFER_H__ 1

#include "GLM/glm.hpp"
#include "Wolfy2D.h"


namespace W2D {

  class FrameBuffer {
  public:
    struct Data;

    FrameBuffer();
    ~FrameBuffer();

    void init();
    void begin();
    void close();

    unsigned int texture() const;

  private:

    uint32 texture_;
    uint32 frame_buffer_;

    FrameBuffer(const FrameBuffer& copy);
    FrameBuffer& operator=(const FrameBuffer& copy);
  };
};
#endif