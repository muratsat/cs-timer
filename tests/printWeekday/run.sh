#!/bin/bash

# Print the day of the week for the given date.

test_dir=$(dirname $0)

gcc $test_dir/main.c src/printWeekday.c -o $test_dir/main

if [ $? -ne 0 ]; then
  echo "compilation failed"
  exit 1
fi

# output=$($test_dir/main)
# correct=$(date +"%A")

declare -a dates=(
  "2022-09-24 0:0:0"
  "2022-03-29 0:0:0"
  "2021-12-08 0:0:0"
  "2022-11-17 0:0:0"
)
IFS=''

for date in "${dates[@]}"; do
  correct=$(date -d $date +"%A")
  output=$($test_dir/main $date)
  echo $output $correct
  if [ "$output" != "$correct" ]; then
    echo "error: $date: expected '$correct', got '$output'"
    exit 1
  fi
done
