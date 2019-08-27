#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


NewNode::NewNode(std::string *type)
        : Node() {
    debugger->printCall("NewNode::NewNode");

    this->staticType = type;

    debugger->printEnd();
}

NewNode::~NewNode() {
    debugger->printCall("NewNode::~NewNode");

    delete (this->staticType);

    debugger->printEnd();
}

bool NewNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("NewNode::doesSubTreeContains");

    debugger->printEnd();
    return *this->staticType == *id;

}

void NewNode::print(std::ostream &os) const {
    debugger->printCall("NewNode::print");

    os << "New(" << *this->staticType << ")";
    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void NewNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("ewNode::check");

    /// Check if the type exist
    if (!ast_processor->symbolTable->hasScope(this->staticType)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Declared type is not define -- " + *this->staticType);
    }

    this->setReturnType(this->staticType);

    debugger->printEnd();
}

llvm::Value *NewNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("NewNode::codeGen");

    debugger->printEnd();
    return nullptr;
}
