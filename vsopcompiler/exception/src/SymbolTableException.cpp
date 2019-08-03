#include "../Exception.h"


SymbolTableException::SymbolTableException(std::string errorTxt)
        : ProjectException (errorTxt) {}

SymbolTableException::~SymbolTableException() {}

void SymbolTableException::print(std::ostream &os) const {
    this->printError(os, "symbol table error");
}