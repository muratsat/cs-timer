#include <stdio.h>

#include "../include/timer.hpp"

char PrintWeekDay(DataTime t) {
  char week_day = (t.tm_wday + 1) % 7;
  printf("%d\n", week_day);
  return week_day;
}
