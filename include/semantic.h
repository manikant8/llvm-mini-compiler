#include<vector>
#include "ast.h"

// analyze the entire program, which is a structutre of type Program
void analyzeProgram(Program*);

// analyze each statement(---) of statement vector
void analyze(vector<ASTNode*>); 