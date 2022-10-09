#include <ctime>

#include "../include/DataTime.hpp"

DataTime SetCurrentTime() {
  time_t time_now;
  time(&time_now);
  return *localtime(&time_now);
}
