#ifndef INFO0085_VSOPCOMPILER_2_MINUSNODE_H
#define INFO0085_VSOPCOMPILER_2_MINUSNODE_H

#include "BinOpNode.h"

class MinusNode
    : public BinOpNode
{
public:
    MinusNode(Node *left, Node *right);
    virtual ~MinusNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
