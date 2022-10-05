#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

#include "../../include/timer.h"
#include "../../include/timer.hpp"

int main() {
  std::string week_days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

  DataTime time_now = setCurrentTime();
  char buffer[80];
  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &time_now);
  std::string str(buffer);
  std::cout << str << '\n';

  // char wday = PrintWeekDay(time_now);
  // std::cout << 

  return 0;
}