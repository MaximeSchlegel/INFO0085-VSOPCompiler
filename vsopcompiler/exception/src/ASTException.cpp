#include "../Exception.h"


ASTException::ASTException(std::string errorText)
        : ProjectException(errorText) {}

ASTException::~ASTException() {}

void ASTException::print(std::ostream &os) const {
    printError(os, "AST error");
}