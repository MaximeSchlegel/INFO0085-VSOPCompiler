#include "../headers/DivNode.h"


DivNode::DivNode(Node *left, Node *right)
        : BinOpNode(left, right) {
    debugger->print("DivNode::DivNode");
    debugger->printEnd();
}

DivNode::~DivNode() {
    debugger->print("DivNode::~DivNode");
    debugger->printEnd();
}

void DivNode::print(std::ostream &os) const {
    debugger->print("DivNode::print");

    this->printBinOp(os, "/");

    debugger->printEnd();
}

void DivNode::check(ASTProcessor *ast_processor) {
    debugger->print("DivNode::check");

    this->checkBinOp(ast_processor, "int32", "int32");

    debugger->printEnd();
}

llvm::Value *DivNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("DivNode::codeGen");

    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateFDiv(leftValue, rightValue, "divtmp");
}
