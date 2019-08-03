#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


NegNode::NegNode(Node *expr)
        : UnOpNode(expr) {
    debugger->printCall("NegNode::NegNode");
    debugger->printEnd();
}

NegNode::~NegNode() {
    debugger->printCall("NegNode::~NegNode");
    debugger->printEnd();
}

void NegNode::print(std::ostream &os) const {
    debugger->printCall("NegNode::print");

    this->printUnOp(os, "-");

    debugger->printEnd();
}

void NegNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("NegNode::check");

    /// Check the Subtree
    this->expression->check(ast_processor);

    /// Check the expression type - expected :  int32
    if (*this->expression->getReturnType() != "int32") {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Type int32 expected -- " + *this->expression->getReturnType());
    }

    this->setReturnType(this->expression->getReturnType());

    debugger->printEnd();
}