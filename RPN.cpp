//RPN.cpp
//Matthew Yamamoto
//4/2/17


#include"Stack.h"
#include<string.h>
#include<iostream>

using namespace std;


int main(){
	string s1;
	string s2;
	ee::list::Stack<string> stack(4);

	cout << endl << "Input in Reverse Polish Notation" << endl;
	getline(cin, s1);
	
	for(string::iterator it = s1.begin(); it != s1.end(); ++it){
		if(it == "0"){s2.push_back(*it);}
		if(it == "1"){s2.push_back(*it);}
		if(it == "2"){s2.push_back(*it);}
		if(it == "3"){s2.push_back(*it);}
		if(it == "4"){s2.push_back(*it);}
		if(it == "5"){s2.push_back(*it);}
		if(it == "6"){s2.push_back(*it);}
		if(it == "7"){s2.push_back(*it);}
		if(it == "8"){s2.push_back(*it);}
		if(it == "9"){s2.push_back(*it);}

	}
	cout << s2 << endl;	

	//parse into stack
	//
	//do math
	//
	//print
}
