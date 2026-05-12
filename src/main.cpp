#include<iostream>
#include "../include/lexer.h"
#include "../include/parser.h"
using namespace std;

int main(){
    string code = "let x = 5+6; print x;";
    auto token = tokenize(code);

    // To display tokens
    // for(auto &t : token){
    //     cout<<t.type<<" "<<t.value<<endl;
    // }

    ASTNode* tree = parse(token);
}