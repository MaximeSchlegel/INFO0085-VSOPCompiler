#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


LowerEqualNode::LowerEqualNode(Node *left, Node *right)
        : BinOpNode(left, right) {
    debugger->print("LowerEqualNode::LowerEqualNode");
    debugger->printEnd();

}

LowerEqualNode::~LowerEqualNode() {
    debugger->print("LowerEqualNode::~LowerEqualNode");
    debugger->printEnd();
}

void LowerEqualNode::print(std::ostream &os) const {
    debugger->print("LowerEqualNode::print");

    this->printBinOp(os, "<=");

    debugger->printEnd();
}

void LowerEqualNode::check(ASTProcessor *ast_processor) {
    debugger->print("LowerEqualNode::check");

    this->checkBinOp(ast_processor, "bool", "int32");

    debugger->printEnd();
}

llvm::Value *LowerEqualNode::codeGen(ASTProcessor *ast_processor)
{
    llvm::Value *leftValue = this->left->codeGen(ast_processor);
    llvm::Value *rightValue = this->right->codeGen(ast_processor);

    if (!leftValue || !rightValue)
    {
        return nullptr;
    }

    llvm::IRBuilder<> builder = ast_processor->llvmBuilder;
    return builder.CreateICmpULE(leftValue, rightValue, "lowerequaltmp");
}
