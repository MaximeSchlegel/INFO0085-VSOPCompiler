#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


IntLiteralNode::IntLiteralNode(int value)
        : Node() {
    debugger->printCall("IntLiteralNode::IntLiteralNode");

    this->value = value;

    debugger->printEnd();
}

IntLiteralNode::~IntLiteralNode() {
    debugger->printCall("IntLiteralNode::~IntLiteralNode");
    debugger->printEnd();
}

bool IntLiteralNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("IntLiteralNode::doesSubTreeContains");

    debugger->printEnd();
    return false;
}

void IntLiteralNode::print(std::ostream &os) const {
    debugger->printCall("IntLiteralNode::print");

    os << this->value;
    if (this->getReturnType()) {
        os << " : int32";
    }

    debugger->printEnd();
}

void IntLiteralNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("IntLiteralNode::check");

    this->setReturnType(new std::string("int32"));

    debugger->printEnd();
}

llvm::Value * IntLiteralNode::codeGen(ASTProcessor *ast_processor) {
    return llvm::ConstantInt::get(ast_processor->llvmContext, llvm::APInt(32, this->value));
}