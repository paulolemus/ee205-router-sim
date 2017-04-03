# ee205-router-sim
Group repo for our EE 205 Programming Assignment 3, Stacks and Queues, Router Simulation

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
