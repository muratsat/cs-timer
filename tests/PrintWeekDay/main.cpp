#include <stdio.h>
#include <time.h>

#include <iostream>
#include <string>

#include "../../include/DataTime.hpp"

int main(int argc, char* argv[]) {
  std::string week_days[] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                             "Friday", "Saturday", "Sunday"};

  DataTime time = GetTime(argv[1]);

  PrintWeekDay(time);

  return 0;
}