#include <stdio.h>

#include "../include/timer.hpp"

void Timer::Show() {
  printf("%lld %d:%d:%d.%09d\n", dd_, hh_, min_, sec_, nano_);
}
