#!/bin/bash

work_dir=$(dirname $0)

gcc $work_dir/test.c src/setCurrentTime.c -o $work_dir/test

rm -f $work_dir/test
