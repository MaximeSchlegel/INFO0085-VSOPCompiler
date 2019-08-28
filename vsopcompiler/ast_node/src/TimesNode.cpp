#include "../headers/TimesNode.h"

TimesNode::TimesNode(Node *left, Node *right) : BinOpNode(left, right)
{
    debugger->printCall("TimesNode::TimesNode");
    debugger->printEnd();
}

TimesNode::~TimesNode()
{
    debugger->printCall("TimesNode::~TimesNode");
    debugger->printEnd();
}

void TimesNode::print(std::ostream &os) const
{
    debugger->printCall("TimesNode::print");

    this->printBinOp(os, "*");

    debugger->printEnd();
}

void TimesNode::check(ASTProcessor *ast_processor)
{

void TimesNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("TimesNode::check");

    this->checkBinOp(ast_processor, "int32", "int32");

    debugger->printEnd();
}

llvm::Value *TimesNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("TimesNode::codeGen");

    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateFMul(leftValue, rightValue, "timestmp");
}
