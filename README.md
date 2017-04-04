# ee205-router-sim
Group repo for our EE 205 Programming Assignment 3, Stacks and Queues, Router Simulation

Team: Sandwich
Members: Paulo L, Jessie G, Matthew Y.
Date: 4/2/2017
TA: Austin Tasato

# PROJECT STRUCTURE

All the files used in the main programs such as the router-simulation and 
the RPN are found in the root folder, the same folder as this README.

The tests/ folder contains some googletest files that are used to verify
the correctness of some of the classes and logic, as well as some extra
test files we used to test our code before adding them to the main programs.

The deps/ folder contains the googletest dependency, which is required
to build any of the tests in the tests/ folder that uses googletest.
I added this dependency so you do not have to install it before hand.

The results/ folder contains any sort of logs or printouts of the router
program, as well as our individual evaluation forms and other files.

# BUILD INSTRUCTIONS

# Building main program

1. make Router - builds the main router program

# Building GTest, building tests, and running tests

1. make deps
2. make tests
3. export TESTCASE=<test-case-name-without-cpp-extension>
4. make run-test

# Running a particular test in tests folder

1. Export the name of the test without the .cpp extension into your
   bash environment.
   Example: `export TESTCASE=test-Queue-array` then `make run-test`

# Building all .cpp files in the test folder

simply type `make tests`, and all the tests will be compiled
into a file of the same name suffixed with `.out`.
