#ifndef INFO0085_VSOPCOMPILER_2_NEWNODE_H
#define INFO0085_VSOPCOMPILER_2_NEWNODE_H

#include "Node.h"

class NewNode
    : public Node
{
private:
    std::string *staticType;

public:
    NewNode(std::string *type);
    virtual ~NewNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
