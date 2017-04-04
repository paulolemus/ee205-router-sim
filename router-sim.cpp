/* File: router-sim.cpp
 * Team: Sandwich
 * Date: 3/28/2017
 */

/* Main program for the router simulation.
 * To use this program, you can either run it without any
 * arguments to have it print out basic information, or you 
 * execute it with an argument "DEBUG" to have it print out
 * the state of each queue at each time period. You can also
 * provide an integer to select the amount of time the program
 * will run.
 *
 * EXAMPLES:
 * ./Router DEBUG - causes program to print queue status every second
 * ./Router 100   - causes program to set time limit from 100000 to 100
 * ./Router 100 DEBUG - does both above
 * ./Router DEBUG 100 - same as above too
*/

#include <cmath>
#include <cstdlib> 
#include <ctime> 
#include <exception>
#include <iostream>
#include <vector>

#include "Config.h"
#include "Queue.h"
#include "Packet.h"

// Read in any arguments and assign integers to the time limit the 
// program will run to, or set a debug flag to print queue contents
// at each second.
void   processArgs(int argc, char** argv, int& timeLimit, bool& DEBUG);

int    getMin(const std::vector<int>& vec); // returns min value in vector
int    getMax(const std::vector<int>& vec); // returns max value in vector
double getAvg(const std::vector<int>& vec); // returns average of all values
double getStd(const std::vector<int>& vec); // returns standard deviation


int main(int argc, char** argv) {

    srand( time(NULL) );

    std::string configFile = "config.txt";
    Config config(configFile);

    ee::array::Queue<Packet> queue1(config.Q1);
    ee::array::Queue<Packet> queue2(config.Q2);
    ee::array::Queue<Packet> queue3(config.Q3);
    std::vector<int> waitTimesQ1;
    std::vector<int> waitTimesQ2;
    std::vector<int> waitTimesQ3;

    int dropsQ1 = 0;
    int dropsQ2 = 0;
    int dropsQ3 = 0;

    int nextArrival = config.packetDelta();
    int numPackets  = 0;
    int time        = 0;

    int timeLimit = 100000;
    bool DEBUG    = false;
    processArgs(argc, argv, timeLimit, DEBUG);

    // Primary loop for the router simulation. This loop
    // steps through each seconds and processes each packet
    // using the parameters provided in the config file.
    //
    // ALGORITHM:
    // This program steps through every second of the simulation from
    // 0 to either 100000 by default or a given time limit. At the 
    // start of a fresh loop, the program checks if it is time for 
    // new packet to arrive. If it is, it adds the packet to Q1.
    // Every loop, each queue also checks if it needs to process a packet.
    // Packets are processed once their process time has been reached, then
    // they are removed from the queue.
    while(time < timeLimit) {

        // print lines if user launches program with DEBUG argument
        if(DEBUG) {
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "Time: " << time << std::endl;
            std::cout << "Q1 "; queue1.print();
            std::cout << "Q2 "; queue2.print();
            std::cout << "Q3 "; queue3.print();
        }

        // Place incoming packets in queue1
        if(nextArrival <= time) {
            numPackets++;
            if( !queue1.enqueue(Packet(nextArrival)) ) dropsQ1++;
            nextArrival = time + config.packetDelta();
        }

        // Process any packets in queue 1
        if(!queue1.isEmpty()) {

            // Begin processing an inactive packet
            if(!queue1.peek().active) {
                queue1.peek().begin( time + config.processTimeQ1() );
            }

            // Move finished packets to next queue randomly
            else if(queue1.peek().process <= time) {

                waitTimesQ1.push_back(time - queue1.peek().arrival);
                queue1.peek().arrival = time;
                queue1.peek().finished();

                if( (rand() % 2) == 0 ) {
                    if( !queue2.enqueue(queue1.dequeue()) ) dropsQ2++;
                } 
                else {
                    if( !queue3.enqueue( queue1.dequeue()) ) dropsQ3++;
                }
            }
        }

        // Process packets in queue 2
        if(!queue2.isEmpty()) {

            // Begin processing an inactive packet
            if(!queue2.peek().active) {
                queue2.peek().begin( time + config.processTimeQ2() );
            }

            // Delete finished packets
            else if(queue2.peek().process <= time) {
                waitTimesQ2.push_back(time - queue2.peek().arrival);
                queue2.dequeue();
            }
        }

        // Process packets in queue 3
        if(!queue3.isEmpty()) {

            // Begin processing an inactive packet in queue
            if(!queue3.peek().active) {
                queue3.peek().begin( time + config.processTimeQ3() );
            }

            // Delete fully processed packets
            else if(queue3.peek().process <= time) {
                waitTimesQ3.push_back(time - queue3.peek().arrival);
                queue3.dequeue();
            }
        }
        // Step time in simulation
        time++;

    } // end while

    // Print summary statements on statistics for each queue
    std::cout << "-----------------------------------------------" << std::endl;
    config.printConfig();
    std::cout << "Time limit: " << timeLimit << std::endl;
    std::cout << "Total number of packets: " << numPackets << std::endl;
    std::cout << "Queue1  drops: " << dropsQ1 << std::endl;
    std::cout << "Queue2  drops: " << dropsQ2 << std::endl;
    std::cout << "Queue3  drops: " << dropsQ3 << std::endl;
    std::cout << "Total   drops: " << dropsQ1 + dropsQ2 + dropsQ3 << std::endl;
    std::cout << "Average drops: " << (dropsQ1 + dropsQ2 + dropsQ3) / 3 << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Queue1 min wait: " << getMin(waitTimesQ1) << std::endl;
    std::cout << "Queue2 min wait: " << getMin(waitTimesQ2) << std::endl;
    std::cout << "Queue3 min wait: " << getMin(waitTimesQ3) << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Queue1 max wait: " << getMax(waitTimesQ1) << std::endl;
    std::cout << "Queue2 max wait: " << getMax(waitTimesQ2) << std::endl;
    std::cout << "Queue3 max wait: " << getMax(waitTimesQ3) << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Queue1 avg wait: " << getAvg(waitTimesQ1) << std::endl;
    std::cout << "Queue2 avg wait: " << getAvg(waitTimesQ2) << std::endl;
    std::cout << "Queue3 avg wait: " << getAvg(waitTimesQ3) << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Queue1 wait StdDeviation: " << getStd(waitTimesQ1) << std::endl;
    std::cout << "Queue2 wait StdDeviation: " << getStd(waitTimesQ2) << std::endl;
    std::cout << "Queue3 wait StdDeviation: " << getStd(waitTimesQ3) << std::endl;

    return 0; 
}

/* ALGORITHM:
 * 1. Save all program arguments besides program name to a string vector.
 * 2. Check each string in the vector and do the following:
 *  a. If string is equal to DEBUG, enable debug flag.
 *  b. else if string is convertable to int, set the timelimit to the int.
 */
void processArgs(int argc, char** argv, int& timeLimit, bool& DEBUG) {
    std::vector<std::string> args;
    for(int i = 1; i < argc; ++i) args.push_back(argv[i]);
    for(auto arg : args) {
        if(arg == "DEBUG") DEBUG = true;
        else {
            try {
                int limit = std::stoi(arg);
                timeLimit = limit;
            } catch(std::exception& e) {}
        }
    }
}

/* ALGORITHM:
 * Set a min variable to first element in vector.
 * If any element is smaller while iterating,
 * replace min with that element.
 */
int getMin(const std::vector<int>& vec) {
    
    if(vec.size() <= 0) return -1;
    else {
        int min = vec[0];
        for(auto value : vec) {
            if(value < min) min = value;
        }
        return min;
    }
}

/* ALGORITHM:
 * Set a max variable to the first element of array.
 * If any element is greater than max while iterating, 
 * replace max with that element.
 */
int getMax(const std::vector<int>& vec) {
    
    if(vec.size() <= 0) return -1;
    else {
        int max = vec[0];
        for(auto value : vec) {
            if(value > max) max = value;
        }
        return max;
    }
}

/* ALGORITHM:
 * Sum all elements in vector, divide by vector size
 */
double getAvg(const std::vector<int>& vec) {

    if(vec.size() <= 0) return -1;
    else {
        long int sum = 0;
        for(auto value : vec) sum += value;
        return ( 1.0 * sum / vec.size() );
    }
}

double getStd(const std::vector<int>& vec) {

    if(vec.size() <= 0) return -1; 
    else {
    
        // calculate the average of values
        long int tempSum = 0;
        for(auto value : vec) tempSum += value;
        double avg = 1.0 * tempSum / vec.size();

        // Calculate the SIGMA sum for each element in vec
        double stdDeviation = 0;
        for(auto value : vec) stdDeviation += (value - avg) * (value - avg);

        // Divide SIGMA sum by N
        stdDeviation /= vec.size();

        // Take SQRT of everything above to get actual stdDeviation
        stdDeviation = sqrt(stdDeviation);
        return stdDeviation;
    }
}
