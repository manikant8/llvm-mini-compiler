#include<cctype>
#include "../include/lexer.h"
using namespace std;

// "  let x = 5 + 6; print x;"
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

            if(lexeme_ID == "let" || lexeme_ID == "print") tokens.push_back({KEYWORD, lexeme_ID});
            else{
                tokens.push_back({IDENTIFIER ,lexeme_ID});
            }
        }

        else if(isdigit(input[i])){
            string lexeme_NUM = "";
            while(isdigit(input[i])) lexeme_NUM += input[i++];
            tokens.push_back({INTEGER, lexeme_NUM});
        }

        else{
            switch(input[i]){
                case '+': tokens.push_back({OPERATOR, "+"}); break;
                case '=': tokens.push_back({OPERATOR, "="}); break;
                case ';': tokens.push_back({PUNCTUATION, ";"});
            }
            i++;
        }
    }

    return tokens;
}