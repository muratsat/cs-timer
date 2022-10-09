#include <ctime>
#include <iostream>

#include "../../include/DataTime.hpp"
// #include "../../include/timer.hpp"

int main() {
  DataTime dt = SetCurrentTime();
  char buff[40] = {};

  strftime(buff, 40, "%Y-%m-%d %H:%M:%S", &dt);

  printf("%s\n", buff);

  return 0;
}