#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


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