# EE 205 Programming Assignment 3 - Stack and Queue
Group repo for our EE 205 Programming Assignment 3, Stacks and Queues, Router Simulation

Team: Sandwich
Members: Paulo Lemus, Matthew Yamamoto, Jessie Grazziotin
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

1. make router - builds the main router program

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

# What our program does:
Router: 
This program simulates the way that a router queues in requests and delivers them to their destination. 
The program by default processes requests from time 0 to 100000, and prints only a summary of the results. 
To change the defaults, you can launch the program with an integer argument representing the timeLimit to run until, and/or the DEBUG flag, which prints the contents of each queue every second.

RPC:
This program simulates a Reverse Polish Calculator. This type of calculator was based on older calculators that wanted to conserve memory. 
The key to this type of calculator is that it changes the typical input format that we use to write math equations. 
By rearranging the order of the equation it can use less memory to perform the functions. 
Bjorn Stroustrup's "buggy RPC" for example, uses only one element in a stack for storage.  

Here's a few examples of the magic format: 
2 - 1 -----> 2 1 -
1 + [ ( 3 * 4 ) % 2 ] ---> 1 3 4 * 2 % + 


Our prompt was to recreate our own with a stack. 
Our stack does not need low memory so we have a large stack to take in a large amount of inputs if necessary. 
It parses in the input as a line, separates the line into tokens, and analyzes the tokens. 
If (token = number) it pushes it on the stack.
Else, it's an operation that will perform on the last two stack entries.
Then it pushes the result back onto the stack. 


# Files:

Drivers:
router-sim.cpp  
RPC.cpp  

Headers:
Config.h  
Packet.h  
Queue.h  
RPC.h  
Stack.h  

Other:
config.txt  
evalJessie.md  
evalPaulo.md
evalMatt.md  

