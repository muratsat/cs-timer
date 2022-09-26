#include <time.h>

#include "timer.h"

DataTime setCurrentTime() {
  return *localtime(NULL);
}
