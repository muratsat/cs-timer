
#!/bin/bash

test_dir=$(dirname $0)

g++ $test_dir/main.cpp src/PrintWeekDay.cpp src/setCurrentTime.cpp -o $test_dir/main

correct=$(date +"%A")
output=$($test_dir/main)

if [ "$output" == "$correct" ]; then
  exit 0
else
  echo "failed"
  printf "Expected:\n$correct\n"
  printf "Got:\n$output\n"
  exit 1
fi