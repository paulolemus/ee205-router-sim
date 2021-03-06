/* 
File: test_Config.cpp
Author: Jessica Grazziotin
Date: 3/30/17
Course: EE 205 Hw 3
Description: This file is used to test the Config file reader. It pulls in the inputs from config.txt
 */



//This is the file parser from the io file Dr.B gave us in lab5
//she told me to use it for lab 5 so I don't see why we can't for this assignment

// ReadFromFile.cpp : 
// Example code that reads from a file and tokenizes, in C++
// by Milica Jan 2017

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../Packet.h"

//queue stuff
#include <stdexcept> 
#include <exception>
#include "../Queue.h"
#include "../Config.h"

using namespace std;


int main() {

    Config conf("../config.txt");
    conf.readDataFile(); // Config.h reads the config.txt file
    conf.printConfig(); //checks to see what was pulled from config.txt
    
    cout << "lambda1: " << conf.packetDelta() << endl; 
    cout << "process_time1: " << conf.processTimeQ1() << endl; 
    cout << "process_time2: " << conf.processTimeQ2() << endl; 
    cout << "process_time3: " << conf.processTimeQ3() << endl << endl; 

	
	int timer = 1;
    int arrivals = 20; 
    std::srand(std::time(NULL)); //for random numbers

    Packet current(conf.packetDelta());
    cout << current.arrival << endl; 
    
    
    for (; arrivals !=0; timer++){
        cout << "arrival count: " << arrivals << "\t\t";
        arrivals --; 
        
		//enqueue in Q1
		
		
        //after processing send to Q2 or Q3
        int nextQueue = rand() % 2; //should be either 0 or 1
        if (nextQueue == 0){
        	cout << "Sending packet to Q2" << endl;
        }
        else if (nextQueue == 1){
        	cout << "Sending packet to Q3" << endl;
        }
    }
    std::cout << "----Time of full process " << timer << " sec ----" <<endl; 
    
    ///////////////////////////////////////////
    //             TEST CASES                //
    ///////////////////////////////////////////
	std::cout << std::endl;
    // queue objects from both implementations
    ee::array::Queue<Packet> arrayQueue(5);

    // Verify size and capacity functions are working
    std::cout << "arrayQueue capacity: " << arrayQueue.capacity() << std::endl;
    std::cout << "arrayQueue size: "     << arrayQueue.size()     << std::endl;

    // Completely fill queue
    // arrayQueue.enqueue(*current);
    // arrayQueue.enqueue(2);
    // arrayQueue.enqueue(3);
    // arrayQueue.enqueue(4);
    // arrayQueue.enqueue(5);
    // arrayQueue.enqueue(6);

    // Cap and size should both be full
    std::cout << "arrayQueue capacity: " << arrayQueue.capacity() << std::endl;
    std::cout << "arrayQueue size: "     << arrayQueue.size()     << std::endl;
    std::cout << "Is arrayQueue full? "  << arrayQueue.isFull()   << std::endl;

    // test print function, prints from base to top of queue
    // arrayQueue.print();
    std::cout << std::endl;
    return 0;
}


