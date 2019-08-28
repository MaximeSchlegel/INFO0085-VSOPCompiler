#ifndef INFO0085_VSOPCOMPILER_2_NODE_H
#define INFO0085_VSOPCOMPILER_2_NODE_H

#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"

#include "llvm/ADT/APInt.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Value.h"

class Node
{
private:
    std::string *filename;
    int line;
    int column;
    std::string *returnType;

protected:
    static int indent;

public:
    Node();
    virtual ~Node();

    void setPosition(std::string filename, int line = -1, int column = -1);
    std::string *getFilename() const;
    int getLine() const;
    int getColumn() const;

    void setReturnType(std::string *type);
    std::string *getReturnType() const;

    virtual bool doesSubTreeContains(std::string *id);

    friend std::ostream &operator<<(std::ostream &os, const Node &node);
    virtual void print(std::ostream &os) const;

    virtual void preprocess(ASTProcessor *ast_processor);
    virtual void check(ASTProcessor *ast_processor);
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor) = 0;
};

#endif
