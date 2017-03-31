/* File: Packet.h
 * Name: Paulo Lemus
 * Team: Sandwich
 * Date: 3/30/2017
 */

/* This file contains a basic packet struct that will be used
 * as discrete packets that are passed through the router.
 */

struct Packet {
    long int arrival_time;
    int process_time;
    int dest;

};
