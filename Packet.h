/* File: Packet.h
 * Name: Paulo Lemus
 * Team: Sandwich
 * Date: 3/30/2017
 */

/* This file contains a basic packet struct that will be used
 * as discrete packets that are passed through the router.
 */

#include <ctime>



struct Packet {
    long int arrival_time;
    int process_time;
    int dest;
    int i; 
    const int arrival_number =i;

    long int set_arrival_time(int range){
        std::srand(std::time(NULL)); //for random numbers
        arrival_time = rand() % range; 
        std::cout << "Packet.h: Arrival time is: " << arrival_time << std::endl; 
        return arrival_time;
    }
    
    int set_process_time(int range){
        std::srand(std::time(NULL)); //for random numbers
        return process_time = rand() % range; 
    }
    
    int set_arrival_number(void){
        while (i){
            i++;
            return i;  
        }
    }
    
    const int get_arrival_number(void){
        return arrival_number; 
    }
};
