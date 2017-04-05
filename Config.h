/* File: Config.h
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

/* This file will preprocess all of the config file 
 * reading in order to get the processing times needed
 */
#ifndef EE_HW3_CONFIG_H_
#define EE_HW3_CONFIG_H_

#include <iostream>
#include <fstream>
#include <cstdlib> // rand
#include <string>


struct Config {

    const std::string configFile;
    int q1a, q1b, q1p, q1e, Q1;
    int q2p, q2e, Q2; 
    int q3p, q3e, Q3;

    // Config must be given a string to a file so that it can
    // parse in all the configuration values
    Config(std::string configFile) : configFile(configFile) {
        readDataFile();
    }

    // Returns the next time a packet should arrive
    int packetDelta() {
        int diff = q1b - q1a;
        return rand() % diff + q1a;
    }

    // Returns the processing time for a packet of Q1
    int processTimeQ1() {
        int diff = q1e - q1p;
        return rand() % diff + q1p;
    }

    // Returns the processing time for a packet of Q2
    int processTimeQ2() {
        int diff = q2e - q2p;
        return rand() % diff + q2p;
    }

    // Returns the processing time for a packet of Q3
    int processTimeQ3() {
        int diff = q3e - q3p;
        return rand() % diff + q3p;
    }


    // prints what's read from the config file
    void printConfig() {

        std::cout << "Contents from config.txt " << std::endl;
        std::cout << "-------- Q1 = " << Q1 << " --------"  << std::endl;
        std::cout << "q1a = " << q1a << "\t\tq1b = " << q1b << std::endl;
        std::cout << "q1p = " << q1p << "\t\tq1e = " << q1e << std::endl;
        std::cout << "-------- Q2 = " << Q2 << " --------"<< std::endl;
        std::cout << "q2p = " << q2p << "\tq2e = " << q2e << std::endl;
        std::cout << "-------- Q3 = " << Q3 << " --------"<< std::endl;
        std::cout << "q3p = " << q3p << "\tq3e = " << q3e << std::endl;
        std::cout << std::endl;
    }

    // Parse in all the values from the data file given
    void readDataFile() {

        std::ifstream infile(configFile.c_str()); 

        // Guard against invalid file name
        if (!infile.is_open()) {
            std::cout << "error in opening input file\n";
            exit(EXIT_FAILURE);
        }
        std::cout << "Reading from input file...\n";

        // pulling in variables from file 
        infile >> q1a >> q1b >> q1p >> q1e >> Q1; 
        infile >> q2p >> q2e >> Q2; 
        infile >> q3p >> q3e >> Q3; 

        // Guard against failed read from config file
        if(infile.fail()) {
            std::cout << "Failed to read config file" << std::endl;
            exit(EXIT_FAILURE);
        }
        // Guard against invalid config file values
        if(q1a > q1b ||
           q1p > q1e ||
           q2p > q2e ||
           q3p > q3e ||
           q1b <= 0  ||
           q1e <= 0  ||
           q2e <= 0  ||
           q3e <= 0 ) {
            
            std::cout << "Invalid value in config file" << std::endl;
            exit(EXIT_FAILURE);
        }

        infile.close();
    }
};

#endif // EE_HW3_CONFIG_H_
