#include <stdio.h>
#include <time.h>

#include "../../include/timer.h"

int main() {
  DataTime dt = setCurrentTime();
  char buff[40] = {};

  strftime(buff, 40, "%Y-%m-%d %H:%M:%S", &dt);

  printf("%s\n", buff);

  return 0;
}