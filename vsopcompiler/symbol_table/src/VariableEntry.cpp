#include "../SymbolTable.h"

VariableEntry::VariableEntry(std::string *id, std::string *type)
        : SymbolTableEntry(id, type){}

VariableEntry::~VariableEntry() {}