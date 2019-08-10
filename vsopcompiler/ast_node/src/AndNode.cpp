#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"

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
    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    llvm::IRBuilder<> builder = ast_processor->llvmBuilder;
    return builder.CreateAnd(leftValue, rightValue, "andtmp");
}
