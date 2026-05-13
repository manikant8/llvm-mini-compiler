#pragma once
#include "lexer.h"   // parser needs token so it needs this file
#include "ast.h"     // parser creates AST so it needs this file
using namespace std;

Program* parse(vector<Token>& tokens);