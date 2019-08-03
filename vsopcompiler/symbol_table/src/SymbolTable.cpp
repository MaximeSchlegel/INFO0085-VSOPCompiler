#include "../SymbolTable.h"

#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"


SymbolTable::SymbolTable() {
    this->rootScope = new SymbolTableScope(nullptr);
    this->currentScope = this->rootScope;
    this->savedScope = new std::map<std::string, SymbolTableScope*>();
}

SymbolTable::~SymbolTable() {
    delete (this->rootScope);

    for (std::map<std::string, SymbolTableScope*>::iterator it = this->savedScope->begin(); it != this->savedScope->end(); it++) {
        delete (it->second);
    }
    delete (this->savedScope);
}

void SymbolTable::enterNewScope() {
    SymbolTableScope *anonymousScope = new SymbolTableScope(this->currentScope);
    this->previousScope = this->currentScope;
    this->currentScope = anonymousScope;
}

void SymbolTable::enterSavedScope(std::string *id) {
    std::map<std::string, SymbolTableScope*>::iterator target = this->savedScope->find(*id);
    if (target == this->savedScope->end()) {
        throw SymbolTableException("Cannot find the scope -- " + *id);
    }
    this->previousScope = this->currentScope;
    this->currentScope = target->second;
}

void SymbolTable::exitToRoot() {
    this->previousScope = this->currentScope;
    this->currentScope = this->rootScope;
}

void SymbolTable::exitToPrevious() {
    SymbolTableScope *tmp = this->previousScope;
    this->previousScope = this->currentScope;
    this->currentScope = tmp;
}

void SymbolTable::exitToParent() {
    this->previousScope = this->currentScope;
    this->currentScope = this->currentScope->getParent();
}

void SymbolTable::createNewSavedScope(std::string *id) {
    SymbolTableScope *newScope = new SymbolTableScope(nullptr);
    newScope->emplace(new std::string("self"), id);
    this->savedScope->emplace(*id, newScope);

}

void SymbolTable::createNewSavedScope(std::string *id, std::string *parent) {
    std::map<std::string, SymbolTableScope*>::iterator target = this->savedScope->find(*parent);
    if (target == this->savedScope->end()) {
        throw SymbolTableException("Cannot find the parent scope -- " + *parent);
    }
    SymbolTableScope *newScope = new SymbolTableScope(target->second);
    newScope->emplace(new std::string("self"), id);
    this->savedScope->emplace(*id, newScope);
}

bool SymbolTable::hasScope(std::string *id) {
    std::map<std::string, SymbolTableScope*>::iterator target = this->savedScope->find(*id);
    return target != this->savedScope->end();
}

void SymbolTable::addEntry(std::string *id, std::string *type) {
    this->currentScope->emplace(id, type);
}

void SymbolTable::addEntry(std::string *id, std::string *type, std::vector<VariableEntry *> *formals) {
    this->currentScope->emplace(id, type, formals);
}

VariableEntry* SymbolTable::findVariable(std::string *id) const {
    return this->currentScope->findVariable(id);
}

VariableEntry* SymbolTable::lookupVariable(std::string *id) const {
    return this->currentScope->lookupVariable(id);
}

std::vector<VariableEntry *> * SymbolTable::getVariablesInScope() const {
    debugger->printCall("SymbolTable::getVariablesInScope");

    SymbolTableScope *scope = this->currentScope;
    std::vector<VariableEntry *> *res = new std::vector<VariableEntry *>();
    while (scope) {
        std::vector<VariableEntry *> *src = scope->getVariables();
        res->insert(res->end(), src->begin(), src->end() );
        scope = scope->getParent();
    }

    debugger->printStep(std::to_string(res->size()));
    debugger->printEnd();
    return res;
}

MethodEntry* SymbolTable::findMethod(std::string *id) const {
    return this->currentScope->findMethod(id);
}

MethodEntry* SymbolTable::lookupMethod(std::string *id) const {
    return this->currentScope->lookupMethod(id);
}

std::vector<MethodEntry *> * SymbolTable::getMethodsInScope() const {
    debugger->printCall("SymbolTable::getMethodsInScope");

    SymbolTableScope *scope = this->currentScope;
    std::vector<MethodEntry *> *res = new std::vector<MethodEntry *>();
    while (scope) {
        std::vector<MethodEntry *> *src = scope->getMethods();
        res->insert(res->end(), src->begin(), src->end() );
        scope = scope->getParent();
    }

    debugger->printStep(std::to_string(res->size()));
    debugger->printEnd();
    return res;
}