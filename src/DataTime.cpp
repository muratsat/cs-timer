#include "../include/DataTime.hpp"

#include <stdio.h>

#include <ctime>

static DataTime ToDataTime(time_t time);
static time_t DeltaSeconds(char* time_delta);

DataTime After(DataTime time, char* time_delta) {
  time_t unix_time = mktime(&time);
  time_t delta = DeltaSeconds(time_delta);

  unix_time += delta;

  time = ToDataTime(unix_time);
  return time;
}

DataTime Before(DataTime time, char* time_delta) {
  time_t unix_time = mktime(&time);
  time_t delta = DeltaSeconds(time_delta);

  if (delta > unix_time) {
    unix_time = 0;
  } else {
    unix_time -= delta;
  }

  time = ToDataTime(unix_time);
  return time;
}

static const int kSecondsInDay = 60 * 60 * 24;
static const int kSecondsInHour = 60 * 60;
static const int kSecondsInMinute = 60;

static DataTime ToDataTime(time_t time) {
  DataTime t = *localtime(&time);
  mktime(&t);
  return t;
}

static time_t DeltaSeconds(char* time_delta) {
  int d, hh, mm, ss;
  sscanf(time_delta, "%d %d:%d:%d", &d, &hh, &mm, &ss);

  time_t delta = 0;
  delta += d * kSecondsInDay;
  delta += hh * kSecondsInHour;
  delta += mm * kSecondsInMinute;
  delta += ss;

  return delta;
}
