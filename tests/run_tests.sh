#!/bin/bash

tests=$(dirname $0)

for test_dir in tests/*/; do
  if [ -f $test_dir/run.sh ]; then
    echo "Running test in $test_dir"
    if $test_dir/run.sh; then
      echo "test $test_dir passed"
    else
      echo "test $test_dir failed"
      exit 1
    fi
  fi
done

echo "All tests passed"
