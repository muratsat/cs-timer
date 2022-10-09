#include "../include/timer.hpp"

void Timer::PlusTimer(DataTime data_time) {
  sec_ += data_time.tm_sec;
  min_ += data_time.tm_min;
  hh_ += data_time.tm_hour;
  dd_ += data_time.tm_mday;

  Normalize();
}