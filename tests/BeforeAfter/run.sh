#!/bin/bash
# Console colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

test_dir=$(dirname $0)

if ! g++ $test_dir/main.cpp src/*.cpp -o $test_dir/main
then
  echo "Compilation failed"
  exit 1
fi

dates=(
  "September 24, 2003"
  "January 1, 1900"
  "March 29, 2004"
  "May 17, 2006"
  "June 20, 2003"
  "September 21, 2020"
  "September 19, 2022"
)

# successful tests counter
passed=0
total=0

dd=$(( $RANDOM % 10 + 1 ))
hh=$(( $RANDOM % 24 ))
mm=$(( $RANDOM % 60 ))
ss=$(( $RANDOM % 60 ))

echo "Random delta: $dd days $hh:$mm:$ss"

for test_date in "${dates[@]}"; do

  # after=$(date --date "${test_date} +$dd days +$hh hours +$mm minutes +$ss seconds" +"%Y-%m-%d %H:%M:%S")
  after=$(date -d "${test_date} +$dd days +$hh hours +$mm minutes +$ss seconds" +"%Y-%m-%d %H:%M:%S")
  before=$(date -d "${test_date} -$dd days -$hh hours -$mm minutes -$ss seconds" +"%Y-%m-%d %H:%M:%S")

  correct="$before $after"

  test_date=$(date -d "$test_date" +"%Y-%m-%d %H:%M:%S")
  output=$($test_dir/main "$test_date" "$dd $hh:$mm:$ss")

  if [ "$output" == "$correct" ]; then
    passed=$((passed+1))
  else 
    printf "${RED}Failed${NC}\n"
    echo "Test: ($test_date)  ($dd $hh:$mm:$ss)"
    printf "Expected:\n$correct\n"
    printf "Got:\n$output\n"
  fi

  total=$((total+1))
done

echo "Passed $passed out of $total tests"
if [ "$passed" == "$total" ]; then
  exit 0
else
  exit 1
fi