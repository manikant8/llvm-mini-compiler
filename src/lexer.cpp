#include<cctype>
#include "../include/lexer.h"
using namespace std;

// lexeme_ID : Identifier type lexeme
// lexeme_NUM: Number type lexeme

// "let x = 5 + 6; y = 8 + 9; print x;"
vector<Token> tokenize(const string& input){
    vector<Token> tokens;
    for(int i = 0; i < input.size(); ){
        
        // ignoring the spaces in input string
        if(isspace(input[i])) {
            i++;
            continue;
        }

        if(isalpha(input[i])){
            string lexeme_ID = "";
            while(isalpha(input[i])) lexeme_ID += input[i++];
            
            if(lexeme_ID == "let") tokens.push_back({LET, lexeme_ID});
            else if(lexeme_ID == "print") tokens.push_back({PRINT, lexeme_ID});
            else{
                tokens.push_back({IDENT, lexeme_ID});
            }
        }

        else if(isdigit(input[i])){
            string lexeme_NUM = "";
            while(isdigit(input[i])) lexeme_NUM += input[i++];
            tokens.push_back({NUMBER, lexeme_NUM});
        }

        else{
            switch(input[i]){
                case '+': tokens.push_back({PLUS, "+"}); break;
                case '=': tokens.push_back({ASSIGN, "="}); break;
                case ';': tokens.push_back({SEMICOLON, ";"});
            }
            i++;
        }
    }
    tokens.push_back({END, ""});
    return tokens;
}