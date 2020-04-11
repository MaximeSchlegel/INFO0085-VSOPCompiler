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
    debugger->printCall("AssignNode::doesSubTreeContains : id=" + *id);

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

    ExceptionsHolder *errors = new ExceptionsHolder();

    /// Check if self is overshadowed
    if (*this->objectName == "self") {
        errors->add(ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                         "Self can not be overshadowed"));
    } else {
        debugger->printStep("Check : Self overshadowed PASS")
    }

    /// Check if the object has been declared
    VariableEntry *object = ast_processor->symbolTable->lookupVariable(this->objectName);
    if (!object) {
        errors->add(ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                          "Use of unbound variable -- " + *this->objectName));
    } else {
        debugger->printStep("Check : Object declared PASS")
    }

    /// Check the subtree
    ast_processor->symbolTable->enterNewScope();
    try {
        this->expression->check(ast_processor);
        debugger->printStep("Check : Subtree PASS");
    } catch (const ExceptionsHolder &e) {
        errors->add(e);
    }
    ast_processor->symbolTable->exitToParent();

    /// Stop here if error because type compatibility tests do not make sense
    if (!errors->isEmpty()) {
        debugger->printEnd();
        throw errors;
    }

    /// Check if the types match
    if (!ast_processor->isChildOf(this->expression->getReturnType(), object->getType())) {
        throw ExceptionsHolder(
                ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                      "Types do not match -- " + *object->getType() + " - " + *this->expression->getReturnType()));
    } else {
        debugger->printStep("Check : Matching type PASS");
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
