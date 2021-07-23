#!/bin/bash

g++ -Wall -Werror -Wextra -pedantic -fopenmp -O2 -std=c++17 -o ./current/main/NV ./current/Naive.cpp && g++ -Wall -Werror -Wextra -pedantic -fopenmp -O2 -std=c++17 -o ./current/main/DP ./current/DP.cpp

echo "###RESULT###" > RESULT
echo "" >> RESULT

# NV: 1-8; 13-18; DP: 1-18

casesNV=(1 2 3 4 5 6 7 8 13 14 15 16 17 18)
casesDP=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18)

for test in NV DP
do

  if [ $test == 'NV' ]
  then
    cases=${casesNV[@]}
  elif [ $test == 'DP' ]
  then
    cases=${casesDP[@]}
  fi

  for case in ${cases[@]}
  do

    for runs in {1..10}
    do

      # For Deployment
      command time -f "Runs\t:\t#$runs\nCPU\t:\t%P\nMEM\t:\t%MKB\nTIME\t:\t%es(Real) %Us(User) %Ss(Sys)\n" ./current/main/$test $case

      # For Testing
      # command time -f "Runs\t:\t#$runs\nCPU\t:\t%P\nMEM\t:\t%MKB\nTIME\t:\t%es(Real) %Us(User) %Ss(Sys)\n" ./current/main/$test $case &>> RESULT

    done
  done
done
