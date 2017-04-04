/* File: RPC.cpp
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

// #include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "../Stack.h"
#include "../RPC.h"
 
using namespace std; 

int main (){
    
    //simple tester
     
    char ch= 'i'; 
    Token t(ch,90);
    cout << "token: " << t.value << endl; 
    
    ee::list::Stack<int> s(2);
    cout << "stack capacity: " << s.capacity() << endl; 
    cout << "stack size: " << s.size() << endl; 
    cout << "...printing stack"<< endl;
    cout << "pushing 1, 2, 3 onto stack" << endl;
    s.push(1); s.push(2); s.push(3);
    s.print();
    cout << "Only " << s.capacity() << " fits!" << endl; 
    cout << "New stack size: " << s.size() << endl; 
    cout << "trying to push token on stack" << endl;
    s.push(t.value);
    s.print();
    cout << "didn't work because stack is full" << endl << endl;
    cout << "Try popping:" << endl;
    cout << "Popped element: " << s.pop() << endl; 
    s.print();
    cout << "trying to push token again" << endl;
    s.push(t.value);
    s.print();
    cout << "it worked!" << endl << endl;
}