#include "../include/parser.h"
#include<iostream>

int pos = 0;
vector<Token>* toks;

// ---------------- CURRENT TOKEN ----------------
Token current(){
    return (*toks)[pos];
}

// ---------------- EXPECT ----------------
void expect(TokenType type){
    if(current().type != type){
        cout << "Unexpected Token: " << current().value << "\n";
        exit(1);
    }
    pos++;
}

// ---------------- PRIMARY ----------------
ASTNode* parsePrimary(){
    Token t = current();

    // NUMBER
    if(t.type == NUMBER){
        pos++;
        return new Number(stoi(t.value));
    }

    // IDENTIFIER
    if(t.type == IDENT){
        pos++;
        return new Variable(t.value);
    }

    cout << "Invalid Expression \n";
    exit(1);
}

// ---------------- EXPRESSION ----------------
ASTNode* parseExpr(){
    ASTNode* left = parsePrimary();
    while(current().type == PLUS){
        pos++;
        ASTNode* right = parsePrimary();
        left = new BinaryOp("+", left, right);
    }
    return left;
}

// ---------------- ASSIGNMENT ----------------
// ASTNode* parseAssignment(){
//     expect(LET);
//     string name = current().value;
//     expect(IDENT);
//     expect(ASSIGN);
//     ASTNode* expr = parseExpr();
//     expect(SEMICOLON);
//     return new Assignment(name, expr);
// }

// ---------------- ASSIGNMENT (parse x without declaration, x = 5+6) ----------------
ASTNode* parseAssignment(){
    // expect(LET);
    string name = current().value;
    expect(IDENT);
    expect(ASSIGN);
    ASTNode* expr = parseExpr();
    expect(SEMICOLON);
    return new Assignment(name, expr);
}

// will parse Let x = 5+6 (parse x with declaration (let))
ASTNode* parseDeclaration(){
    expect(LET);
    string name = current().value;
    expect(IDENT);
    expect(ASSIGN);
    ASTNode* expr = parseExpr();
    expect(SEMICOLON);
    return new VarDecl(name, expr);
}

// ---------------- PRINT ----------------
ASTNode* parsePrint(){
    expect(PRINT);
    ASTNode* expr = parseExpr();
    expect(SEMICOLON);
    return new Print(expr);
}

// ---------------- STATEMENT ----------------
ASTNode* parseStatement(){
    if(current().type == LET) return parseDeclaration();
    
    if(current().type == IDENT) return parseAssignment();

    if(current().type == PRINT) return parsePrint();

    cout<< "Unknown Statement\n";
    exit(1);
}

// ---------------- PROGRAM ----------------
Program* parse(vector<Token>& tokens){
    toks = &tokens;
    pos = 0;
    Program* program = new Program();

    while(current().type != END){
        program -> statements.push_back(
            parseStatement()
        );
    }
    return program;
}