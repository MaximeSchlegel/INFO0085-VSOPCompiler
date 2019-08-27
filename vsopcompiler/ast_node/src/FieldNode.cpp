#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


FieldNode::FieldNode(std::string *name, std::string *type)
        : Node() {
    debugger->printCall("FieldNode::FieldNode");

    this->name = name;
    this->staticType = type;
    this->expr = nullptr;

    debugger->printEnd();
}

FieldNode::FieldNode(std::string *name, std::string *type, Node *expr)
        : Node() {
    debugger->printCall("FieldNode::FieldNode");

    this->name = name;
    this->staticType = type;
    this->expr = expr;

    debugger->printEnd();
}

FieldNode::~FieldNode() {
    debugger->printCall("FieldNode::~FieldNode");

    delete (this->name);
    delete (this->staticType);
    delete (this->expr);

    debugger->printEnd();
}

bool FieldNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("FieldNode::doesSubTreeContains");

    if (*this->name == *id) {
        debugger->printEnd();
        return true;
    }
    if (*this->staticType == *id) {
        debugger->printEnd();
        return true;
    }
    if (this->expr) {
        debugger->printEnd();
        return doesSubTreeContains(id);
    }

    debugger->printEnd();
    return false;
}

void FieldNode::print(std::ostream &os) const {
    debugger->printCall("FieldNode::print");

    os << "Field("; this->indent += 6;
    os << *this->name << ", " << *this->staticType;

    if (this->expr) {
        os << "," << std::endl;

        for (int i = 0; i < this->indent; ++i) { os << " "; }
        os << *this->expr;
    }
    os << ")";
    this->indent -= 6;

    debugger->printEnd();
}

void FieldNode::preprocess(ASTProcessor *ast_processor) {
    debugger->printCall("FieldNode::preprocess");

    /// Check if the field is already define
    if (ast_processor->symbolTable->findVariable(this->name)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "The field is already define -- " + *this->name);
    }

    /// Check if the field is a redefinition of inherited field
    if (ast_processor->symbolTable->lookupVariable(this->name)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Redefinition of inherited field -- " + *this->name);
    }

    /// Create the field in the symbol table
    ast_processor->symbolTable->addEntry(this->name, this->staticType);

    debugger->printEnd();
}

void FieldNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("FieldNode::check");

    ///Check that the declared type exist
    if (!ast_processor->exist(this->staticType)){
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Declared type is not define -- " + *this->staticType);
    }
    debugger->printStep("Declared type check pass");

    /// Check the expression
    if (this->expr) {
        ///check the expression
        this->expr->check(ast_processor);
        debugger->printStep("Expression check pass");

        /// Check that no fields or methods are used in the field assignment
        std::vector<VariableEntry *> *variablesInScope = ast_processor->symbolTable->getVariablesInScope();
        for (std::vector<VariableEntry *>::iterator it = variablesInScope->begin(); it != variablesInScope->end(); it++) {
            if (this->expr->doesSubTreeContains((*it)->getId())) {
                throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                        "Cannot use class field in field initializer -- " + *(*it)->getId());
            }
        }
        std::vector<MethodEntry *> *methodsInCsope = ast_processor->symbolTable->getMethodsInScope();
        for (std::vector<MethodEntry *>::iterator it = methodsInCsope->begin(); it != methodsInCsope->end(); it++) {
            if (this->expr->doesSubTreeContains((*it)->getId())) {
                throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                        "Cannot use class methods in field initializer -- " + *(*it)->getId());
            }
        }

        debugger->printStep("Field or method used in assign check pass");

        /// Check that the expression type match the declared one
        if(!ast_processor->isChildOf(this->expr->getReturnType(), this->staticType)) {
            throw ASTProcessorException (*this->getFilename(), this->getLine(), this->getColumn(),
                    "Declared and assigned type do not match -- " + *this->staticType + " - " + *this->expr->getReturnType());
        }
        debugger->printStep("Declared type match check pass");
    }
    debugger->printStep("Expression checked pass");

    debugger->printEnd();
}

llvm::Value *FieldNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("FieldNode::codeGen");

    debugger->printEnd();
    return nullptr;
}
