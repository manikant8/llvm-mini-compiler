#include <iostream>
#include <unordered_set>
#include "../include/semantic.h"
using namespace std;

// **************** Symbol Table ******************
unordered_set<string> symbolTable;

// **************** Analyze Node ******************
void analyze(ASTNode* node){

    // ---------------- NUMBER ----------------
    if(dynamic_cast<Number*>(node)) return;

    // ---------------- VARIABLE USAGE ----------------
    if(auto v = dynamic_cast<Variable*>(node)){

         // variable must already exist
        if(!symbolTable.count(v -> name)){
            cout << "Semantic Error: Undeclared Variable" << v -> name << endl;
            exit(1);
        }
        return;
    }

    // ---------------- BINARY OP ----------------
    if(auto b = dynamic_cast<BinaryOp*>(node)){
        analyze(b -> left);
        analyze(b -> right);
        return;
    }

    // ---------------- VARIABLE DECLARATION ----------------
    if(auto d = dynamic_cast<VarDecl*>(node)){
        
        // check RSH expression first
        analyze(d -> expr);

        // redeclaration check
        if(symbolTable.count(d -> name)){
            cout << "Semantic Error: Variable already declared "<< d -> name << endl;
            exit(1);
        }

         // officially declare variable
         symbolTable.insert(d -> name);
         return;
    }


    // ---------------- ASSIGNMENT ----------------
    if(auto a = dynamic_cast<Assignment*>(node)){

        // analyze RHS expression
        analyze(a -> expr);

        // assignment only allowed if variable exists
        if(!symbolTable.count(a -> name)){
            cout << "Semantic Error: Assignment to undeclared variable " << a -> name << endl;
            exit(1);
        }
        return;
    }

    // ------------------- PRINT --------------------
    if(auto p = dynamic_cast<Print*>(node)){
        analyze(p -> expr);
        return;
    }
}


// //******************************** PROGRAM (Semantic Analysis) ********************************//
void analyzeProgram(Program* program){
    for(auto stmt : program -> statements){
        analyze(stmt);
    }

    cout << "Semantic Analysis Successful!" << endl;
}



