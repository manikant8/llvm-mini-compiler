#pragma once
using namespace std;

struct ASTNode{
    virtual ~ASTNode() {}
};

struct Number : ASTNode {
    int value;
    Number(int v) : value(v) {}
};

struct Variable : ASTNode {
    string name;
    Variable(string n) : name(n) {}
};

struct BinaryOp : ASTNode {
    string op;
    ASTNode* left;
    ASTNode* right;
    BinaryOp(string o, ASTNode* l, ASTNode* r) : op(o), left(l), right(r) {}
};

struct Assignment : ASTNode {
    string name;
    ASTNode* expr;
    Assignment(string n, ASTNode* e) : name(n), expr(e) {}
};

struct Print : ASTNode {
    ASTNode* expr;
    Print(ASTNode* e) : expr(e) {}
};

struct Program : ASTNode {
    vector<ASTNode*> statements;
};