#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


EqualNode::EqualNode(Node *left, Node *right)
        : BinOpNode(left, right) {
    debugger->print("EqualNode::EqualNode");
    debugger->printEnd();
}

EqualNode::~EqualNode() {
    debugger->print("EqualNode::~EqualNode");
    debugger->printEnd();
}

void EqualNode::print(std::ostream &os) const {
    debugger->print("EqualNode::print");

    this->printBinOp(os, "=");

    debugger->printEnd();
}

void EqualNode::check(ASTProcessor *ast_processor) {
    debugger->print("EqualNode::check");

    this->checkBinOp(ast_processor, "bool");

    debugger->printEnd();
}

llvm::Value *EqualNode::codeGen(ASTProcessor *ast_processor)
{
    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    llvm::IRBuilder<> builder = ast_processor->llvmBuilder;
    return builder.CreateICmpEQ(leftValue, rightValue, "equaltmp");
}
