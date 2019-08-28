#ifndef INFO0085_VSOPCOMPILER_2_LOWEREQUALNODE_H
#define INFO0085_VSOPCOMPILER_2_LOWEREQUALNODE_H

#include "BinOpNode.h"

class LowerEqualNode
    : public BinOpNode
{
public:
    LowerEqualNode(Node *left, Node *right);
    virtual ~LowerEqualNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
