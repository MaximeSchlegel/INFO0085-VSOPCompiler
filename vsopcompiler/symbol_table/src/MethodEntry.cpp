#include "../SymbolTable.h"

#include "../../exception/Exception.h"


MethodEntry::MethodEntry(std::string *id, std::string *type, std::vector<VariableEntry *> *formals)
        : SymbolTableEntry (id, type) {
    this->formals = formals;
}

MethodEntry::~MethodEntry() {
    for (std::vector<VariableEntry *>::iterator it = this->formals->begin(); it != this->formals->end(); it++) {
        delete (*it);
    }
    delete (this->formals);
}

long unsigned int MethodEntry::formalsNumber() const {
    return this->formals->size();
}

std::vector<VariableEntry *> * MethodEntry::getFormals() const {
    return this->formals;
}

VariableEntry* MethodEntry::getFormal(int i) const {
    if (i >= this->formals->size()) {
        throw SymbolTableException("Out-of-range formal access");
    }
    return this->formals->at(i);
}