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
#include "Stack.h"
#include "RPC.h"



float calculator(char *c, ee::list::Stack<float> * stack);


int main(){
    //declarations
    ee::list::Stack<float> k(100); // big stack for number inputs
    string s; //string for tokenizer
    float output; 

    //prompt user
    prompt(); // RPC.h
    std::cout << "Check out our test file to watch the stack" << std::endl; 

    // get input
    getline (cin, s);
    std::cout << "Input received: " << s << std::endl; 
    char *duplicate = strdup(s.c_str());  //strdup duplicates the string "s" into a char pointer (see token = strtok)
    char *token; 
    char delim[] = " ,;'?:_!@#$&|[]{}~=()\t\n"; //common test delimeters

    //separate the first token 
    token = strtok(duplicate, delim); // by using the duplicate char* we can use the c function strtok

    // while there's still more tokens
    while( token != NULL ){ 
        output = calculator(token, &k); //send them to the calculator
        if (isnan(output)){ //check for an error output and quit
            return 0; 
        }
        token = strtok(NULL, delim); //continue to seperate the remainder of the string (I have no idea how it knows to keep seperating duplicate?)
    }

    free(duplicate); //release the duplicate string
    std::cout << "Final Answer: "<< std::endl; 
    std::cout << "---> " << output << std::endl; 

    //error checking

    return 0; 
}




//similar to checker from B. Stroustrup's file but using our personal stack
float calculator(char *c, ee::list::Stack<float>* stack){
    float f, a, b;  
    string temp;
    int int_valueA, int_valueB; 

    switch (*c){
        case '-': // - IS FOR NEGATIVE NUMBERS
            temp = c; //convert c to string
            if (check_negative(temp)){ //RPC.h
                std::cout << "true" << std::endl;
                f = number_check(temp, 1); //RPC.h
                if (isnan(f)== 0) stack->push(f);
            }
            else { // - is for an operation    
                b = stack->pop();
                if (stack->isEmpty() == true){ 
                    std::cout << "Error: at input format" << std::endl;
                    f = NAN; 
                    break; 
                }
                a = stack->pop(); 
                f = a - b; 
                stack->push(f);
            }
            break;

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
        case '9':{ // case # is found:
                     temp = c; //convert c to string
                     f = number_check(temp, 0); //RPC.h
                     if (isnan(f)== 0) stack->push(f);
                     break; 
                 }

                 // case it's an operation (see minus above)
        case '+': 
                 b = stack->pop(); //pop first val to a temp
                 if (stack->isEmpty() == true){ // this means there were only 1 or 0 things in the stack before the operation
                     std::cout << "Error: at input format" << std::endl;
                     f = NAN; 
                     break; 
                 }
                 a = stack->pop(); //pop second val to a temp
                 f = a + b;  // perform function
                 stack->push(f); //push result back
                 break;
        case '*': // ------ see case + for notes
                 b = stack->pop(); 
                 if (stack->isEmpty() == true){ 
                     std::cout << "Error: at input format" << std::endl;
                     f = NAN; 
                     break; 
                 }
                 a = stack->pop(); 
                 f = a * b; 
                 stack->push(f);
                 break;
        case '/': // ------ see case + for notes
                 b = stack->pop();
                 if (b == 0){ 
                     std::cout << "cannot divide by zero" << std::endl;
                     f = NAN;
                     return f; 
                 }
                 if (stack->isEmpty() == true){ 
                     std::cout << "Error: at input format" << std::endl;
                     f = NAN; 
                     break; 
                 }
                 a = stack->pop(); 
                 f = a / b; 
                 stack->push(f);
                 break;
        case '%': // ------ see case + for notes
                 b = stack->pop();
                 int_valueB = (int)b; //convert float to int (% is an int op)
                 if (b == 0){ 
                     std::cout << "cannot '%' by zero" << std::endl;
                     f = NAN; 
                     return f; 
                 }
                 a = stack->pop(); 
                 int_valueA = (int)a; //convert float to int (% is an int op)
                 f = int_valueA % int_valueB;  
                 stack->push(f);
                 break;
                 // //run op funciton
        case '^': // ------ see case + for notes
                 b = stack->pop(); 
                 if (stack->isEmpty() == true){ 
                     std::cout << "Error: at input format" << std::endl;
                     f = NAN; 
                     break; 
                 }
                 a = stack->pop(); 
                 f = pow (a , b); //power or exponent function
                 stack->push(f);
                 break;
        default: {
                     std::cout << "Invalid Input " << c << std::endl;
                     f = NAN;
                     return f; 
                 }
    }
    return f; 
}
