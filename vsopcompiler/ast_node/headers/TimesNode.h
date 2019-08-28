#ifndef INFO0085_VSOPCOMPILER_2_TIMESNODE_H
#define INFO0085_VSOPCOMPILER_2_TIMESNODE_H

#include "BinOpNode.h"

class TimesNode
    : public BinOpNode
{
public:
    TimesNode(Node *left, Node *right);
    virtual ~TimesNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
