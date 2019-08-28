#include "../headers/PlusNode.h"

PlusNode::PlusNode(Node *left, Node *right)
    : BinOpNode(left, right)
{
    debugger->print("PlusNode::PlusNode");
    debugger->printEnd();
}

PlusNode::~PlusNode()
{
    debugger->print("lusNode::~PlusNode");
    debugger->printEnd();
}

void PlusNode::print(std::ostream &os) const
{
    debugger->print("PlusNode::print");

    this->printBinOp(os, "+");

    debugger->printEnd();
}

void PlusNode::check(ASTProcessor *ast_processor) {
    debugger->print("PlusNode::check");

    this->checkBinOp(ast_processor, "int32", "int32");

    debugger->printEnd();
}

llvm::Value *PlusNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("PlusNode::codeGen");

    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateFAdd(leftValue, rightValue, "plustmp");
}
