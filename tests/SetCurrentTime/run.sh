#!/bin/bash

test_dir=$(dirname $0)

if ! gcc $test_dir/main.cpp src/SetCurrentTime.cpp -o $test_dir/main
then
  exit 1
fi

correct=$(date +"%Y-%m-%d %H:%M:%S")
output=$($test_dir/main)

if [ "$output" == "$correct" ]; then
  exit 0
else
  exit 1
fi