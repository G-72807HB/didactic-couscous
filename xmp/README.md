# SturdyTribble

On The Analysis of Minimum Vertex Cover Algorithm Comparison by Naive - Dynammic Programming Approach

PS. It's expecting a build error, thus the build status

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine for testing and examining purposes

### What is Minimum Vertex Cover(MVC)?

MVC is a minimum possible number of nodes in which, if the nodes are connected as a leaf under one single parent; It would have only took exactly 2 different coupled edges or separated only by 1 node across to reach every other nodes there is.

You can say, that for every edges, one of it's endpoints must be connected to any of the MVC nodes

### How it works

1. We start of from the root, then traverse the tree in an almost similiar manner as in BFS.
2. We make two measurement here, for each node it traverses we count the minimum number of cover by including the node itself and it's children or excluding it, counting the children instead
3. It finishes by returning the minimum of two(from step 2) recursively
4. For DP solution the minimum result cover from the 2 measurement before is stored in each nodes, so that if it visits the same node again, we simply took the stored values instead, eliminating nodes revisiting as in the Naive solution entirely

### Problem illustration example

See the VisuAlgo page about MVC and it's in-depth visualisation from the link in [References](#references) section below

## Prerequisites

I use the following things during the development cycle, it is important to at least established some degree familiarity as I will be relying heavily on these tools and so does the guide. For more information see [Tools](#tools-used) section below

* GCC(G++) 9.2.1
* GNU Time 1.7
* Bash 5.0.7 & ulimit
* C++17
* Linux

If you have all of the above items and would like to skip manual configurations and go straight to testing, just execute `main.sh` from inside your terminal and set your current workdir to where the shell script is(It may need *superuser* permission)

### Installing

A step by step series of examples about how to get a development env running

For GCC you can install via package manager or download and use an IDE instead

```
g++ --version
```

The GNU time is part of most Linux system, so you don't need to install it separately. For Windows user, I prefer to use IDE instead as most of them have it built-in as debug features.

```
man time
```

On it's default format, there is 3 different results after the execution that depends specifically on how it is measured

1. *real* - Self-explanatory, using real wall-clock time
2. *user* - The machine's CPU-seconds, in respect of the user mode
3. *sys* - The machine's CPU-seconds, in respect of the kernel mode

### Before going any further

I decided to divide up the approach into two different files, thus two different executables(NV - Naive; DP - Dynamic Programming) and one source testcase. This makes it easy when doing comparison between test cases(especially when looping for multiple amount of times so as to ensure the most stable result as possible)

My system itself is specified as follows

*Intel Pentium Gold 5405U; 1x4GB DDR4-2600Mhz; M.2 NVMe 256GB @ W:~1GB/s, R:~1.5GB/s; Fedora WS 32*

For neatyness purposes, I recommend to use the same file structures and code styles

### Compiling

After you have cloned this repository to your local machine, compile the program and store it under current/main. I use the following command

```
$ g++ -Wall -Werror -Wextra -pedantic -std=c++17 -o ./current/main/NV ./current/Naive.cpp
```
and

```
$ g++ -Wall -Werror -Wextra -pedantic -std=c++17 -o ./current/main/DP ./current/DP.cpp
```

It tells the compiler to store the output program in ```current/main``` from the input files which can be found under ```current``` and display all the warnings and error which is by default is turned off so that the possibility of bugs arising later can be minimized early

The files(`Naive.cpp` & `DP.cpp`) function as the main driver, which contain dependencies call to the testcases(`Test.h`) and to the headers(`TestNV.h` & `TestDP.h`) that are located in `tests`.

### Running and experimenting with compiler-optimization

I use custom format for the GNU Time

```
command time -f "\nCPU : %P\nMemory : %MKB\nReal %es\nUser %Us \nSys %Ss" ./current/main/XY Z
```

Where XY is the name of executable, and Z is the wanted testcase

The result

```
CPU : 0%
Memory : 3224KB
Real 0.63s
User 0.00s
Sys 0.00s
```

Multiple testcases are not generally recommended as it's interfere with loopback call too much, causing unstable program execution

```
./current/main/XY 1 2 3
```

By default most of the shell's command is under some sort of resource limitation. This command allows us to allocate as much as possible resource to a running terminal program

Next steps,

- [x] Turn off resource limiter
- [x] Add the compiler-optimization flags

```
$ ulimit -u unlimited
$ g++ -Wall -Werror -Wextra -pedantic -std=c++17 -fopenmp -O2 -o ./current/main/XY ./current/XY.cpp
$ command time -f "\nCPU : %P\nMemory : %MKB\nReal %es\nUser %Us \nSys %Ss" ./current/main/XY Z
```

*Beware that some command may need root permission*

I use two kind of flags, OpenMP which allows parallel execution(GCC built-in) and the other is GCC's `-O` optimization. There are several option and category, and each may vary by machines

The rough result of tree generating with >150000 continuous loops

```
Runs #1
NV #1
CPU : 97%
Memory : 1018400KB
Real 1.42s
User 0.24s
Sys 1.14s

Runs #1
DP #1
CPU : 95%
Memory : 1019256KB
Real 1.40s
User 0.24s
Sys 1.09s
```

## Testing Analysis and Explanation

I put as much as 18 different cases(out of unique 3) which expanded to include data order of growth by a factor of 10

1. Case(1-6): StarTree, `N = 1/10/100/1000/10000/100000`; The tree consists of `N-leaves`, but only one parent.
2. Case(7-12): LinearChain, `N = 1/10/100/1000/10000/100000`; Despite `N`, every node will always have one parent and one children. Thus `N` denotes the depth of tree.
3. Case(13-18); Complete I-ary tree, `N = 1/10/100/1000/10000/100000`; Self-explanatory, currently `I is set to 3`

Here's some illustration(*Parent: X,Child: 0*)

```
StarTree(N is set to 8)

0#0#0
#\|/#
0-X-0
#/|\#
0#0#0
```

```
LinearChain(N is set to 5)

X-0-0-0-0-0
```

```
Complete I-ary tree(I is set to 3, N is set to 4)

#######
#####/0
###/0-0
##/##\0
#/###/0
X---0-0
#\###\0
##\##/0
###\0-0
#####\0
#######
```

### Up-to-date results

You can see the latest build and test results here [TravisCI-Log](https://travis-ci.com/github/Dithmarschen/sturdy-tribble). It generates a whopping *~3000* lines of log output from 18x10 different cases formated nicely for analysis purposes

### Data on the table

The algorithm average time consumption and memory usage results compared side-by-side across testcases in 10x runs. The first row represents *% of CPU usage*, the second row represents the total *memory consumption in MB(Default) or GB(G)*, and the third row represents the roughly amount of execution *time in seconds or Inf(Infinite)*

#### Case 1-6(StarTree 1/10/100/1000/10000/100000)

NV-1 | DP-1 | NV-2 | DP-2 | NV-3 | DP-3 | NV-4 | DP-4 | NV-5 | DP-5 | NV-6 | DP-6
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
35.0 | 53.3 | 20.0 | 41.6 | 73.3 | 82.6 | 92.6 | 85.0 | 97.3 | 96.2 | 96.9 | 97.7
3.03 | 2.95 | 3.07 | 3.05 | 3.41 | 3.39 | 7.10 | 7.00 | 43.5 | 43.5 | ~407 | ~406
0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.03 | 0.04 | 0.39 | 0.38

We managed to achieve toe-to-toe performance; one of the main reason was because StarTree here doesn't make that much recursive calls. Although DP have slightly better memory consumption by a little margin

#### Case 7-12(LinearChain 1/10/100/1000/10000/100000)

NV-7 | DP-7 | NV-8 | DP-8 | NV-9 | DP-9 | NV-10 | DP-10 | NV-11 | DP-11 | NV-12 | DP-12
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
35.0 | 30.0 | 30.0 | 40.0 | Inf. | 90.0 | Inf. | 85.5 | Inf. | 96.6 | Inf. | 98.5
3.03 | 3.01 | 3.08 | 3.02 | Inf. | 3.41 | Inf. | 7.09 | Inf. | 44.1 | Inf. | ~414
0.00 | 0.00 | 0.00 | 0.00 | Inf. | 0.00 | Inf. | 0.00 | Inf. | 0.04 | Inf. | 0.40

As expected, NV can't barely handle as little as N=100 depth LinearChain tree(even though the previous tests run absolutely fine); meanwhile, DP effortlesly paving it's way through to N=100000 thanks to it's excellent memoization. Also, I took the liberty on testing DP furthermore to up to N=~600000. It took around *~30s*, and so far there isn't any sign of bad memory allocation whatsoever using my current settings

#### Case 13-18(Complete N-ary Tree(I=3) 1/10/100/1000/10000/100000)

NV-13 | DP-13 | NV-14 | DP-14 | NV-15 | DP-15 | NV-16 | DP-16 | NV-17 | DP-17 | NV-18 | DP-18
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
30.0 | 20.0 | 55.0 | 45.0 | 66.8 | 77.4 | 88.8 | 90.1 | 95.8 | 98.3 | 98.8 | 99.0
3.07 | 3.01 | 3.24 | 3.13 | 4.29 | 4.24 | 15.2 | 15.1 | ~124 | ~124 | 1.2G | 1.2G
0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.01 | 0.01 | 0.18 | 0.15 | 10.5 | 10.3

Much of the computational power and memory is heavily used more than previous cases, making it interesting to toy with and the most balanced case to date. First off, DP started using significantly less CPU, and memory effectively beating NV in the first 3 cases. It became clear as the data grows faster, while the amount of DP's execution time grows slower, the time it took for NV grows exponentially; especially when one were to step up to N>1000000


## Miscellaneous

Here is list of many source-references and every other thing that exert some level of influence that help make this project possible from the ground up

### Tools used

* [GCC](http://gnu.org/gcc/) - The GNU Compiler Collections
* [GitHub](https://github.com/) - Used for code hosting and versioning
* [TravisCI](https://travis-ci.com/) - Continuous Integration tools
* [Fedora WS 32](https://getfedora.org/) - *"Choose freedom, choose Fedora"*

### Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us

### Versioning

I use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/G-72807HB/didactic-couscous/tags)

### Authors

* [G-72807HB](https://github.com/G-72807HB)

See also the list of [contributors](https://github.com/G-72807HB/didactic-couscous/contributors) who participated in this project

### License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

### References

* [VisuAlgo](https://visualgo.net/en/mvc) - Many complex data structures nicely explained interactively
* [GeeksforGeeks](https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/) - My original source of inspiration. Thanks!
* Data Structures and Algorithm Analysis in C++ by *Mark A. Weiss*
* Guides to Scientific Computing in C++(The UTICS Series) by *J. Pitt-Francis and J. Whiteley*
* Class slides and lecture notes

### Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* Deadlines
* etc
