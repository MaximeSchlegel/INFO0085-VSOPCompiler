#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


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
    debugger->printCall("CallNode::doesSubTreeContains");

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

    /// Check the caller
    this->caller->check(ast_processor);
    debugger->printStep("Caller check pass");

    /// Check that the method exist
    ast_processor->symbolTable->enterSavedScope(this->caller->getReturnType());
    MethodEntry *method = ast_processor->symbolTable->lookupMethod(this->methodName);
    ast_processor->symbolTable->exitToPrevious();
    if(!method) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Method is not define -- " + *this->caller->getReturnType() + "::" + *this->methodName);
    }
    debugger->printStep("Method exist check pass");

    /// Check that the args are define according to the formals
    if (this->arguments) {
        debugger->printStep("Call has arguments");

        if (this->arguments->size() != method->formalsNumber()) {
            throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                    "Invalid number of argument -- " + std::to_string(this->arguments->size()) + " / " + std::to_string(method->formalsNumber()));
        }
        debugger->printStep("Number of arguments check pass");

        for (long unsigned int i = 0; i < this->arguments->size(); ++i) {
            /// Check the args
            ast_processor->symbolTable->enterNewScope();
            this->arguments->at(i)->check(ast_processor);
            ast_processor->symbolTable->exitToParent();

            /// Check that the type match
            if (!ast_processor->isChildOf(this->arguments->at(i)->getReturnType(), method->getFormal(i)->getType())) {
                throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                        "Types do not match -- " + *this->arguments->at(i)->getReturnType() + " - " + *method->getFormal(i)->getType());
            }
        }
        debugger->printStep("Arguments matching check pass");

    } else if (method->formalsNumber() != 0) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "Invalid number of argument -- " + std::to_string(0) + " / " + std::to_string(method->formalsNumber()));
    }

    this->setReturnType(method->getType());

    debugger->printEnd();
}

llvm::Value *CallNode::codeGen(ASTProcessor *ast_processor)
{
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
    llvm::IRBuilder<> builder = ast_processor->llvmBuilder;
    return builder.CreateCall(called, argsValues, "calltmp");
}
