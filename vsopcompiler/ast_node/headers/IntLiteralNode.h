#ifndef INFO0085_VSOPCOMPILER_2_INTLITERALNODE_H
#define INFO0085_VSOPCOMPILER_2_INTLITERALNODE_H

#include "Node.h"

class IntLiteralNode
    : public Node
{
private:
    int value;

public:
    IntLiteralNode(int value);
    virtual ~IntLiteralNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
