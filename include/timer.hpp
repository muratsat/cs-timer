#include <time.h>

#include <ctime>

#include "DataTime.hpp"

typedef struct tm DataTime;

class Timer {
 private:
  long long dd_ = 0;
  int hh_ = 0;
  int min_ = 0;
  int sec_ = 0;
  int nano_ = 0;

  clock_t start_time_ = 0;
  clock_t end_time_ = 0;
  timespec *mt;

  void Normalize();

 public:
  Timer() {}
  Timer(long long dd, int hh, int min, int sec, int nano)
      : dd_(dd), hh_(hh), min_(min), sec_(sec), nano_(nano) {
  }
  ~Timer() {
  }

  void AddTimer(const Timer& timer);

  void MinusTimer(const Timer& timer);

  void PlusTimer(DataTime data_time);

  void Start();

  void Stop();

  void Show();
};
