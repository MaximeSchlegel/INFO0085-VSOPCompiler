#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


TimesNode::TimesNode(Node *left, Node *right) : BinOpNode(left, right){
    debugger->printCall("TimesNode::TimesNode");
    debugger->printEnd();
}

TimesNode::~TimesNode() {
    debugger->printCall("TimesNode::~TimesNode");
    debugger->printEnd();
}

void TimesNode::print(std::ostream &os) const {
    debugger->printCall("TimesNode::print");

    this->printBinOp(os, "*");

    debugger->printEnd();
}

void TimesNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("TimesNode::check");

    this->checkBinOp(ast_processor, "int32", "int32");

    debugger->printEnd();
}