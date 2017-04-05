## HW3 Evaluation - Paulo Lemus - Team Sandwich

## 1) What I learned from this homework:

I spent the first 8 hours working on adding the GoogleTest dependancy,
as well as setting up the makefile and make environment.
From this, I learned how to add dependencies to a project so that
anyone who has it does not need to install an external library.

I learned how to write robust Stack and Queue classes.

I learned how to add execution parameters to meaningfully change 
program output.

## 2) My Contributions

I wrote the code for the Stack and Queue classes, although Jessie and Matt
modified the Stack class so that is was more compatible with the RPC program.

I took Jessie's code for the router-simulation and added features and cleaned up
the code, as well as added the print statements. I wrote the functions for min, max, 
average, and standard deviation.

I wrote a couple test files to ensure that the stack and queue classes behave EXACTLY
as expected. I also converted Jessie's Token-Stack test into one that made use of 
GoogleTest for quicker testing and validation.

I took Jessie's and Matt's Config.h code and robustified it a little.

I put together some of the output logs for the router-simulation for analysis.

## 3) Questions:

Would it be possible to go over using CMake instead of GNUMake? I hear that CMake
is a much better build software than Make and that is works cross-platform, however
the documentation for it is tough to read.

Also, I am confused about using .o files that were compiled with the -c flag vs
using .a files which from the GTEST makefile appear to be a linked library?
What does this line mean:
`ar -rv libgtest.a gtest-all.o`


## 4) Comments:

I think this was a fun project, as we gained experience working with a program
that required use of many different types of classes working together.
I think that the instructions for the assignment could have been a little clearer,
for example, it says that queue1 capacity is Q1, but further down it says, 
"assume Q1=Q2=Q3=3 sec", implying that capacity is measured in time instead
of packets the queue can hold.
