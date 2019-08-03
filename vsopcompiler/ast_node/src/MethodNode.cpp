#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


MethodNode::MethodNode(std::string *name, std::string *type, std::vector<Node *> *formals, Node *block)
        : Node() {
    debugger->printCall("MethodNode::MethodNode");

    this->name = name;
    this->staticType = type;
    this->formals = formals;
    this->block = block;

    debugger->printEnd();
}

MethodNode::~MethodNode() {
    debugger->printCall("MethodNode::~MethodNode");

    delete (this->name);
    delete (this->staticType);
    delete (this->formals);
    delete (this->block);

    debugger->printEnd();
}

bool MethodNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("MethodNode::doesSubTreeContains");

    if (*this->name == *id) {
        debugger->printEnd();
        return true;
    }
    if (*this->staticType == *id) {
        debugger->printEnd();
        return true;
    }
    if (formals) {
        for (std::vector<Node *>::iterator it = this->formals->begin(); it != this->formals->end(); it++){
            if ((*it)->doesSubTreeContains(id)) {
                debugger->printEnd();
                return true;
            };
        }
    }
    if (this->block->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void MethodNode::print(std::ostream &os) const {
    debugger->printCall("MethodNode::print");

    os << "Method("; this->indent += 7;
    os << *this->name << ","<< std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << "["; this->indent++;

    if (this->formals) {
        os << *this->formals->front();

        std::vector<Node *>::iterator it = this->formals->begin(); it++;
        for (; it != this->formals->end(); it++) {
            os << "," << std::endl;

            for (int i = 0; i < this->indent; ++i) { os << " "; }
            os << **it;
        }
    }
    os << "]," << std::endl; this->indent--;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->staticType << ","<< std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->block;
    os << ")"; this->indent -= 7;

    debugger->printEnd();
}

void MethodNode::preprocess(ASTProcessor *ast_processor) {
    debugger->printCall("MethodNode::preprocess");

    /// Check if the method is already define in the class
    if (ast_processor->symbolTable->findMethod(this->name)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "The method is already define -- " + *this->name);
    }
    debugger->printStep("Method redefinition check pass");

    std::vector<VariableEntry *> *formalsVector = new std::vector<VariableEntry *>();

    ///Check if the formals are correct
    if (this->formals) {
        std::vector<std::string> *usedName = new std::vector<std::string>();

        for (std::vector<Node *>::iterator it = this->formals->begin(); it != this->formals->end(); it++) {
            FormalNode *formalNode = (FormalNode*) *it;

            /// Check if self is used has formal
            if (*formalNode->getName() == "self") {
                throw ASTProcessorException(*formalNode->getFilename(), formalNode->getLine(), formalNode->getColumn(),
                        "Cannot use self as an argument name");
            }

            /// Check if the formal name is already used
            for (std::vector<std::string>::iterator uN = usedName->begin(); uN != usedName->end(); uN++) {
                if (*uN == *formalNode->getName()) {
                    throw ASTProcessorException(*formalNode->getFilename(), formalNode->getLine(), formalNode->getColumn(),
                                           "Formal's name already used -- " + *formalNode->getName());
                }
            }

            usedName->push_back(*formalNode->getName());
            VariableEntry *fml = new VariableEntry(formalNode->getName(), formalNode->getStaticType());
            formalsVector->push_back(fml);
        }
    }
    debugger->printStep("Formals check pass");

    /// Check if the method overwrite is correct
    if (MethodEntry *overwritedMethod = ast_processor->symbolTable->lookupMethod(this->name)){
        /// Check if the types match
        if (*(overwritedMethod->getType()) != *this->staticType) {
            throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                    "Return type does not match the overritten function -- expcted : " + *overwritedMethod->getType());
        }
        debugger->printStep("Overwrite return type check pass");

        /// Check if the number of formals match
        if (!this->formals && overwritedMethod->formalsNumber() != 0) {
            throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                   "Number of formals do not match the overritten function -- expected : " + overwritedMethod->formalsNumber());
        }
        if (this->formals && overwritedMethod->formalsNumber() != this->formals->size()) {
            throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                    "Number of formals do not match the overritten function -- expected : " + overwritedMethod->formalsNumber());
        }
        debugger->printStep("Overwrite number of formals check pass");


        /// Check that formal's type matches
        for (long unsigned int i = 0; this->formals && i < this->formals->size(); ++i) {
            if (*overwritedMethod->getFormal(i)->getType() != *((FormalNode *) this->formals->at(i))->getStaticType()) {
                throw ASTProcessorException(*this->formals->at(i)->getFilename(), this->formals->at(i)->getLine(), this->formals->at(i)->getColumn(),
                        "Type of the formal do not match the overritten function -- expected : " + *overwritedMethod->getFormal(i)->getType());
            }
        }
        debugger->printStep("Overwrite formals type check pass");

    }
    debugger->printStep("Overwrite check pass");

    /// Create the method to the current scope
    ast_processor->symbolTable->addEntry(this->name, this->staticType, formalsVector);

    debugger->printEnd();
}

void MethodNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("MethodNode::check");

    ast_processor->symbolTable->enterNewScope();

    /// Check that the declared type exist
    if (!ast_processor->exist(this->staticType)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Method returned type is not define -- " + *this->staticType);
    }
    debugger->printStep("Return type check pass");

    /// Check the formals
    if (formals) {
        for (std::vector<Node *>::iterator it = this->formals->begin(); it != this->formals->end(); it++){
            (*it)->check(ast_processor);
        }
    }
    debugger->printStep("Formals check pass");

    /// Check the method body
    this->block->check(ast_processor);
    debugger->printStep("Body check pass");

    /// Check that the returned and declared type match
    if (!ast_processor->isChildOf(this->block->getReturnType(), this->staticType)) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Method retruned type does not match block returned type -- " + *this->staticType + " - " + *this->block->getReturnType());
    }
    debugger->printStep("Matching type check pass");

    ast_processor->symbolTable->exitToParent();

    this->setReturnType(this->staticType);

    debugger->printEnd();
}