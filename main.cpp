#include <stdio.h>

#include "include/timer.hpp"

int main() {
  Timer timer;
  timer.Start();

  for (int i = 0; i < 1e9; i++) {

  }

  timer.Stop();

  timer.Show();

  return 0;
}
