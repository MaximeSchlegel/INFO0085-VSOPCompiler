#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


PlusNode::PlusNode(Node *left, Node *right)
        : BinOpNode(left, right) {
    debugger->print("PlusNode::PlusNode");
    debugger->printEnd();
}

PlusNode::~PlusNode() {
    debugger->print("lusNode::~PlusNode");
    debugger->printEnd();
}

void PlusNode::print(std::ostream &os) const {
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
    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    llvm::IRBuilder<> builder = ast_processor->llvmBuilder;
    return builder.CreateFAdd(leftValue, rightValue, "plustmp");
}
