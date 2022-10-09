#include <ctime>
#include <iostream>

#include "../../include/DataTime.hpp"

int main(int argc, char* argv[]) {
  DataTime time = GetTime(argv[1]);
  char buff[26];
  strftime(buff, 26, "%Y-%m-%d %H:%M:%S", &time);
  printf("%s\n", buff);

  return 0;
}