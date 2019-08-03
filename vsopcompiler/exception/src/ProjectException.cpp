#include "../Exception.h"


ProjectException::ProjectException(std::string errorText) {
    this->errorText = errorText;
}

ProjectException::~ProjectException() {}

const char *ProjectException::what() const throw() {
    return this->errorText.c_str();
}

std::ostream & operator<<(std::ostream &os, const ProjectException &exception) {
    exception.print(os);
    return os;
}

void ProjectException::print(std::ostream &os) const {
    printError(os, "error");
}

void ProjectException::printError(std::ostream &os, std::string errorType) const {
    os << errorType << " : " << this->errorText << std::endl;
}

