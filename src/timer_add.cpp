#include "../include/timer.hpp"

void Timer::AddTimer(const Timer& timer) {
  nano_ += timer.nano_;
  sec_ += timer.sec_;
  min_ += timer.min_;
  hh_ += timer.hh_;
  dd_ += timer.dd_;
  Normalize();
}
