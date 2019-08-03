#include "../Exception.h"

ASTProcessorException::ASTProcessorException(std::string filename, int line, int column, std::string errorText)
        : CompilerException (filename, line, column, errorText) {}

ASTProcessorException::~ASTProcessorException() {}

void ASTProcessorException::print(std::ostream &os) const {
    this->printError(os, "semantic error");
}