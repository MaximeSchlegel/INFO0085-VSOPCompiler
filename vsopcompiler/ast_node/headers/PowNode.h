#ifndef INFO0085_VSOPCOMPILER_2_PLUSNODE_H
#define INFO0085_VSOPCOMPILER_2_PLUSNODE_H

#include "BinOpNode.h"

class PowNode
    : public BinOpNode
{
public:
    PowNode(Node *left, Node *right);
    virtual ~PowNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
