#include <ctime>
#include <iostream>

#include "../../include/timer.h"
#include "../../include/timer.hpp"

int main(int argc, char* argv[]) {
  DataTime time = getTime(argv[1]);
  char buff[26];
  strftime(buff, 26, "%Y-%m-%d %H:%M:%S", &time);
  printf("%s\n", buff);


  return 0;
}