/* File: main-queue.cpp
 * Name: Paulo Lemus
 * Date: 3/13/2017
 */
#include <stdexcept> //had to add this for runtime and other random things that wouldn't compile
#include <exception>
#include <iostream>
#include "Queue.h"


int main(){

    ///////////////////////////////////////////
    //             TEST CASES                //
    ///////////////////////////////////////////

    // queue objects from both implementations
    ee::array::Queue<int> arrayQueue(5);

    // Verify size and capacity functions are working
    std::cout << "arrayQueue capacity: " << arrayQueue.capacity() << std::endl;
    std::cout << "arrayQueue size: "     << arrayQueue.size()     << std::endl;

    // Completely fill both queues
    arrayQueue.enqueue(1);
    arrayQueue.enqueue(2);
    arrayQueue.enqueue(3);
    arrayQueue.enqueue(4);
    arrayQueue.enqueue(5);
    arrayQueue.enqueue(6);

    // Cap and size should both be full
    std::cout << "arrayQueue capacity: " << arrayQueue.capacity() << std::endl;
    std::cout << "arrayQueue size: "     << arrayQueue.size()     << std::endl;
    std::cout << "Is arrayQueue full? "  << arrayQueue.isFull()   << std::endl;

    // test print function, prints from base to top of queue
    arrayQueue.print();
    std::cout << std::endl;


    // dequeue test, throws exception if you attempt to over dequeue
    // Intended usage is to check isEmpty before dequeueping
    for(int i = 0; i < arrayQueue.capacity() + 1; ++i) {
        try {
            std::cout << arrayQueue.dequeue() << std::endl;
        } catch(const std::runtime_error& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }

    // Check isEmpty function, should be true
    std::cout << "Is arrayQueue empty? " << arrayQueue.isEmpty() << std::endl;
    // std::cout << "Is listQueue empty? "  << listQueue.isEmpty()  << std::endl;
    std::cout << "DONE!" << std::endl;


    //////////////////////////////////////////////////////////
    //                    USER TESTING                      //
    //////////////////////////////////////////////////////////

    ee::array::Queue<int> arrayQue(10);
    // ee::list::queue<int>  listQue(10);
    bool running = true;
    bool usingArray = true;

    std::cout << "\n\nNote that input is UNPROTECTED, enter values correctly" << std::endl;

    while(running){

        int select;
        int data;
        std::cout << "\n\nEnter 1 to enqueue an int" << std::endl;
        std::cout << "Enter 2 to dequeue an int"     << std::endl;
        std::cout << "Enter 3 to get size"           << std::endl;
        std::cout << "Enter 4 to get capacity"       << std::endl;
        std::cout << "Enter 5 to check isFull"       << std::endl;
        std::cout << "Enter 6 to check isEmpty"      << std::endl;
        std::cout << "Enter 7 to print"              << std::endl;
        std::cout << "Enter 8 to switch structure"   << std::endl;

        if(usingArray) {
            std::cout << "Currently editing arrayQueue" << std::endl;
            std::cin >> select;
         
            switch(select) {
                case 1: 
                    std::cout << "Enter an int: ";
                    std::cin >> data;
                    arrayQue.enqueue(data);
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;} 
                    break;
                case 2:
                    try {
                        arrayQue.dequeue();
                    } catch(...) {
                        std::cout << "Caught an error" << std::endl;
                    }
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}
                    break;
                case 3:
                    std::cout << "Size: " << arrayQue.size() << std::endl;
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}
                    break;
                case 4:
                    std::cout << "Capacity: " << arrayQue.capacity() << std::endl;
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}
                    break;
                case 5:
                    std::cout << "isFull: " << arrayQue.isFull() << std::endl;
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}
                    break;
                case 6:
                    std::cout << "isEmpty: " << arrayQue.isEmpty() << std::endl;
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}                    
                    break;
                case 7: 
                    arrayQue.print();
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}
                    break;
                case 8:
                    usingArray = !usingArray;
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}                    
                    break;
                default:
                    std::cout << "Did nothing" << std::endl;
                    std::cout << "Would you like to continue? 0 = NO and 1 = YES : ";
                    std::cin >> running; 
                    if(running == 0){std::cout << "Thank you!" << std::endl;}
                    break;
            }

        } 
    }

    return 0;
}
