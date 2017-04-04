
// #include "std_lib_facilities2.h"
#include "Og_stdlib_facilities.h"
using namespace std;
/*
Buggy Reverse Polish Calculator
Helpful comments removed.
We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#define DEBUG

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string n) :kind(ch), name(n) {} //jess- added this to fix error for line 73
};

class Token_stream {
    bool full;
    Token buffer;
    public:
    Token_stream() :full(0), buffer(0) { }
    Token get(); 
    void unget(Token t) { buffer = t; full = true; }
    void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get(){
    int count=0; 
    if (full) { 
        full = false; 
        return buffer; 
    }
    
    #ifdef DEBUG
    cout << "DEBUG here in Token_stream::get \n";
    #endif
    
    char ch;
    cin >> ch;
    switch (ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
            return Token(ch); //i should figureout how to pop before here
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
            // string str; 
            cin.unget();
            // Token(ch); 
            // getline (std::cin,str);
            double val;
            cin >> val;
            count++;
       
        #ifdef DEBUG
        cout << "DEBUG - case '.'-9: int is: " << count << endl; //count =1
        #endif
        
            return Token(number, val);
        }
        default:
            if (isalpha(ch)) {
                // count++; 
                // cout << "DEBUG - default: int is: " << count << endl; 
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))){
                    s = ch;  
                } 
                cin.unget();
                if (s == "let") return Token(let);
                if (s == "quit") return Token(quit); //changed this to quit
                return Token(name, s);
            }
            error("Bad token");
    }//end of switch
}//end of Token_stream::get function


void Token_stream::ignore(char c){
    if (full && c == buffer.kind) {
    full = false;
    return;
    }
    full = false;
    char ch;
    while (cin >> ch) //here? what's going on?
        if (ch == c) return;
}// end of Token_steam::ignore function


struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names; //declaration

double get_value(string s){
    for (int i = 0; i<names.size(); ++i)
    if (names[i].name == s) {
        return names[i].value;
    }    
    error("get: undefined name ", s);
} //end of get_value function

void set_value(string s, double d){
    for (int i = 0; i <= names.size(); ++i)
    if (names[i].name == s) {
        names[i].value = d;
        return;
    }
    error("set: undefined name ", s);
} //end of set_value function

bool is_declared(string s){
    for (int i = 0; i<names.size(); ++i)
    if (names[i].name == s) {
        return true;
    }
    return false;
} //end of is_declared function

Token_stream ts; //declaration
double expression(); //declaration

double primary(){
    #ifdef DEBUG
    cout << "DEBUG here inside primary()\n";
    #endif
    
    Token t = ts.get();
    switch (t.kind) {
        case '(':{ 
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("'(' expected");
        }
        case '-':
            return -primary();
        case number:
            return t.value;
        case name:
            return get_value(t.name);
        default:
            error("primary expected");
    }
} //end of primary function

double term(){
    #ifdef DEBUG
    cout << "DEBUG here inside term()\n";
    #endif
    
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':{
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                break;
            }
            default:
                ts.unget(t);
                return left;
        }
    }
} //end of term function

double expression(){
    #ifdef DEBUG
    cout << "DEBUG here inside expression()\n";
    #endif
    
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.unget(t);
                return left;
        }
    }
}//end of expression function

double declaration(){
    #ifdef DEBUG
    cout << "DEBUG here inside declaration()\n";
    #endif
    
    Token t = ts.get();
    if (t.kind != 'a') error("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);
    double d = expression();
    names.push_back(Variable(name, d));
    return d;
}//end of declaration function

double statement(){
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.unget(t);
            return expression();
    }
} //end of statement function

void clean_up_mess(){
    ts.ignore(print);
}

#ifdef DEBUG
const string prompt = "DEBUG prompt symbol: \n> "; //declaration
const string result = "DEBUG result symbol: \n= ";//declaration
#else
const string prompt = "> "; //declaration
const string result = "= ";//declaration
#endif

void calculate(){
    int count =0; //moved up here above while
    while (true) try {
        // int count =0; //from original
        cout << prompt;
        
        #ifdef DEBUG
        cout << "\nDEBUG here inside calculate, before get\n";
        #endif
        
        Token t = ts.get();
        count++; 
        
        #ifdef DEBUG
        cout << "DEBUG here inside calculate, after token: count is: " << count << endl; 
        #endif

        if (t.kind == print){ //changed this from while to if
            t = ts.get();  
            count++; 
            
            #ifdef DEBUG
            cout << "DEBUG here inside calculate, while: int is: " << count << endl;
            #endif
        } 
        else if (t.kind == quit) return; //changed this from if to else if
        
        #ifdef DEBUG
        cout << "DEBUG here inside calculate, before ts.unget(t)\n";
        #endif
        
        ts.unget(t);
        cout << result << statement() << endl;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
} //end of calculate function

//#########################  MAIN ##########################

int main() {
    int count = 0;
    cout << "RPC.cpp: \n";
    cout << "#######    TASK 2 STATUS:   ########\n";
    cout << "---LIST OF BUGS FOUND: \n";
    cout << "Compile errors: \n";
    cout << "end curly for the main, Token constructor with char & string argument, must compile in c++11\n";
    cout << "Algorithm errors: \n";
    cout << "Right now it's basically storing the 1st element into result,\n";
    cout << "then using the next 2 of the first prompt and executing the function with\n";
    cout << "the 1st element of the next prompt\n";
    cout << "example: \n";
    cout << "> 8 9 -\n";
    cout << "result= 8 (1st element, no function)\n";
    cout << "> 3 7 +\n";
    cout << "result= 6 ( last 2 elements with 1st of the next: 9-3=6)\n";
    cout << "\nNot finished but through debug statements I can follow the flow: \n";
    cout << "calculate, expression, term, primary, token steam: get\n";
    cout << "I tried playing with the number of times it 'gets' and 'ungets' but I couldn't fix it\n";
    cout << "**uncomment line 10 (#define DEBUG) to see debug statements\n\n";
    
    try {


        calculate();
        cout << "returning\n";
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c&& c != ';');
            return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
    
}// end of main
