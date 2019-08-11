#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


BlockNode::BlockNode()
        : Node() {
    debugger->printCall("BlockNode::BlockNode");

    this->expressions = new std::vector<Node *>();

    debugger->printEnd();
}

BlockNode::~BlockNode() {
    debugger->printCall("BlockNode::~BlockNode");

    delete (this->expressions);

    debugger->printEnd();
}

void BlockNode::addExpr(Node *expr) {
    this->expressions->push_back(expr);
}

bool BlockNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("BlockNode::doesSubTreeContains");

    for (std::vector<Node *>::iterator it = this->expressions->begin(); it != this->expressions->end() ; it++) {
        if ((*it)->doesSubTreeContains(id)) {
            debugger->printEnd();
            return true;
        }
    }

    debugger->printEnd();
    return false;
}

void BlockNode::print(std::ostream &os) const {
    debugger->printCall("BlockNode::print");

    if (this->expressions->size() == 1) {
        os << *this->expressions->front();
        return;
    }
    if (this->expressions->size() > 1) {
        os << "["; this->indent++;

        os << *this->expressions->front();

        std::vector<Node *>::iterator it = this->expressions->begin(); it++;
        for (; it != this->expressions->end(); it++) {
            os << "," << std::endl;
            for (int i = 0; i < this->indent; ++i) { os << " "; }
            os << **it;
        }

        os << "]"; this->indent--;
    }

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void BlockNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("BlockNode::check");

    ast_processor->symbolTable->enterNewScope();

    /// Check the subtree
    for (std::vector<Node *>::iterator it = this->expressions->begin(); it != this->expressions->end() ; it++) {
        (*it)->check(ast_processor);
    }

    ast_processor->symbolTable->exitToParent();
    this->setReturnType(this->expressions->back()->getReturnType());

    debugger->printEnd();
}