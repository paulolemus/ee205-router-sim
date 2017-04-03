/* File: router-sim.cpp
 * Team: Sandwich
 * Date: 3/28/2017
 */

/* Main program for the router simulation
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

int    getMin(const std::vector<int>& vec); // returns min value in vector
int    getMax(const std::vector<int>& vec); // returns max value in vector
double getAvg(const std::vector<int>& vec); // returns average of all values
double getStd(const std::vector<int>& vec); // returns standard deviation

int main() {

    srand( time(NULL) );

    std::string configFile = "config.txt";
    Config config(configFile);

    ee::array::Queue<Packet> queue1(config.Q1);
    ee::array::Queue<Packet> queue2(config.Q2);
    ee::array::Queue<Packet> queue3(config.Q3);

    int dropsQ1 = 0;
    int dropsQ2 = 0;
    int dropsQ3 = 0;
    std::vector<int> waitTimesQ1;
    std::vector<int> waitTimesQ2;
    std::vector<int> waitTimesQ3;

    int nextArrival = config.packetDelta();
    int time = 0;

    while(time < 10000) {

        // Place incoming packets in queue1
        if(nextArrival <= time) {
            if( !queue1.enqueue(Packet(nextArrival)) ) dropsQ1++;
            nextArrival = time + config.packetDelta();
        }

        // Process any packets in queue 1
        if(!queue1.isEmpty()) {

            // Begin processing an inactive packet
            if(!queue1.peek().active) {
                queue1.peek().begin( time + config.processTimeQ1() );
            }

            // Move head packet to next queue
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

            // Move finished packets
            else if(queue2.peek().process <= time) {
                waitTimesQ2.push_back(time - queue2.peek().arrival);
                queue2.dequeue();
            }
        }

        // Process packets in queue 3
        if(!queue3.isEmpty()) {

            // Begin processing an inactive packet
            if(!queue3.peek().active) {
                queue3.peek().begin( time + config.processTimeQ3() );
            }

            // Move finished packets
            else if(queue3.peek().process <= time) {
                waitTimesQ3.push_back(time - queue3.peek().arrival);
                queue3.dequeue();
            }
        }
        time++;

    } // end while

    // TODO: ADD MIN/MAX/AVG calculations, PRINT VALUES
    config.printConfig();
    std::cout << "Queue1  drops: " << dropsQ1 << std::endl;
    std::cout << "Queue2  drops: " << dropsQ2 << std::endl;
    std::cout << "Queue3  drops: " << dropsQ3 << std::endl;
    std::cout << "Total   drops: " << dropsQ1 + dropsQ2 + dropsQ3 << std::endl;
    std::cout << "Average drops: " << (dropsQ1 + dropsQ2 + dropsQ3) / 3 << std::endl;
    std::cout << std::endl;
    
    std::cout << "Queue1 min wait: " << getMin(waitTimesQ1) << std::endl;
    std::cout << "Queue2 min wait: " << getMin(waitTimesQ2) << std::endl;
    std::cout << "Queue3 min wait: " << getMin(waitTimesQ3) << std::endl;
    std::cout << "Queue1 max wait: " << getMax(waitTimesQ1) << std::endl;
    std::cout << "Queue2 max wait: " << getMax(waitTimesQ2) << std::endl;
    std::cout << "Queue3 max wait: " << getMax(waitTimesQ3) << std::endl;
    std::cout << "Queue1 avg wait: " << getAvg(waitTimesQ1) << std::endl;
    std::cout << "Queue2 avg wait: " << getAvg(waitTimesQ2) << std::endl;
    std::cout << "Queue3 avg wait: " << getAvg(waitTimesQ3) << std::endl;
    std::cout << "Queue1 wait StdDeviation: " << getStd(waitTimesQ1) << std::endl;
    std::cout << "Queue2 wait StdDeviation: " << getStd(waitTimesQ2) << std::endl;
    std::cout << "Queue3 wait StdDeviation: " << getStd(waitTimesQ3) << std::endl;

    return 0; 
}


int getMin(const std::vector<int>& vec) {
    
    if(vec.size() <= 0) throw std::runtime_error("No min for empty vector");
    else {
        int min = vec[0];
        for(auto value : vec) {
            if(value < min) min = value;
        }
        return min;
    }
}

int getMax(const std::vector<int>& vec) {
    
    if(vec.size() <= 0) throw std::runtime_error("No max for empty vector");
    else {
        int max = vec[0];
        for(auto value : vec) {
            if(value > max) max = value;
        }
        return max;
    }
}

double getAvg(const std::vector<int>& vec) {

    if(vec.size() <= 0) throw std::runtime_error("No average for empty vector");
    else {
        long int sum = 0;
        for(auto value : vec) sum += value;
        return ( 1.0 * sum / vec.size() );
    }
}

double getStd(const std::vector<int>& vec) {

    if(vec.size() <= 0) 
        throw std::runtime_error("No standard deviation for empty vector");
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
