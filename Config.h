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

struct Config {
    string q1a, q1b, q1p, q1e, Q1, q2p, q2e, Q2, q3p, q3e, Q3;
    // int lambda1, process_time1, process_time2, process_time3; 

    void printConfig(void){
	cout << "q1a = " << q1a << endl;
	cout << "q1b = " << q1b << endl;
	cout << "q1p = " << q1p << endl;
	cout << "q1e = " << q1e << endl;
	cout << "Q1 = " << Q1 << endl << endl;
	
	cout << "q2p = " << q2p << endl;
	cout << "q2e = " << q2e << endl;
	cout << "Q2 = " << Q2 << endl << endl;
	
	cout << "q3p = " << q3p << endl;
	cout << "q3e = " << q3e << endl;
	cout << "Q3 = " << Q3 << endl;
    }
    
    string set_string(string a){
        return a; 
    }
    
    
    int conv_q1a = stoi(q1a, NULL, 10);
    int conv_q1b = stoi(q1b, NULL, 10);
    int conv_q1p = stoi(q1p, NULL, 10);
    int conv_q1e = stoi(q1e, NULL, 10);
    int conv_q2p = stoi(q2p, NULL, 10);
    int conv_q2e = stoi(q2e, NULL, 10);
    int conv_q3p = stoi(q3p, NULL, 10);
    int conv_q3e = stoi(q3e, NULL, 10);

    int lambda1 = conv_q1b - conv_q1a;
    int process_time1 = conv_q1e - conv_q1p; 
    int process_time2 = conv_q2e - conv_q2p;
    int process_time3 = conv_q3e - conv_q3p; 
    
};
