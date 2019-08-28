#ifndef INFO0085_VSOPCOMPILER_2_ASSIGNNODE_H
#define INFO0085_VSOPCOMPILER_2_ASSIGNNODE_H

#include "Node.h"

class AssignNode
    : public Node
{
private:
    std::string *objectName;
    Node *expression;

public:
    AssignNode(std::string *object, Node *expr);
    virtual ~AssignNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
