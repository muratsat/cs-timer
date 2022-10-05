#include <time.h>

#include "../include/DataTime.hpp"

DataTime getTime(char* time_string) { 
  DataTime t; 
  strptime(time_string, "%y-%m-%d %H:%M:%S", &t); 
  mktime(&t);
  return t; 
}
