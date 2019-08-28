#ifndef INFO0085_VSOPCOMPILER_2_BOOLLITERALNODE_H
#define INFO0085_VSOPCOMPILER_2_BOOLLITERALNODE_H

#include "Node.h"

class BoolLiteralNode
    : public Node
{
private:
    bool value;

public:
    BoolLiteralNode(bool value);
    virtual ~BoolLiteralNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
