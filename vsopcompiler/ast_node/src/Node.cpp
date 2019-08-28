#include "../headers/Node.h"

int Node::indent = 0;

Node::Node() {
    this->returnType = nullptr;
    this->filename = new std::string();
    this->line = -1;
    this->column = -1;
}

Node::~Node() {
    delete (this->returnType);
    delete (this->filename);
}

void Node::setPosition(std::string filename, int line, int column) {
    this->filename = new std::string(filename);
    this->line = line;
    this->column = column;
}

std::string *Node::getFilename() const {
    return this->filename;
}

int Node::getLine() const {
    return this->line;
}

int Node::getColumn() const {
    return this->column;
}

void Node::setReturnType(std::string *type) {
    this->returnType = type;
}

std::string * Node::getReturnType() const {
    return this->returnType;
}

bool Node::doesSubTreeContains(std::string *id) {
    throw ASTException("Can not check generic node subtree for id -- " + *id);
}

std::ostream &operator<<(std::ostream &os, const Node &node) {
    node.print(os);
    return os;
}

void Node::print(std::ostream &os) const {
    os << "Generic node";
}

void Node::preprocess(ASTProcessor *ast_processor) {
    throw ASTProcessorException(*this->filename, this->line, this->column,
            "Can not preprocess generic node");
}

void Node::check(ASTProcessor *ast_processor) {
    throw ASTProcessorException(*this->filename, this->line, this->column,
            "Can not check generic node");
}
