#include "../Exception.h"

LexerException::LexerException(std::string filename, int line, int column, std::string errorText)
        : CompilerException(filename, line, column, errorText) {}

LexerException::~LexerException() {}

void LexerException::print(std::ostream &os) const {
    printError(os, "lexical error");
}