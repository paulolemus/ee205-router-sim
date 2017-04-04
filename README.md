# EE 205 Programming Assignment 3 - Stack and Queue
Group repo for our EE 205 Programming Assignment 3, Stacks and Queues, Router Simulation

Team   : Sandwich
Members: Paulo Lemus, Matthew Yamamoto, Jessie Grazziotin
Date   : 4/4/2017

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

# To make:

type: `make`  
This should make the following exec files:  
Router
RPC

# Test cases

type: 'make tests'
This will create each test file driver individually.
They can run in the main folder with:
"./tests/test-<filename>.out"


