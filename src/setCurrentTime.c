#include <time.h>

#include "../include/timer.h"

DataTime setCurrentTime() {
  return *localtime(NULL);
}
