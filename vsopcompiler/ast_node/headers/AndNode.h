#ifndef INFO0085_VSOPCOMPILER_2_ANDNODE_H
#define INFO0085_VSOPCOMPILER_2_ANDNODE_H

#include "BinOpNode.h"

class AndNode
    : public BinOpNode
{
public:
    AndNode(Node *left, Node *right);
    virtual ~AndNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
