#include "../SymbolTable.h"

SymbolTableEntry::SymbolTableEntry(std::string *id, std::string *type) {
    this->id = id;
    this->type = type;
}

SymbolTableEntry::~SymbolTableEntry() {
    delete (this->id);
    delete (this->type);
}

std::string *SymbolTableEntry::getId() {
    return this->id;
}

std::string *SymbolTableEntry::getType() {
    return this->type;
}
