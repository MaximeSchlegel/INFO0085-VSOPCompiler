#ifndef INFO0085_VSOPCOMPILER_ASTPROCESSOR_H
#define INFO0085_VSOPCOMPILER_ASTPROCESSOR_H


#include <exception>
#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"


class Node;
class ProgramNode;
class ClassNode;
class SymbolTable;
class Debugger;

extern Debugger *debugger;
extern std::string filename;


class ASTProcessor {
private:
    ProgramNode *root;
    std::vector<ClassNode *> *waitingQueue;
    std::map<std::string, Node *> *declaredClasses;


public:
    SymbolTable *symbolTable;

    llvm::LLVMContext llvmContext;
    llvm::IRBuilder<> llvmBuilder();
    std::unique_ptr<llvm::Module> llvmModule;
    std::map<std::string, llvm::Value *> llvmNamedValues;

    ASTProcessor(ProgramNode *root);
    ~ASTProcessor();

    void registerClass(std::string *id, ClassNode* node);
    Node* strToNode(std::string *id) const;
    bool exist(std::string *id) const;

    void addWaiting(ClassNode *node);
    void popWaiting();
    bool isWaiting(std::string *id);

    bool isChildOf(std::string *subclass, std::string *testClass);
    std::string *getFirstCommonAncestor(std::string *c1, std::string *c2);

    void check();
    void codeGen();
};


#endif //INFO0085_VSOPCOMPILER_ASTPROCESSOR_H
