#ifndef INFO0085_VSOPCOMPILER_2_NEGNODE_H
#define INFO0085_VSOPCOMPILER_2_NEGNODE_H

#include "UnOpNode.h"

class NegNode
    : public UnOpNode
{
public:
    NegNode(Node *expr);
    virtual ~NegNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
