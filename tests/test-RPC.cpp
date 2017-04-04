/* File: test-RPC.cpp
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include "../Stack.h"
#include "../RPC.h"

using namespace std; 

float number_check(char* c);

int main(){
    //declarations
    ee::list::Stack<int> k(100); // big stack for number inputs
    string s; //string for tokenizer

    //prompt user
    cout << "RPC: input a line in Reverse Polish Notation form:" << endl; 

    
    // get input
    getline (cin, s);
    cout << "---first received line: " << s << endl; 
    char *duplicate = strdup(s.c_str());  //strdup duplicates the string "s" into a char pointer (see token = strtok)
    char *token; 
    char delim[] = " ,;'?:_!@#$&|[]{}~=\t\n"; //common test delimeters
    //separate the first token 
    token = strtok(duplicate, delim); // by using the duplicate char* we can use the c function strtok
    while( token != NULL ){ //
        cout << "in while loop, token is: " << token << endl; //debug
        token = strtok(NULL, delim); //continue to seperate the remainder of the string (I have no idea how it knows to keep seperating duplicate?)
        
        //send token to a char checker
        number_check(token);
    }
    free(duplicate); 
    
    
    //check if its a #
        // if true - push
        
        
    
    //check if its an op
        // if true - pop 2 numbers
        // perform op
    
    //error checking
    

    return 0; 
}


float number_check(char* c){
    char temp = *c;
    float f;
    if (isdigit(temp)){
        // f = atof (*c);  
        cout << "is digit" << endl; 
        return f=1; 
    }
    cout << "---not a float" << endl; 
    return -1; 
}








    // k.push(1);
    // k.pop();
    // if (k.isEmpty()){
    //     cout << "stack is empty" << endl;
    // }