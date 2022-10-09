#include "../include/timer.hpp"

void Timer::MinusTimer(const Timer& timer) {
  nano_ -= timer.nano_;
  sec_ -= timer.sec_;
  min_ -= timer.min_;
  hh_ -= timer.hh_;
  dd_ -= timer.dd_;
  if (nano_ < 0) {
    sec_ -= 1;
    nano_ += 1000000000;
  }
  if (sec_ < 0) {
    min_ -= 1;
    sec_ += 60;
  }
  if (min_ < 0) {
    hh_ -= 1;
    min_ += 60;
  }
  if (hh_ < 0) {
    dd_ -= 1;
    hh_ += 24;
  }
}
