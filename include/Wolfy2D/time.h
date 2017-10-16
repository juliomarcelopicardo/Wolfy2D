/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#ifndef __WOLFY2D_TIME_H__
#define __WOLFY2D_TIME_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

struct Chronometer {
  Chronometer() : timer(0),
                  total_average(0),
                  iterations(0) {}

  void start();
  void restart();
  uint64 end();
  uint64 average();

  uint64 timer;
  uint64 total_average;
  uint32 iterations;
};

/// @brief returns time in milliseconds
uint64 Time();
uint64 TimeInMicroSeconds();
void Sleep(const uint64 miliseconds);
void SleepSeconds(const uint64 seconds);

}; /* W2D */

#endif
