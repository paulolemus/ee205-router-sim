/* File: RPC_.h
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

/* This file will read the inputs as strings 
 * and then check if each item is a digit, operator, or not
 */
 
#ifndef RPC_H_
#define RPC_H_ 
 
#include <iostream>       // std::cout
#include <string>         // std::string
#include <ctime>
#include <cstdlib>

using namespace std; 

    struct Token {
        char kind;
        double value;
        string name;
        Token(char ch) :kind(ch), value(0) { }
        Token(char ch, double val) :kind(ch), value(val) { }
        Token(char ch, string n) :kind(ch), name(n) {} //jess- added this to fix error for line 73
    };

    //not sure if this is needed, was the "stack / buffer-ish thing" in OG_RPC
    class Token_stream {
        bool full;
        Token buffer;
        public:
        Token_stream() :full(0), buffer(0) { }
        Token get(); 
        void unget(Token t) { buffer = t; full = true; }
        void ignore(char);
    };

void prompt (){
    cout << "RPC: input a line in Reverse Polish Notation form:" << endl; 
    cout << "-----IMPORTANT: separate each input by a space ' ' -----" << endl; 
    cout << "Correct: 2 4 3 - +     Error: 243-+ or 2 4 3- +" <<endl; 
    cout << "Correct: 1 44 /        Error: 1/44 or 1 44/" <<endl; 
    cout << "Possible operations: + - * / ^ modulus    Possible inputs: floating point numbers" << endl; 
}

float number_check(string s, bool i){ //boolean is for negative numbers
    const char* temp = s.c_str();
    float f;
    if (i == false){    // if its positive start at beginning
        if (isdigit(temp[0])){
            f = atof (temp);  
            // cout << "is non negative digit: " << temp << endl; //debug
            return f; 
        }
    }
    if (i == true){ //if check if its a digit at the second number
        if (isdigit(temp[1])){
            f = atof (temp);  
            // cout << "is negative digit: " << temp << endl; //debug
            return f; 
        }
    }
    // cout << "---not a float" << endl; //debug
    return f = NAN; 
}

bool check_negative(string s){
    const char* temp = s.c_str();
    float f=0;
    // cout << "temp string is: " << temp << endl; //debug
    if (isdigit(temp[1])){
        // cout << "---is negative digit: " << temp << endl; //debug
        f = atof (temp);
        // cout << "--- f = " << f << endl; //debug
        return 1; 
    }
    f = f; 
    // cout << "---not a neg digit" << endl; //debug
    return 0; 
}

    

    
    
#endif