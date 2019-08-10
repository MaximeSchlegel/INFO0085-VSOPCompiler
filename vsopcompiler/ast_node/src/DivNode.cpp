#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


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
    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    llvm::IRBuilder<> builder = ast_processor->llvmBuilder;
    return builder.CreateFDiv(leftValue, rightValue, "divtmp");
}
