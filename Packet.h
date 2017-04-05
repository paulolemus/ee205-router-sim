/* File: Packet.h
 * Name: Paulo Lemus
 * Team: Sandwich
 * Date: 3/30/2017
 */

/* This file contains a basic packet struct that will be used
 * as discrete packets that are passed through the router.
 */

#ifndef EE_HW3_PACKET_H_
#define EE_HW3_PACKET_H_

#include <ostream>

struct Packet {
    bool active;    // Used so queues can tell if a new packet is at head
    int process;    // Time when packet is finished being processed
    int arrival;    // Time the packet arrives at a queue

    Packet() :
        active(false),
        process(-1),
        arrival(-1) {}

    Packet(const Packet& p)  {
        active   = p.active;
        process  = p.process;
        arrival  = p.arrival;
    }

    Packet(int arrival) : 
        active(false), 
        process(-1),
        arrival(arrival) {}

    // Used with queue to set the time the packet is finished
    void begin(int processTime) {
        process  = processTime;
        active   = true;
    }

    // Called to reset packet values in one line
    void finished() {
        process = -1;
        active = false;
    }

    bool operator== (const Packet& p) {
        return (p.arrival == arrival);
    }

    void operator= (const Packet& p) {
        active = p.active;
        process = p.process;
        arrival = p.arrival;
    }

    // Used to print a packet. It prints the arrival time to a queue, suffixed
    // with t if it is being processed or f if it is inactive
    friend std::ostream& operator<< (std::ostream& out, const Packet& p) {
        out << p.arrival;
        if(p.active) out << "t";
        else         out << "f";
        return out;
    }
};

#endif // EE_HW3_PACKET_H_
