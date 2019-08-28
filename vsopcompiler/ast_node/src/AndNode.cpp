#include "../headers/AndNode.h"

AndNode::AndNode(Node *left, Node *right)
    : BinOpNode(left, right)
{
    debugger->printCall("AndNode::AndNode");
    debugger->printEnd();
}

AndNode::~AndNode()
{
    debugger->printCall("AndNode::~AndNode");
    debugger->printEnd();
}

void AndNode::print(std::ostream &os) const
{
    debugger->printCall("AndNode::print");

    this->printBinOp(os, "and");

    debugger->printEnd();
}

void AndNode::check(ASTProcessor *ast_processor)
{
    debugger->printCall("AndNode::check");

    this->checkBinOp(ast_processor, "bool", "bool");

    debugger->printEnd();
}

llvm::Value *AndNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("AndNode::codeGen");

    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateAnd(leftValue, rightValue, "andtmp");
}
