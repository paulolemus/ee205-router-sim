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
using namespace std;

void configSetter (void);

int main() {
    
    // configSetter();
	string filename = "config.txt";
	ifstream infile(filename.c_str());  //constructor automatically opens the file

	if (!infile.is_open()) {
		cout << "error in opening input file\n";
		exit(EXIT_FAILURE);
	}

	//read from file
	cout << "reading from input file\n";
	string q1a;
	string q1b;
	string q1p;
	string q1e;
	string Q1;
	string q2p;
	string q2e;
	string Q2;
	string q3p;
	string q3e;
	string Q3;
	

	infile >> q1a; 
	cout << "q1a = " << q1a << endl;
	infile >> q1b; 
	cout << "q1b = " << q1b << endl;
	infile >> q1p; 
	cout << "q1p = " << q1p << endl;
	infile >> q1e; 
	cout << "q1e = " << q1e << endl;
	infile >> Q1; 
	cout << "Q1 = " << Q1 << endl << endl;
	
	infile >> q2p; 
	cout << "q2p = " << q2p << endl;
	infile >> q2e; 
	cout << "q2e = " << q2e << endl;
	infile >> Q2; 
	cout << "Q2 = " << Q2 << endl << endl;
	
	infile >> q3p; 
	cout << "q3p = " << q3p << endl;
	infile >> q3e; 
	cout << "q3e = " << q3e << endl;
	infile >> Q3; 
	cout << "Q3 = " << Q3 << endl;
// 		cout << "\n This should parse out each set of consecutive numbers \n\n\n";
	
	infile.close();
	
	Packet *current = new Packet; 
	int timer = 1;
    int arrivals = 20; 
    int conv = stoi(q1b, NULL, 10);
    // std::string::size_type sz;   // alias of size_t
	// int conv = std::stoi (q1b,&sz);

    std::srand(std::time(NULL)); //for random numbers
    int lambda1 = rand() % conv +1; 
    cout << "lambda1: " << lambda1 << endl; 
    for (timer; arrivals !=0; timer++){
        cout << "arrival count: " << arrivals << "\t\t";
        arrivals --; 
        
		//enque in Q1
	
		
		
        //after processing send to Q2 or Q3
        int nextQueue = rand() % 2; //should be either 0 or 1
        if (nextQueue == 0){
        	cout << "Sending packet to Q2" << endl;
        }
        if (nextQueue == 1){
        	cout << "Sending packet to Q3" << endl;
        }
    }
    return 0;
}


