#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


LetNode::LetNode(std::string *name, std::string *type, Node *expr)
        :Node () {
    debugger->printCall("LetNode::LetNode");

    this->objectName = name;
    this->staticType = type;
    this->expression = expr;
    this->assign = nullptr;

    debugger->printEnd();
}


LetNode::LetNode(std::string *name, std::string *type, Node *assign, Node *expr) {
    debugger->printCall("LetNode::LetNode");

    this->objectName = name;
    this->staticType = type;
    this->expression = expr;
    this->assign = assign;

    debugger->printEnd();
}

LetNode::~LetNode() {
    debugger->printCall("LetNode::~LetNode");

    delete (this->objectName);
    delete (this->staticType);
    delete (this->expression);
    delete (this->assign);

    debugger->printEnd();
}

bool LetNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("LetNode::doesSubTreeContains");

    if (*this->objectName == *id) {
        debugger->printEnd();
        return true;
    }
    if (*this->staticType == *id) {
        debugger->printEnd();
        return true;
    }
    if (this->expression->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }
    if (this->assign && this->assign->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void LetNode::print(std::ostream &os) const {
    debugger->printCall("LetNode::print");

    os << "Let("; this->indent += 4;
    os << *this->objectName << ", " << *this->staticType << ","<< std::endl;

    if (this->assign) {
        for (int i = 0; i < this->indent; ++i) { os << " ";}
        os << *this->assign << "," << std::endl;
    }

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->expression;
    os << ")"; this->indent -= 4;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void LetNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("LetNode::check");

    /// Check the declared type
    if (!ast_processor->exist(this->staticType)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Declared type is not define -- " + *this->staticType);
    }
    debugger->printStep("Declared type check pass");

    /// Check overshadowed of self
    if (*this->objectName == "self") {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Self can not be overshadowed");
    }
    debugger->printStep("Overshadowed self check pass");

    /// Check the assign statement
    if (this->assign) {
        ast_processor->symbolTable->enterNewScope();
        this->assign->check(ast_processor);
        ast_processor->symbolTable->exitToParent();
    }
    debugger->printStep("Assign statement check pass");

    /// Check the expression
    ast_processor->symbolTable->enterNewScope();
    ast_processor->symbolTable->addEntry(this->objectName, this->staticType);
    this->expression->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    debugger->printStep("Expression check pass");

    this->setReturnType(this->expression->getReturnType());

    debugger->printEnd();
}
