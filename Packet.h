/* File: Packet.h
 * Name: Paulo Lemus
 * Team: Sandwich
 * Date: 3/30/2017
 */

/* This file contains a basic packet struct that will be used
 * as discrete packets that are passed through the router.
 */


struct Packet {
    bool active;
    int process;
    int arrival;

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

    void begin(int processTime) {
        process  = processTime;
        active   = true;
    }

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
};
