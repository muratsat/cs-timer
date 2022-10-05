
#!/bin/bash

test_dir=$(dirname $0)

g++ $test_dir/main.cpp src/PrintWeekDay.cpp src/setCurrentTime.cpp -o $test_dir/main

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

dates=(
  "2022-09-19 12:00:00"
  "2022-09-20 12:00:00"
  "2022-09-21 12:00:00"
  "2022-09-22 12:00:00"
  "2022-09-23 12:00:00"
  "2022-09-24 12:00:00"
  "2022-09-25 12:00:00"
)

passed=0
total=0

for test_date in "${dates[@]}"; do
  correct=$(date -d "$test_date" +%u)
  output=$($test_dir/main "$test_date")

  if [ "$output" == "$correct" ]; then
    printf "${GREEN}passed $test_date $NC\n"
    passed=$((passed+1))
  else
    printf "${RED}failed $test_date $NC\n"
    printf "Expected: $correct\n"
    printf "Got: $output\n"
    # exit 1
  fi
  total=$((total+1))
done

echo "Passed $passed out of $total tests"
if [ "$passed" == "$total" ]; then
  exit 0
else
  exit 1
fi