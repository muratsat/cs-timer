#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../../include/timer.h"


int main(int argc, char const *argv[]) {
  char date[20];
  strcpy(date, argv[1]);
  
  DataTime date_time = getTime(date);

  char weekday = printWeekDay(date_time);

  const char *weekdays[] = {"Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday", "Sunday"};

  printf("%s\n", weekdays[weekday - 1]);

  return 0;
}
