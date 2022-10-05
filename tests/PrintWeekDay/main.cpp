#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

#include "../../include/timer.h"
#include "../../include/timer.hpp"

DataTime getTime(char* time_string) { 
  DataTime t; 
  strptime(time_string, "%y-%m-%d %H:%M:%S", &t); 
  mktime(&t);
  return t; 
}

int main(int argc, char* argv[]) {
  std::string week_days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

  DataTime time = getTime(argv[1]);
  // printf("%s\n", asctime(&time));

  PrintWeekDay(time);

  return 0;
}