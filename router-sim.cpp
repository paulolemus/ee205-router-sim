/* File: router-sim.cpp
 * Team: Sandwich
 * Date: 3/28/2017
 */

/* Main program for the router simulation
*/

#include <iostream>
#include <cstdlib> 
#include <ctime> 

#include "Config.h"
#include "Queue.h"
#include "Packet.h"


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
                queue1.peek().finished();

                if( (rand() % 2) == 0 ) {
                    if(!queue2.enqueue( queue1.dequeue() )) dropsQ2++;
                } 
                else {
                    if(!queue3.enqueue( queue1.dequeue() )) dropsQ3++;
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


    return 0; 
}
