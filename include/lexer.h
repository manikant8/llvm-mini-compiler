#include <string>
#include<vector>
using namespace std;


enum TokenType{
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    INTEGER,
    PUNCTUATION
};

struct Token {
    TokenType type;
    string value;
};

vector<Token> tokenize(const string& input);