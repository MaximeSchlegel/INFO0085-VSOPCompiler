#include "../Exception.h"


CompilerException::CompilerException(std::string filename, int line, int column, std::string errorText)
        : ProjectException(errorText) {
    this->filename = filename;
    this->linePos = line;
    this->colPos = column;
}

CompilerException::~CompilerException() {}

const char* CompilerException::getFilename() const {
    return this->filename.c_str();
}

int CompilerException::getLineNumber() const {
    return this->linePos;
}

int CompilerException::getColumnNumber() const {
    return this->colPos;
}

void CompilerException::print(std::ostream &os) const {
    this->printError(os, "compile error");
}

void CompilerException::printError(std::ostream &os, std::string errorType) const {
    os << this->filename << ":" << this->linePos << ":" << this->colPos << ": " << errorType << " : " << this->what() << std::endl;
}