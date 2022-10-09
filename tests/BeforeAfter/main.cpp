#include <ctime>
#include <iostream>

#include "../../include/DataTime.hpp"


// argv[1]: time string (YY-MM-DD HH:MIN:SEC)
// argv[2]: time delta (DD HH:MIN:SEC)

int main(int argc, char* argv[]) {
  DataTime t = GetTime(argv[1]);
  char* time_delta = argv[2];

  DataTime t1 = Before(t, time_delta);
  DataTime t2 = After(t, time_delta);

  char buff1[26];
  char buff2[26];
  strftime(buff1, 26, "%Y-%m-%d %H:%M:%S", &t1);
  strftime(buff2, 26, "%Y-%m-%d %H:%M:%S", &t2);

  printf("%s %s\n", buff1, buff2);

  return 0;
}