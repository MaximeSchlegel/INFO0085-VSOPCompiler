#ifndef INFO0085_VSOPCOMPILER_2_NOTNODE_H
#define INFO0085_VSOPCOMPILER_2_NOTNODE_H

#include "UnOpNode.h"

class NotNode
    : public UnOpNode
{
public:
    NotNode(Node *expr);
    virtual ~NotNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
