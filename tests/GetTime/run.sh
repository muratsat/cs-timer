
#!/bin/bash

test_dir=$(dirname $0)


if ! g++ $test_dir/main.cpp src/GetTime.cpp -o $test_dir/main 
then
  echo "Compilation failed"
  exit 1
fi

# Console colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

correct=$(date +"%Y-%m-%d %H:%M:%S")
output=$($test_dir/main "$correct")

if [ "$output" != "$correct" ]
then
  echo -e "${RED}Test failed${NC}"
  echo "Expected: $correct"
  echo "Got: $output"
  exit 1
fi