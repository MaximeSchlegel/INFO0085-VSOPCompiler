#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


FormalNode::FormalNode(std::string *name, std::string *type)
        : Node() {
    debugger->printCall("FormalNode::FormalNode");

    this->name = name;
    this->staticType = type;

    debugger->printEnd();
}

FormalNode::~FormalNode() {
    debugger->printCall("FormalNode::~FormalNode");

    delete (this->name);
    delete (this->staticType);

    debugger->printEnd();
}

std::string * FormalNode::getName() const {
    return name;
}

std::string * FormalNode::getStaticType() const {
    return this->staticType;
}

bool FormalNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("FormalNode::doesSubTreeContains");

    if (*this->name == *id) {
        debugger->printEnd();
        return true;
    }
    if (*this->staticType == *id) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void FormalNode::print(std::ostream &os) const {
    debugger->printCall("FormalNode::print");

    os << *this->name << " : " << *this->staticType;

    debugger->printEnd();
}

void FormalNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("FormalNode::check");

    /// Check if the formal type is define
    if (!ast_processor->exist(this->staticType)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Formal type is not define -- " + *this->staticType);
    }
    debugger->printStep("Declared type check pass");

    /// Add to the current scope (created in the method check) to check the block
    ast_processor->symbolTable->addEntry(this->name, this->staticType);
    debugger->printStep("Formal added to method scope");

    debugger->printEnd();
}

llvm::Value *FormalNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("FormalNode::codeGen");

    debugger->printEnd();
    return nullptr;
}
