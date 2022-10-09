#include <ctime>

#include "../include/DataTime.hpp"

DataTime SetCurrentTime() {
  time_t time_now;
  time(&time_now);
  DataTime time = *localtime(&time_now);
  mktime(&time);
  return time;
}
