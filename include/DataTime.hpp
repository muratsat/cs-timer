#include <time.h>

typedef struct tm DataTime;

DataTime SetCurrentTime();

DataTime GetTime(char* time_string);

char PrintWeekDay(DataTime t);