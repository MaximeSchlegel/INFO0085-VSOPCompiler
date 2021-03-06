#include "../headers/LowerNode.h"


LowerNode::LowerNode(Node *left, Node *right)
    :BinOpNode(left, right) {
    debugger->printCall("LowerNode::LowerNode");
    debugger->printEnd();
}

LowerNode::~LowerNode() {
    debugger->printCall("LowerNode::~LowerNode");
    debugger->printEnd();
}

void LowerNode::print(std::ostream &os) const {
    debugger->printCall("LowerNode::print");

    this->printBinOp(os, "<");

    debugger->printEnd();
}

void LowerNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("LowerNode::check");

    this->checkBinOp(ast_processor, "bool", "int32");

    debugger->printEnd();
}

llvm::Value *LowerNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("LowerNode::codeGen");
    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateICmpULT(leftValue, rightValue, "lowertmp");
}
