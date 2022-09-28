#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

tests=$(dirname $0)
passed=0
total=0

for test_dir in tests/*/; do
  if [ -f $test_dir/run.sh ]; then
    printf "\n$test_dir:\n"
    if $test_dir/run.sh; then
      printf "${GREEN}test $test_dir passed${NC}\n"
      passed=$((passed+1))
    else
      printf "${RED}test $test_dir failed${NC}\n"
    fi
    total=$((total+1))
    rm $test_dir/main
  fi
done

echo "passed $passed/$total tests"
if [ $passed -eq $total ]; then
  exit 0
else
  exit 1
fi
