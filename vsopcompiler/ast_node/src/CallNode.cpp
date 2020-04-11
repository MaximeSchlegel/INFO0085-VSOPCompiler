#include "../headers/CallNode.h"


CallNode::CallNode(std::string *methodName, Node *caller, std::vector<Node *> *args)
        : Node() {
    debugger->printCall("CallNode::CallNode");

    this->methodName = methodName;
    this->caller = caller;
    this->arguments = args;

    debugger->printEnd();
}

CallNode::~CallNode() {
    debugger->printCall("CallNode::~CallNode");

    delete (this->methodName);
    delete (this->caller);

    for (std::vector<Node *>::iterator it = this->arguments->begin(); it != this->arguments->end(); it++) {
        delete (*it);
    }
    delete (this->arguments);

    debugger->printEnd();
}

bool CallNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("CallNode::doesSubTreeContains : id=" + *id);

    if (*this->methodName == *id) {
        debugger->printEnd();
        return true;
    }
    if (this->caller->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }
    if (arguments) {
        for (std::vector<Node *>::iterator it = this->arguments->begin(); it != this->arguments->end(); it++) {
            if ((*it)->doesSubTreeContains(id)) {
                debugger->printEnd();
                return true;
            }
        }
    }

    debugger->printEnd();
    return false;
}

void CallNode::print(std::ostream &os) const {
    debugger->printCall("CallNode::print");

    os << "Call("; this->indent += 5;
    os << *this->caller << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->methodName << ",";


    if (this->arguments) {
        os << std::endl;

        for (int i = 0; i < this->indent; ++i) { os << " "; }
        os << "["; this->indent++;
        os << *this->arguments->front();

        std::vector<Node *>::iterator it = this->arguments->begin(); it ++;
        for (; it != this->arguments->end(); it++) {
            os << "," << std::endl;

            for (int i = 0; i < this->indent; ++i) { os << " "; }
            os << **it;
        }

        os << "]"; this->indent--;
    } else {
        os << " []";
    }

    os << ")"; this->indent -= 5;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void CallNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("CallNode::check");

    ExceptionsHolder *errors = new ExceptionsHolder();

    /// Check the caller and method
    try {
        this->caller->check(ast_processor); /// can throw an errors -> if the case try stop here
        debugger->printStep("Check : Caller PASS");

        /// Check if the method exist for the caller
        ast_processor->symbolTable->enterSavedScope(this->caller->getReturnType());
        MethodEntry *method = ast_processor->symbolTable->lookupMethod(this->methodName);
        ast_processor->symbolTable->exitToPrevious();
        if (method) {
            debugger->printStep("Check : Method existence PASS");

            /// Check that the args number match the formals number
            if (this->arguments && (this->arguments->size() != method->formalsNumber()) {
                errors->add(ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                                  "Invalid number of argument -- " + std::to_string(this->arguments->size()) + " / " + std::to_string(method->formalsNumber())));
            } else if (!this->arguments && (method->formalsNumber() != 0)) {
                errors->add(ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                            "Invalid number of argument -- " + std::to_string(0) + " / " + std::to_string(method->formalsNumber())));
            } else {
                debugger->printStep("Check : Arguments number PASS");
            }
        } else {
            errors->add(ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                              "Method is not define -- " + *this->caller->getReturnType() + "::" + *this->methodName));
        }
    } catch (const ExceptionsHolder &e) {
        errors->add(e);
    }


    /// Check the subtree
    bool pass = true;
    for (long unsigned int i = 0; i < this->arguments->size(); ++i) {
        ast_processor->symbolTable->enterNewScope();
        try {
            this->arguments->at(i)->check(ast_processor);
        } catch (const ExceptionsHolder &e) {
            errors->add(e);
            pass = false;
        }
        ast_processor->symbolTable->exitToParent();
    }

    if (pass) {
        debugger->printStep("Check : Subtree PASS");
    }

    /// Stop here if error because type compatibility tests do not make sense
    if (!errors->isEmpty()) {
        debugger->printEnd();
        throw errors;
    }

    /// Check that the args are define according to the formals
    pass = true;
    for (long unsigned int i = 0; i < this->arguments->size(); ++i) {
        if (!ast_processor->isChildOf(this->arguments->at(i)->getReturnType(), method->getFormal(i)->getType())) {
            errors->add(ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                    "Types do not match -- " + *this->arguments->at(i)->getReturnType() + " - " + *method->getFormal(i)->getType()));
            pass = false;
        }
    }
    if (pass) {
        debugger->printStep("Check : Matching type of args PASS");
    }
    if (!errors->isEmpty()) {
        throw errors;
    }

    this->setReturnType(method->getType());
    debugger->printEnd();
}

llvm::Value *CallNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("CallNode::codeGen");

    llvm::Function *called = ast_processor->llvmModule->getFunction(*this->methodName);
    if(!called) {
        return nullptr;
    }

    std::vector<llvm::Value *> argsValues;

    for (long unsigned int i = 0; i < this->arguments->size(); ++i) {
        argsValues.push_back(this->arguments->at(i)->codeGen(ast_processor));
        if(!argsValues.back()) {
            return nullptr;
        }
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateCall(called, argsValues, "calltmp");
}
