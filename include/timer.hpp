#include <time.h>

typedef struct tm DataTime;

class Timer {
 private:
  long long dd_;
  int hh_;
  int min_;
  int sec_;
  int nano_;

 public:
  Timer(long long dd, int hh, int min, int sec, int nano):
    dd_(dd), hh_(hh), min_(min), sec_(sec), nano_(nano) {}
  ~Timer();

  void AddTimer(const Timer& timer);

  void Show() const;

};

char PrintWeekDay(DataTime t);
