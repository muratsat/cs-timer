#include "../include/timer.hpp"

void Timer::Normalize() {
  if (nano_ >= 1000000000) {
    sec_ += nano_ / 1000000000;
    nano_ %= 1000000000;
  }
  if (sec_ >= 60) {
    min_ += sec_ / 60;
    sec_ %= 60;
  }
  if (min_ >= 60) {
    hh_ += min_ / 60;
    min_ %= 60;
  }
  if (hh_ >= 24) {
    dd_ += hh_ / 24;
    hh_ %= 24;
  }
}