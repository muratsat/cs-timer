#include <stdio.h>

#include <ctime>

#include "../include/DataTime.hpp"

DataTime GetTime(char* time_string) {
  int y, m, d, hh, mm, ss;
  sscanf(time_string, "%d-%d-%d %d:%d:%d", &y, &m, &d, &hh, &mm, &ss);

  DataTime t = {0};
  t.tm_year = y - 1900;
  t.tm_mon = m - 1;
  t.tm_mday = d;

  t.tm_hour = hh;
  t.tm_min = mm;
  t.tm_sec = ss;

  mktime(&t);
  return t;
}
