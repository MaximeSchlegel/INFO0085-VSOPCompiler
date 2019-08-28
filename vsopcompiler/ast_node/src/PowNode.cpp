#include "../headers/PowNode.h"

PowNode::PowNode(Node *left, Node *right)
    : BinOpNode(left, right)
{
    debugger->print("PowNode::PowNode");
    debugger->printEnd();
}

PowNode::~PowNode()
{
    debugger->print("PowNode::~PowNode");
    debugger->printEnd();
}

void PowNode::print(std::ostream &os) const
{
    debugger->print("PowNode::print");

    this->printBinOp(os, "^");

    debugger->printEnd();
}

void PowNode::check(ASTProcessor *ast_processor)
{
    debugger->print("PowNode::check");

    this->checkBinOp(ast_processor, "int32", "int32");

    debugger->printEnd();
}

llvm::Value *PowNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("PowNode::codeGen");

    llvm::Value *leftValue = this->left->codeGen(ast_processor);

    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateFMul(leftValue, rightValue, "powtmp"); // TODO Find the proper function
}
