#include<iostream>
#include "../include/lexer.h"
#include "../include/parser.h"
using namespace std;

int main(){
    string code = "let x = 5+6; print x;";
    vector<Token> tokens = tokenize(code);

    // To display tokens
    // for(auto &t : tokens){
    //     cout<<t.type<<" "<<t.value<<endl;
    // }

    Program* program = parse(tokens);
    cout << "Parsing Successful\n";
}