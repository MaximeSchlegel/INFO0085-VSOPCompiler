#include "../SymbolTable.h"

#include "../../debugger/Debugger.h"

SymbolTableScope::SymbolTableScope(SymbolTableScope *parent) {
    this->parent = parent;
    this->variables = new std::map<std::string, VariableEntry *>();
    this->methods = new std::map<std::string, MethodEntry *>();
}

SymbolTableScope::~SymbolTableScope() {
    for (std::map<std::string, VariableEntry *>::iterator it = this->variables->begin();
         it != this->variables->end(); it++) {
        delete (it->second);
    }
    delete (this->variables);

    for (std::map<std::string, MethodEntry *>::iterator it = this->methods->begin(); it != this->methods->end(); it++) {
        delete (it->second);
    }
    delete (this->methods);
}

void SymbolTableScope::emplace(std::string *id, std::string *type) {
    VariableEntry *var = new VariableEntry(id, type);
    this->variables->emplace(*id, var);
}

VariableEntry *SymbolTableScope::findVariable(std::string *id) const {
    std::map<std::string, VariableEntry *>::iterator target = this->variables->find(*id);
    return (target == this->variables->end()) ? nullptr : target->second;
}

VariableEntry *SymbolTableScope::lookupVariable(std::string *id) const {
    std::map<std::string, VariableEntry *>::iterator target = this->variables->find(*id);
    if (target == this->variables->end()) {
        return (this->parent) ? this->parent->lookupVariable(id) : nullptr;
    }
    return target->second;
}

std::vector<VariableEntry *> *SymbolTableScope::getVariables() const {
    debugger->printCall("SymbolTableScope::getVariables");

    std::vector<VariableEntry *> *res = new std::vector<VariableEntry *>();
    for (std::map<std::string, VariableEntry *>::iterator it = this->variables->begin(); it != this->variables->end() ; it++) {
        res->push_back(it->second);
    }

    debugger->printStep(std::to_string(res->size()));
    debugger->printEnd();
    return res;

}

void SymbolTableScope::emplace(std::string *id, std::string *type, std::vector<VariableEntry *> *formals) {
    MethodEntry *met = new MethodEntry(id, type, formals);
    this->methods->emplace(*id, met);
}

MethodEntry *SymbolTableScope::findMethod(std::string *id) const {
    std::map<std::string, MethodEntry *>::iterator target = this->methods->find(*id);
    return (target == this->methods->end()) ? nullptr : target->second;
}

MethodEntry *SymbolTableScope::lookupMethod(std::string *id) const {
    std::map<std::string, MethodEntry *>::iterator target = this->methods->find(*id);
    if (target == this->methods->end()) {
        return (this->parent) ? this->parent->lookupMethod(id) : nullptr;
    }
    return target->second;
}

std::vector<MethodEntry *> * SymbolTableScope::getMethods() const {
    std::vector<MethodEntry *> *res = new std::vector<MethodEntry *>();
    for (std::map<std::string, MethodEntry *>::iterator it = this->methods->begin(); it != this->methods->end() ; it++) {
        debugger->printStep(it->first);
        if (it->second) {
            res->push_back(it->second);
        } else {
        }
    }
    return res;
}

SymbolTableScope* SymbolTableScope::getParent() const {
    return this->parent;
}