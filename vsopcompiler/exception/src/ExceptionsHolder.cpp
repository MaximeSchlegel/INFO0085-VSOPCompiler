#include "../Exception.h"

ExceptionsHolder::ExceptionsHolder()
        : public std::exception {
    this->errors = new std::vector<ProjectException *>();
}

ExceptionsHolder::ExceptionsHolder(ProjectException error)
        : public std::exception {
    this->errors = new std::vector<ProjectException *>();
    this->errors->push_back(*error);
}

ExceptionsHolder::ExceptionsHolder(ProjectException *error) {
    this->errors = new std::vector<ProjectException *>();
    this->errors->push_back(error);
}

ExceptionsHolder::~ExceptionsHolder() {
    delete (this->errors);
}

const char* ExceptionsHolder::what() const {
    return "Multiple errors occured";
}

std::vector<std::exception> * ExceptionsHolder::getErrors() {
    return this->errors;
}

bool ExceptionsHolder::isEmpty() {
    return this->errors->size() == 0;
}

void ExceptionsHolder::add(std::exception error) {
    this->errors->push_back(error);
}

void ExceptionsHolder::add(ExceptionsHolder error) {
    std::vector<std::exception> *to_add = error.getErrors();
    if (to_add->size() > this->errors->size()) {
        for (std::vector<exception>::iterator it = this->errors->begin(); it != this->errors->end(); it++) {
            to_add->push_back(*it);
        }
        tmp = this->errors;
        this->errors = to_add;
        delete (tmp);
    } else {
        for (std::vector<exception>::iterator it = to_add->begin(); it != to_add->end(); it++) {
            this->errors.push_back(*it);
        }
    }
}

std::ostream & ExceptionsHolder::operator<<(std::ostream &os, const ProjectException &exception) {
    for (std::vector<exception>::iterator it = this->errors->begin(); it != this->errors->end(); it++) {
        os << *it << std::endl;
    }
}