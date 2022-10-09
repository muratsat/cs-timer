#!/bin/bash

test_dir=$(dirname $0)

gcc $test_dir/main.c src/setCurrentTime.c -o $test_dir/main

correct=$(date +"%Y-%m-%d %H:%M:%S")
output=$($test_dir/main)

if [ "$output" == "$correct" ]; then
  exit 0
else
  exit 1
fi