#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


IfNode::IfNode(Node *condition, Node *iftrue)
        : Node() {
    debugger->printCall("IfNode::IfNode");

    this->condition = condition;
    this->iftrue = iftrue;
    this->iffalse = nullptr;

    debugger->printEnd();
}

IfNode::IfNode(Node *conditon, Node *iftrue, Node *iffalse)
        : Node() {
    debugger->printCall("IfNode::IfNode");

    this->condition = conditon;
    this->iftrue = iftrue;
    this->iffalse = iffalse;

    debugger->printEnd();
}

IfNode::~IfNode() {
    debugger->printCall("IfNode::~IfNode");

    delete (this->condition);
    delete (this->iftrue);
    delete (this->iffalse);

    debugger->printEnd();
}

bool IfNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("IfNode::doesSubTreeContains");

    if (condition->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }
    if (iftrue->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }
    if (iffalse && iffalse->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void IfNode::print(std::ostream &os) const {
    debugger->printCall("IfNode::print");

    os << "If("; this->indent += 3;
    os << *this->condition << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->iftrue;

    if (this->iffalse) {
        os << "," << std::endl;

        for (int i = 0; i < this->indent; ++i) { os << " "; };
        os << *this->iffalse;
    }
    os << ")"; this->indent -= 3;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void IfNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("IfNode::check");

    /// Check the Subtree
    ast_processor->symbolTable->enterNewScope();
    this->condition->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    ast_processor->symbolTable->enterNewScope();
    this->iftrue->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    if (iffalse) {
        ast_processor->symbolTable->enterNewScope();
        this->iffalse->check(ast_processor);
        ast_processor->symbolTable->exitToParent();
    }
    debugger->printStep("Subtree check pass");

    /// Check that the first expr has type bool
    if (*condition->getReturnType() != "bool") {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "If conditon is expected of type bool -- " + *this->condition->getReturnType());
    }

    /// Check that both then/else expr have the same type
    if (iffalse) {
        if (ast_processor->isChildOf(this->iftrue->getReturnType(), new std::string("Object"))
                && ast_processor->isChildOf(this->iffalse->getReturnType(), new std::string("Object"))) {
            this->setReturnType(ast_processor->getFirstCommonAncestor(this->iftrue->getReturnType(), this->iffalse->getReturnType()));
        } else if (*this->iftrue->getReturnType() == *this->iffalse->getReturnType()) {
            this->setReturnType(this->iftrue->getReturnType());
        } else if (*this->iftrue->getReturnType() == "unit" || *this->iffalse->getReturnType() == "unit") {
            this->setReturnType(new std::string("unit"));
        } else {
            throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                    "Returned type of then and else do not match -- " + *this->iftrue->getReturnType() + " - " + *this->iffalse->getReturnType());
        }
    } else {
        this->setReturnType(new std::string("unit"));
    }

    debugger->printEnd();
}