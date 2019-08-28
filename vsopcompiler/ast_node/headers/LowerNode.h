#ifndef INFO0085_VSOPCOMPILER_2_LOWERNODE_H
#define INFO0085_VSOPCOMPILER_2_LOWERNODE_H

#include "BinOpNode.h"

class LowerNode
    : public BinOpNode
{
public:
    LowerNode(Node *left, Node *right);
    virtual ~LowerNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
