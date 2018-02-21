/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D - Including JMP scripting language.
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __WOLFY2D_TIME_H__
#define __WOLFY2D_TIME_H__ 1

#include "Wolfy2D/globals.h"

namespace W2D {

/// Chronometer struct used to calculate time.
struct Chronometer {
  Chronometer() : timer(0),
                  total_average(0),
                  iterations(0) {}
  
  ///--------------------------------------------------------------------------
  /// @fn   uint64 start();
  ///
  /// @brief Starts or actives the time count.
  ///--------------------------------------------------------------------------
  void start();
  ///--------------------------------------------------------------------------
  /// @fn   uint64 end();
  ///
  /// @brief Restarts the time history and average.
  ///--------------------------------------------------------------------------
  void restart();
  ///--------------------------------------------------------------------------
  /// @fn   uint64 end();
  ///
  /// @brief Time duration between last start and now.
  /// @return Miliseconds between a start and an end.
  ///--------------------------------------------------------------------------
  uint64 end();
  ///--------------------------------------------------------------------------
  /// @fn   uint64 aveerage();
  ///
  /// @brief Time average duration between all starts and ends.
  /// @return Miliseconds average.
  ///--------------------------------------------------------------------------
  uint64 average();

  /// Timer to save the actual time.
  uint64 timer;
  /// Total average of times counted.
  uint64 total_average;
  /// Number of times that we have previously calculated.
  uint32 iterations;
};

///--------------------------------------------------------------------------
/// @fn   uint64 Time();
///
/// @brief Actual time of the application in miliseconds .
/// @return Miliseconds time.
///--------------------------------------------------------------------------
uint64 Time();
///--------------------------------------------------------------------------
/// @fn   uint64 TimeInMicroSeconds();
///
/// @brief Actual time of the application in microseconds.
/// @return Microseconds time.
///--------------------------------------------------------------------------
uint64 TimeInMicroSeconds();
///--------------------------------------------------------------------------
/// @fn   Sleep(const uint64 miliseconds);
///
/// @brief Sleeps this thread.
/// @param miliseconds time in miliseconds that the thread will be sleeping.
///--------------------------------------------------------------------------
void Sleep(const uint64 miliseconds);
///--------------------------------------------------------------------------
/// @fn   Sleep(const uint64 seconds);
///
/// @brief Sleeps this thread.
/// @param miliseconds time in seconds that the thread will be sleeping.
///--------------------------------------------------------------------------
void SleepSeconds(const uint64 seconds);

}; /* W2D */

#endif
