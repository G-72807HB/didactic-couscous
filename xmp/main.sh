#!/bin/bash

g++ -Wall -Werror -Wextra -pedantic -fopenmp -Os -Ofast -std=c++17 -o ./current/main/main ./current/main.cpp

# Passed:1-10, 13-16
cases=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18)

for test in main
do

  for case in ${cases[@]}
  do

    # for runs in {1..10}
    for runs in 1
    do

      # For Deployment
      command time -f "Runs\t:\t#$runs\nCPU\t:\t%P\nMEM\t:\t%MKB\nTIME\t:\t%es(Real) %Us(User) %Ss(Sys)\n" ./current/main/$test $case

      # For Testing
      # command time -f "Runs\t:\t#$runs\nCPU\t:\t%P\nMEM\t:\t%MKB\nTIME\t:\t%es(Real) %Us(User) %Ss(Sys)\n" ./current/main/$test $case &>> RESULT

    done
  done
done
