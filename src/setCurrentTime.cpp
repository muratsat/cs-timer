#include <time.h>
#include <iostream>

#include "../include/timer.h"

DataTime setCurrentTime() {
  time_t time_now;
  time(&time_now);
  return *localtime(&time_now);
}
