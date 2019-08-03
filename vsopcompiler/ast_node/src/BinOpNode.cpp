#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


BinOpNode::BinOpNode(Node *left, Node *right)
        : Node() {
    debugger->printCall("BinOpNode::BinOpNode");

    this->left = left;
    this->right = right;

    debugger->printEnd();
}

BinOpNode::~BinOpNode() {
    debugger->printCall("");

    delete (this->left);
    delete (this->right);

    debugger->printEnd();
}

bool BinOpNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("BinOpNode::doesSubTreeContains");

    if (left->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }
    if (right->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void BinOpNode::print(std::ostream &os) const {
    debugger->printCall("BinOpNode::print");

    this->printBinOp(os, "unkown");

    debugger->printEnd();
}

void BinOpNode::printBinOp(std::ostream &os, std::string str) const {
    os << "BinOp("; this->indent += 6;
    os << str << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->left << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->right;

    os<< ")";this->indent -= 6;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void BinOpNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("");

    this->checkBinOp(ast_processor, "unit");

    debugger->printEnd();
}

void BinOpNode::checkBinOp(ASTProcessor *ast_processor, std::string returnType) {

    /// Check the Subtree
    ast_processor->symbolTable->enterNewScope();
    this->left->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    ast_processor->symbolTable->enterNewScope();
    this->right->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    debugger->printStep("Subtree check pass");

    if (*this->left->getReturnType() != *this->right->getReturnType()) {
        throw ASTProcessorException(*this->left->getFilename(), this->left->getLine(), this->left->getColumn(),
                "Same type expeced -- " + *this->left->getReturnType() + " - " + *this->right->getReturnType());
    }
    debugger->printStep("Expr type check pass");

    this->setReturnType(new std::string(returnType));

    debugger->printEnd();

}

void BinOpNode::checkBinOp(ASTProcessor *ast_processor, std::string returnType, std::string testType) {

    /// Check the Subtree
    ast_processor->symbolTable->enterNewScope();
    this->left->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    ast_processor->symbolTable->enterNewScope();
    this->right->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    debugger->printStep("Subtree check pass");

    if (*this->left->getReturnType() != testType) {
        throw ASTProcessorException(*this->left->getFilename(), this->left->getLine(), this->left->getColumn(),
                "Expected " + testType + " -- " + *this->left->getReturnType());
    }
    debugger->printStep("Left expr check pass");

    if (*this->right->getReturnType() != testType) {
        throw ASTProcessorException(*this->right->getFilename(), this->right->getLine(), this->right->getColumn(),
                "Expected " + testType + " -- " + *this->right->getReturnType());
    }
    debugger->printStep("Right expr check pass");

    this->setReturnType(new std::string(returnType));
}