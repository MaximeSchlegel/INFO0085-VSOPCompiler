#include "../headers/ClassNode.h"

ClassNode::ClassNode(std::string *name, std::string *extends,
                     std::pair<std::vector < Node * > *, std::vector<Node *> *> *fieldsAndMethods)
        : Node() {
    debugger->printCall("ClassNode::ClassNode");

    this->name = name;
    this->extends = extends;
    this->fields = fieldsAndMethods->first;
    this->methods = fieldsAndMethods->second;

    debugger->printEnd();
}

ClassNode::~ClassNode() {
    debugger->printCall("ClassNode::~ClassNode");

    delete (this->name);
    delete (this->extends);

    for (std::vector<Node *>::iterator it = this->fields->begin(); it != this->fields->end(); it++) {
        delete (*it);
    }
    delete (this->fields);

    for (std::vector<Node *>::iterator it = this->methods->begin(); it != this->methods->end(); it++) {
        delete (*it);
    }
    delete (this->methods);

    debugger->printEnd();
}

std::string *ClassNode::getName() const {
    return this->name;
}

std::string *ClassNode::getExtends() const {
    return this->extends;
}

bool ClassNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("ClassNode::doesSubTreeContains : id=" + *id);

    if (*this->name == *id) {
        debugger->printEnd();
        return true;
    }
    if (*this->extends == *id) {
        debugger->printEnd();
        return true;
    }
    if (this->fields) {
        for (std::vector<Node *>::iterator it = this->fields->begin(); it != this->fields->end(); it++) {
            if ((*it)->doesSubTreeContains(id)) {
                debugger->printEnd();
                return true;
            }
        }
    }
    if (this->methods) {
        for (std::vector<Node *>::iterator it = this->methods->begin(); it != this->methods->end(); it++) {
            if ((*it)->doesSubTreeContains(id)) {
                debugger->printEnd();
                return true;
            }
        }
    }
    debugger->printEnd();
    return false;
}

void ClassNode::print(std::ostream &os) const {
    debugger->printCall("ClassNode::print");

    os << "Class(";
    this->indent += 6;

    os << *this->name << ", " << *this->extends << ",";

    if (this->fields) {
        os << std::endl;

        for (int i = 0; i < this->indent; ++i) { os << " "; }
        os << "[";
        this->indent++;

        os << *this->fields->front();

        std::vector<Node *>::iterator it = this->fields->begin();
        it++;
        for (; it != this->fields->end(); it++) {
            os << "," << std::endl;
            for (int i = 0; i < this->indent; ++i) { os << " "; }
            os << **it;
        }

        os << "],";
        this->indent--;
    } else {
        os << " [],";
    }

    if (this->methods) {
        os << std::endl;
        for (int i = 0; i < this->indent; ++i) { os << " "; }
        os << "[";
        this->indent++;
        os << *this->methods->front();
        std::vector<Node *>::iterator it = this->methods->begin();
        it++;
        for (; it != this->methods->end(); it++) {
            os << "," << std::endl;
            for (int i = 0; i < this->indent; ++i) { os << " "; }
            os << **it;
        }
        os << "]";
        this->indent--;
    } else {
        os << " []";
    }

    os << ")";
    this->indent -= 6;

    debugger->printEnd();
}

void ClassNode::preprocess(ASTProcessor *ast_processor) {
    debugger->printCall("ClassNode::preprocess");

    /// Check if the class has already been define in the symbol table
    if (!ast_processor->symbolTable->hasScope(this->name)) {

        /// Check if the parent class is define in the program
        if (!ast_processor->exist(this->extends)) {
            throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                    "Parent class is not define -- " + *this->extends);
        }

        /// Add the current class to the classes needed to be define
        ast_processor->addWaiting(this);

        /// Check if the parent is define in the symbol table
        if (!ast_processor->symbolTable->hasScope(this->extends)) {

            /// Check for cyclic definition
            if (ast_processor->isWaiting(this->extends)) {
                throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                        "Cyclic definition -- " + *this->extends);
            }

            /// Try to register the parent node (if not already register)
            ast_processor->strToNode(this->extends)->preprocess(ast_processor);
        }
    }

    /// Create the scope for the current class under those of the parent one
    ast_processor->symbolTable->createNewSavedScope(this->name, this->extends);
    ast_processor->popWaiting();

    /// Try to register the methods and fields of the method
    ast_processor->symbolTable->enterSavedScope(this->name);
    if (this->fields) {
        for (std::vector<Node *>::iterator it = this->fields->begin(); it != this->fields->end(); it++) {
            (*it)->preprocess(ast_processor);
        }
    }
    if (this->methods) {
        for (std::vector<Node *>::iterator it = this->methods->begin(); it != this->methods->end(); it++) {
            (*it)->preprocess(ast_processor);
        }
    }

    debugger->printEnd();
}

void ClassNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("ClassNode::check");

    ast_processor->symbolTable->enterSavedScope(this->name);

    ///Check the fields and the methods
    if (this->fields) {
        for (std::vector<Node *>::iterator it = this->fields->begin(); it != this->fields->end(); it++) {
            (*it)->check(ast_processor);
        }
    }
    if (this->methods) {
        for (std::vector<Node *>::iterator it = this->methods->begin(); it != this->methods->end(); it++) {
            (*it)->check(ast_processor);
        }
    }

    debugger->printEnd();
}

llvm::Value *ClassNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("ClassNode::codeGen");

    debugger->printEnd();
    return nullptr;
}
