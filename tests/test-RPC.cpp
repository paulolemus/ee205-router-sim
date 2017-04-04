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
#include <math.h>
#include "../Stack.h"
#include "../RPC.h"

using namespace std; 

float number_check(string s);
float general_token_check(char *c, ee::list::Stack<float> * stack);

int main(){
    //declarations
    ee::list::Stack<float> k(100); // big stack for number inputs
    string s; //string for tokenizer
    float output; 
    //prompt user
    cout << "RPC: input a line in Reverse Polish Notation form:" << endl; 
    cout << "-----IMPORTANT: seperate each input by a space ' ' -----" << endl; 
    cout << "Correct: 2 4 3 - +     Error: 243-+" <<endl; 
    cout << "Correct: 1 4 /        Error: 1/4 or 1 4/" <<endl; 
    
    // get input
    getline (cin, s);
    cout << "---first received line: " << s << endl; 
    char *duplicate = strdup(s.c_str());  //strdup duplicates the string "s" into a char pointer (see token = strtok)
    char *token; 
    char delim[] = " ,;'?:_!@#$&|[]{}~=()\t\n"; //common test delimeters
    //separate the first token 
    token = strtok(duplicate, delim); // by using the duplicate char* we can use the c function strtok
    while( token != NULL ){ //
        //send token to a char checker
        output = general_token_check(token, &k);
        cout << "output is : "<< output << endl; 
        k.print();
        // number_check(token);
        // cout << "in while loop, token is: " << token << endl ; //debug
        token = strtok(NULL, delim); //continue to seperate the remainder of the string (I have no idea how it knows to keep seperating duplicate?)
        cout << endl << endl; 
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

float general_token_check(char *c, ee::list::Stack<float>* stack){
    
    float f, a, b;  
    // int int_valueB, int_valueA; 
    switch (*c){
        // case '-': // - IS FOR NEGATIVE NUMBERS
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':{
            // cout << "Number found? " << c << endl;
            string temp = c; 
            // cout << "Temp is " << temp << endl;
            f = number_check(temp);
            if (f >= 0) stack->push(f);
            break; 
        }
        case '+': 
            b = stack->pop();
            if (stack->isEmpty() == true){ // this means there were only 1 or 0 things in the stack before the operation
                cout << "Error at input" << endl;
                break; 
            }
            a = stack->pop(); 
            f = a + b; 
            stack->push(f);
            break;
        case '-':
            b = stack->pop();
            if (stack->isEmpty() == true){ 
                cout << "Error at input" << endl;
                break; 
            }
            a = stack->pop(); 
            f = a - b; 
            stack->push(f);
            break;
        case '*':
            b = stack->pop(); 
            if (stack->isEmpty() == true){ 
                cout << "Error at input" << endl;
                break; 
            }
            a = stack->pop(); 
            f = a * b; 
            stack->push(f);
            break;
        case '/':
            b = stack->pop();
            if (b == 0){ 
                cout << "cannot divide by zero" << endl;
                return 0; 
            }
            if (stack->isEmpty() == true){ 
                cout << "Error at input" << endl;
                break; 
            }
            a = stack->pop(); 
            f = a / b; 
            stack->push(f);
            break;
        case '%':
            cout << " '%' not working for now due to the float to int conversion" << endl; 
            // b = stack->pop();
            // int_valueB = (std::round(b));
            // if (b == 0){ 
            //     cout << "cannot '%' by zero" << endl;
            //     return 0; 
            // }
            // a = stack->pop(); 
            // int_valueA = (std::round(a));
            // f = int_valueA % int_valueB;  
            // stack->push(f);
            break;
            // //run op funciton
        case '^':
            b = stack->pop(); 
            if (stack->isEmpty() == true){ 
                cout << "Error: at input format" << endl;
                break; 
            }
            a = stack->pop(); 
            f = pow (a , b); 
            stack->push(f);
            break;
        default: cout << "Invalid Input " << c << endl;
    }
    return f; 
}


float number_check(string s){
    const char* temp = s.c_str();
    float f;
    if (isdigit(temp[0])){
        f = atof (temp);  
        // cout << "is digit: " << temp << endl; 
        return f; 
    }
    // cout << "---not a float" << endl; 
    return f = -1; 
}








    // k.push(1);
    // k.pop();
    // if (k.isEmpty()){
    //     cout << "stack is empty" << endl;
    // }