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



    




////// Stuff I was playing with earlier --- some works some doesnt : /

            // for (int i=0; i < inputA.length() ; i++){
            //     while (inputA != '\n' || inputA != ' '){
            //         if(inputA == '.'){
            //             std::cout << "dot" << endl; 
            //         }
            // 
                // // std::string inputA; 
    // char inputA; 
    // while(true){
    //     std::cout << "Input the first number: "; 
    //     std::cin >> inputA; 
        
    //     if (isalpha(inputA)){
    //         std::cout << "Letters are not accepted" << std::endl; 
    //     }
    //     else if (isdigit(inputA)){
    //         int n_inputA = stoi(inputA, NULL, 10);    
    //         std::cout << inputA << " worked!" << std::endl; 
    //         cout << n_inputA << " is the int version" << endl; 
    //     }
    //     else if (inputA == '+'){
    //             std::cout << "it's a plus" << std::endl; 
    //         }
            
    //     else {
    //         std::cout << "none of the above" << std::endl;
    //     }
    
    
#endif