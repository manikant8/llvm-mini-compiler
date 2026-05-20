#include<iostream>
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/semantic.h"
using namespace std;

int main(){
    string code = "let x = 5+6; y = 8+9; print x; ";

    // *************************** LEXER *******************************//
    vector<Token> tokens = tokenize(code);

    // To display tokens
    cout << "Tokens Generated <Token Type, Token>: " << endl;
    for(auto &t : tokens){
        cout<<t.type<<" "<<t.value<<endl;
    }
    cout << endl;

    // *************************** PARSER  *******************************//
    Program* program = parse(tokens);
    cout << "Parsing is Successful\n" << endl;

    // *************************** SEMANTIC ANALYSIS *******************************//
    analyzeProgram(program);


}