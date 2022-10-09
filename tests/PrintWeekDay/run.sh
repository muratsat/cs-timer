#!/bin/bash

# Console colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# path to the main.cpp where
# executable will be located
test_dir=$(dirname $0)

# Compilation of source files
# to test executable
if ! g++ $test_dir/main.cpp src/PrintWeekDay.cpp src/GetTime.cpp -o $test_dir/main
then
  echo "Compilation failed"
  exit 1
fi

dates=(
  "2022-09-19 12:00:00"
  "2022-09-20 12:00:00"
  "2022-09-21 12:00:00"
  "2022-09-22 12:00:00"
  "2022-09-23 12:00:00"
  "2022-09-24 12:00:00"
  "2022-09-25 12:00:00"
)

# successful tests counter
passed=0
total=0

for test_date in "${dates[@]}"; do
  correct=$(date -d "$test_date" +%u)
  output=$($test_dir/main "$test_date")

  if [ "$output" == "$correct" ]; then
    passed=$((passed+1))
  fi
  total=$((total+1))
done

echo "Passed $passed out of $total tests"
if [ "$passed" == "$total" ]; then
  exit 0
else
  exit 1
fi