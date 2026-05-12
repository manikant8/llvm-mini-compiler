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
    ASTNode* left;
    ASTNode* right;
    BinaryOp(ASTNode* l, ASTNode* r) : left(l), right(r) {}
};