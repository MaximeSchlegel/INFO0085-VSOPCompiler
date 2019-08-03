#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


UnOpNode::UnOpNode(Node *expr)
        : Node() {
    debugger->printCall("UnOpNode::UnOpNode");

    this->expression = expr;

    debugger->printEnd();
}

UnOpNode::~UnOpNode() {
    debugger->printCall("UnOpNode::~UnOpNode");

    delete (this->expression);

    debugger->printEnd();
}

bool UnOpNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("UnOpNode::doesSubTreeContains");

    debugger->printEnd();
    return this->expression->doesSubTreeContains(id);
}

void UnOpNode::print(std::ostream &os) const {
    debugger->printCall("UnOpNode::print");

    this->printUnOp(os, "unkown");

    debugger->printEnd();
}

void UnOpNode::printUnOp(std::ostream &os, std::string str) const {
    os << "UnOp("; this->indent += 5;
    os << str << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->expression << ")"; this->indent -= 5;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void UnOpNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("UnOpNode::check");

    ast_processor->symbolTable->enterNewScope();
    this->expression->check(ast_processor);
    ast_processor->symbolTable->exitToParent();

    setReturnType(this->expression->getReturnType());

    debugger->printEnd();
}