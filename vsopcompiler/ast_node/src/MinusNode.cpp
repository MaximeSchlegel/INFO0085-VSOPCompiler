#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


MinusNode::MinusNode(Node *left, Node *right)
        : BinOpNode(left, right) {
    debugger->printCall("MinusNode::MinusNode");
    debugger->printEnd();

}

MinusNode::~MinusNode() {
    debugger->printCall("MinusNode::MinusNode");
    debugger->printEnd();
}

void MinusNode::print(std::ostream &os) const {
    debugger->printCall("MinusNode::MinusNode");

    this->printBinOp(os, "-");

    debugger->printEnd();
}

void MinusNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("MinusNode::MinusNode");

    this->checkBinOp(ast_processor, "int32", "int32");

    debugger->printEnd();
}