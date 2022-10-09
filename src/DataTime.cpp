#include "../include/DataTime.hpp"

#include <stdio.h>

#include <ctime>

static DataTime ToDataTime(time_t time);
static time_t DeltaSeconds(char* time_delta);

// DataTime After(DataTime time, char* time_delta_string) {
//   DataTime new_time = time;
//   DataTime time_delta= {0};
//   strftime(time_delta_string, 26, "%Y-%m-%d %H:%M:%S", &time_delta);

//   new_time.tm_mday += time_delta.tm_mday;
//   new_time.tm_hour += time_delta.tm_hour;
//   new_time.tm_min += time_delta.tm_min;
//   new_time.tm_sec += time_delta.tm_sec;

//   mktime(&new_time);
//   return new_time;
// }

// DataTime Before(DataTime time, char* time_delta_string) {
//   DataTime time_delta = {0};
//   strftime(time_delta_string, 26, "%Y-%m-%d %H:%M:%S", &time_delta);
//   mktime(&time_delta);

//   time.tm_mday -= time_delta.tm_mday;
//   time.tm_hour -= time_delta.tm_hour;
//   time.tm_min -= time_delta.tm_min;
//   time.tm_sec -= time_delta.tm_sec;

//   mktime(&time);
//   return time;
// }


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

  unix_time -= delta;
  // if (delta > unix_time) {
  //   unix_time = 0;
  // } else {
  //   unix_time -= delta;
  // }

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
