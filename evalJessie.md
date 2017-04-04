## HW3 Evaluation - Jessica Grazziotin - Team Sandwich


## 1) What I learned from this homework:
I learned that parsing out numbers versus operations is a lot more complex and tedious that it appears at first. 
I also learned the important of knowing the time relationships between your processing times and you incoming queue times. 
It taught me the importance of knowing where your bottlenecks are in a program and how it can really affect your implementation. 



## 2) My Contributions
(separated by file)
### Config.h 
Paulo set it up, I added most of the functions, and then he cleaned everything up because it was kind of messy. 


This file is responsible for parsing the config.txt file and relaying the time variables to the queue. 
It also handles the randomization of the inputs to the queues. 



### RPC.cpp and  test/test-RPC.cpp
I wrote these with a combination of the files from Lab 8 and some getline / tokenizer tools from lab 5. 

I used the buggy reverse polish calculator file we were given in lab 8 as inspiration for the switch cases of the calculator parser. 

I wanted the Calculator to be clean and direct like a calculator so there's not many print outs. 
The test file I made uses a lot of print outs for debugging and is always checking the stack. 

This file handles the interface between the RPC.h file and the Stack.h file. 
It tokenizes a users input to a Reverse Polish Calculator. 

### router-sim.cpp
I started contributed to the setup for this but did not put in most of the work. 
My goal was to make sure that it could work with the Config.h file


## 3) Questions:

Can we go over standards for neatness when coding?
When I look at my code and I look at everyone elses, mine looks so sloppy. 


## 4) Comments:
I enjoyed this homework much more than the last one. 
I felt that I was much more prepared and was able to contribute more to this one than homework 2. 
I still feel like I need to work on my cleanliness with comments and the way I setup my functions. 