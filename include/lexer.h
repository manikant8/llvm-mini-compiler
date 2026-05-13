#pragma once
#include <string>
#include<vector>

using namespace std;


enum TokenType{
    LET,
    PRINT,
    IDENT,
    NUMBER,
    PLUS,
    ASSIGN,
    SEMICOLON,
    END
};

struct Token {
    TokenType type;
    string value;
};

vector<Token> tokenize(const string& input);