#include <iostream>
#include <time.h>

typedef struct tm DataTime;

DataTime setCurrentTime();

DataTime GetTime(char * time_string);

char PrintWeekDay(DataTime t);