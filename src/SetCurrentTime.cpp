#include <time.h>

#include "../include/timer.hpp"

DataTime setCurrentTime() {
  time_t time_now;
  time(&time_now);
  return *localtime(&time_now);
}
