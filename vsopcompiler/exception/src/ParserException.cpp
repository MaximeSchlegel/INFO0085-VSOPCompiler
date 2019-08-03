#include "../Exception.h"


ParserException::ParserException(std::string filename, int line, int column, std::string errorText)
        : CompilerException(filename, line, column, errorText) {}

ParserException::~ParserException() {}

void ParserException::print(std::ostream &os) const {
    printError(os, "syntax error");
}