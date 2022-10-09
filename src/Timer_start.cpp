#include "../include/timer.hpp"
#include <iostream>

void Timer::Start() {
  clock_gettime(CLOCK_REALTIME, mt);
}

void Timer::Stop() {
  struct timespec mt2; 
  clock_gettime (CLOCK_REALTIME, &mt2); 
  long long delta; 
  delta = 1000000000*(mt2.tv_sec - mt->tv_sec)+(mt2.tv_nsec - mt->tv_nsec); 
  printf("Time used: %lld ns\n", delta); 
}