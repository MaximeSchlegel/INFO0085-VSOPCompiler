#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


BoolLiteralNode::BoolLiteralNode(bool value)
        : Node() {
    debugger->printCall("BoolLiteralNode::BoolLiteralNode");
    this->value = value;
    debugger->printEnd();
}

BoolLiteralNode::~BoolLiteralNode() {
    debugger->printCall("BoolLiteralNode::~BoolLiteralNode");
    debugger->printEnd();
}

bool BoolLiteralNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("BoolLiteralNode::doesSubTreeContains : id=" + *id);
    debugger->printEnd();
    return false;
}

void BoolLiteralNode::print(std::ostream &os) const {
    if (this->value) {
        os << "true";
    } else {
        os << "false";
    }

    if (this->getReturnType()) {
        os << " : bool";
    }
}

void BoolLiteralNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("BoolLiteralNode::check");

    this->setReturnType(new std::string("bool"));

    debugger->printEnd();
}

llvm::Value * BoolLiteralNode::codeGen(ASTProcessor *ast_processor) {
    return llvm::ConstantInt::get(ast_processor->llvmContext, llvm::APInt(1, this->value));
}