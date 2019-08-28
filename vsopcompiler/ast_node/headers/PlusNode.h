#ifndef INFO0085_VSOPCOMPILER_2_PLUSNODE_H
#define INFO0085_VSOPCOMPILER_2_PLUSNODE_H

#include "BinOpNode.h"

class PlusNode
    : public BinOpNode
{
public:
    PlusNode(Node *left, Node *right);
    virtual ~PlusNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
