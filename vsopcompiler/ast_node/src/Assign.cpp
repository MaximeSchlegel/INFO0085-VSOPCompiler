#include "../headers/AssignNode.h"


AssignNode::AssignNode(std::string *object, Node *expr)
        : Node() {
    debugger->printCall("AssignNode::AssignNode");

    this->objectName = object;
    this->expression = expr;

    debugger->printEnd();
}

AssignNode::~AssignNode() {
    debugger->printCall("AssignNode::~AssignNode");

    delete (this->objectName);
    delete (this->expression);

    debugger->printEnd();
}

bool AssignNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("AssignNode::doesSubTreeContains");

    if (*this->objectName == *id) {
        debugger->printEnd();
        return true;
    }
    if (this->expression->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void AssignNode::print(std::ostream &os) const {
    debugger->printCall("AssignNode::print");

    os << "Assign("; this->indent += 7;
    os << *this->objectName << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->expression;

    os<< ")"; this->indent -= 7;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void AssignNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("AssignNode::check");

    /// Check overshadowed of self
    if (*this->objectName == "self") {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Self can not be overshadowed");
    }

    VariableEntry *object = ast_processor->symbolTable->lookupVariable(this->objectName);

    /// Check if the object has been declared
    if (!object) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Use of unbound variable -- " + *this->objectName);
    }

    /// Check the expression
    ast_processor->symbolTable->enterNewScope();
    this->expression->check(ast_processor);
    ast_processor->symbolTable->exitToParent();

    /// Check if the types match
    if (!ast_processor->isChildOf(this->expression->getReturnType(), object->getType())) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Types do not match -- " + *object->getType() + " - " + *this->expression->getReturnType());
    }

    this->setReturnType(this->expression->getReturnType());

    debugger->printEnd();
}

llvm::Value *AssignNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("WhileNode::codeGen");

    llvm::Value *expressionValue = this->expression->codeGen(ast_processor);
    if(!expressionValue) {
        return nullptr;
    }

    ast_processor->llvmNamedValues[*this->objectName] = expressionValue;

    debugger->printEnd();
    return expressionValue;
}
