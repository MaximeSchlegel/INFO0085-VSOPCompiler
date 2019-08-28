#ifndef INFO0085_VSOPCOMPILER_2_EQUALNODE_H
#define INFO0085_VSOPCOMPILER_2_EQUALNODE_H

#include "BinOpNode.h"

class EqualNode
    : public BinOpNode
{
public:
    EqualNode(Node *left, Node *right);
    virtual ~EqualNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
