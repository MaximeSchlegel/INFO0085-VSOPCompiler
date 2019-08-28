#ifndef INFO0085_VSOPCOMPILER_2_ISNULLNODE_H
#define INFO0085_VSOPCOMPILER_2_ISNULLNODE_H

#include "UnOpNode.h"

class IsNullNode
    : public UnOpNode
{
public:
    IsNullNode(Node *expr);
    virtual ~IsNullNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
