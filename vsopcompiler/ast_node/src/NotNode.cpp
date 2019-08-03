#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


NotNode::NotNode(Node *expr)
        : UnOpNode(expr) {
    debugger->printCall("NotNode::NotNode");
    debugger->printEnd();
}

NotNode::~NotNode() {
    debugger->printCall("NotNode::~NotNode");
    debugger->printEnd();
}

void NotNode::print(std::ostream &os) const {
    debugger->printCall("NotNode::print");

    this->printUnOp(os, "not");

    debugger->printEnd();
}

void NotNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("NotNode::check");

    /// Check the Subtree
    this->expression->check(ast_processor);

    /// Check the type of expression
    if (*this->expression->getReturnType() != "bool") {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Bool Type expected -- " + *this->expression->getReturnType());
    }

    this->setReturnType(this->expression->getReturnType());

    debugger->printEnd();
}