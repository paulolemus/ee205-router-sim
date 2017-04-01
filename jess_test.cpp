/* File: router-sim.cpp
 */

/* Main program for the router simulation
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
#include "Packet.h"

//queue stuff
#include <stdexcept> //had to add this for runtime and other random things that wouldn't compile
#include <exception>
#include "Queue.h"

// #include "Config.h"
using namespace std;

void configSetter (void);

int main() {
	string filename = "config.txt";
	ifstream infile(filename.c_str());  //constructor automatically opens the file
	if (!infile.is_open()) {
		cout << "error in opening input file\n";
		exit(EXIT_FAILURE);
	}

	cout << "reading from input file\n";
	string q1a, q1b, q1p, q1e, Q1, q2p, q2e, Q2, q3p, q3e, Q3; //declare strings
	infile >> q1a; //pulling in variables from file 
	infile >> q1b; 
	infile >> q1p; 
	infile >> q1e; 
	infile >> Q1; 
	infile >> q2p; 
	infile >> q2e; 
	infile >> Q2; 
	infile >> q3p; 
	infile >> q3e; 
	infile >> Q3; 

	cout << "q1a = " << q1a << endl; //print the variables from config file
	cout << "q1b = " << q1b << endl; //This should parse out each set of consecutive numbers
	cout << "q1p = " << q1p << endl;
	cout << "q1e = " << q1e << endl;
	cout << "Q1 = " << Q1 << endl << endl;
	cout << "q2p = " << q2p << endl;
	cout << "q2e = " << q2e << endl;
	cout << "Q2 = " << Q2 << endl << endl;
	cout << "q3p = " << q3p << endl;
	cout << "q3e = " << q3e << endl;
	cout << "Q3 = " << Q3 << endl;

	
	infile.close(); //close the file
	
	
    int conv_q1a = stoi(q1a, NULL, 10); //convert strings to ints
    int conv_q1b = stoi(q1b, NULL, 10);
    int conv_q1p = stoi(q1p, NULL, 10);
    int conv_q1e = stoi(q1e, NULL, 10);
    int conv_q2p = stoi(q2p, NULL, 10);
    int conv_q2e = stoi(q2e, NULL, 10);
    
    int lambda1 = conv_q1b-conv_q1a; //create the input rate and processing times
    int process_time1 = conv_q1e-conv_q1p;
    int process_time2 = conv_q2e-conv_q2p;
    int process_time3 = conv_q3e-conv_q3p;

    cout << "lambda1: " << lambda1 << endl; 
    cout << "process_time1: " << process_time1 << endl; 
    cout << "process_time2: " << process_time2 << endl; 
    cout << "process_time3: " << process_time3 << endl; 

	
	int timer = 1;
    int arrivals = 20; 
    std::srand(std::time(NULL)); //for random numbers

    Packet *current = new Packet; //start the new packet
    current->set_arrival_time(lambda1); 
    cout << current->arrival_time << endl; 
    
    
    for (timer; arrivals !=0; timer++){
        cout << "arrival count: " << arrivals << "\t\t";
        arrivals --; 
        
		//enqueue in Q1
		
		
        //after processing send to Q2 or Q3
        int nextQueue = rand() % 2; //should be either 0 or 1
        if (nextQueue == 0){
        	cout << "Sending packet to Q2" << endl;
        }
        if (nextQueue == 1){
        	cout << "Sending packet to Q3" << endl;
        }
    }
    
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


