/* File: test-RPC.cpp
 * Name: Jessica Grazziotin
 * Team: Sandwich
 * Date: 3/30/2017
 */

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "../Stack.h"
#include "../RPC.h"

using namespace std; 

int main(){
    //prompt user
    cout << "RPC: input a line in Reverse Polish Notation form:" << endl; 
    
    // get input
    string s; 
    // cin >> s;  
    getline (cin, s);
    cout << "---first received line: " << s << endl; 
    
    char *duplicate = strdup(s.c_str()); 
    char *token1;
    char delim[] = " ,.;'-?:!\t\n";
    token1 = strtok(duplicate, delim);
    

  while( token1 != NULL ) 
  {
    cout << "in while loop, token is: " << token1 << endl;
    token1 = strtok(NULL, delim);
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