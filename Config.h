/* File: Config.h
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

// This file will preprocess all of the config file reading in order to get the processing times needed
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std; 


//This uses the same type of file parser from the io file Dr.B gave us in lab5 (see ReadDaFile function below)
//she told me to use it for lab 5 so I don't see why we can't for this assignment

// ReadFromFile.cpp : 
// Example code that reads from a file and tokenizes, in C++
// by Milica Jan 2017
struct Config {
    string q1a, q1b, q1p, q1e, Q1, q2p, q2e, Q2, q3p, q3e, Q3;
    int lambda1, process_time1, process_time2, process_time3; 

    void printConfig(void){ //prints what's read from the config.txt file
    cout << "Contents from config.txt " << endl;
    
    cout << "--- Q1 = " << Q1 << " ---"<< endl;
	cout << "q1a = " << q1a << "\t\tq1b = " << q1b << endl;
	cout << "q1p = " << q1p << "\tq1e = " << q1e << endl;
	
	cout << "--- Q2 = " << Q2 << " ---"<< endl;
	cout << "q2p = " << q2p << "\tq2e = " << q2e << endl;
	
	cout << "--- Q3 = " << Q3 << " ---"<< endl;
	cout << "q3p = " << q3p << "\tq3e = " << q3e << endl <<endl;
    }

    
    //get's the time difference between 2 string inputs
    int get_time( string a , string b){ //input the 1st occuring num first
        int conv_a = stoi(a, NULL, 10);   
        int conv_b = stoi(b, NULL, 10);   
        int diff = conv_b - conv_a; // 2nd # - 1st #
        return diff; 
    }
    
    int get_lambda (void){ //will be used in the ReadDaFile function to set the processing times
        int num = get_time(q1a, q1b);
        return num; 
    }
    
    int get_process_time1 (void){ //same as get_lambda with approriate time diff
        int num = get_time(q1p, q1e);
        return num; 
    }
    
    int get_process_time2 (void){ //same as get_lambda with approriate time diff
        int num = get_time(q2p, q2e);
        return num; 
    }
    
    int get_process_time3 (void){ //same as get_lambda with approriate time diff
        int num = get_time(q3p, q3e);
        return num; 
    }
    
    
    void ReadDaFile (void){
        string filename = "config.txt";
	    ifstream infile(filename.c_str());  //constructor automatically opens the file
    	if (!infile.is_open()) {
    		cout << "error in opening input file\n";
    		exit(EXIT_FAILURE);
    	}
        Config * conf = new Config; 
    	cout << "Reading from input file...\n";
    	
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
    	
    	lambda1 = get_lambda(); //setting the processing times up
    	process_time1 = get_process_time1();
    	process_time2 = get_process_time2();
    	process_time3 = get_process_time3();
    	
    	infile.close(); //close the file
    }
    
    
};
