#ifndef INFO0085_VSOPCOMPILER_2_IFNODE_H
#define INFO0085_VSOPCOMPILER_2_IFNODE_H

#include "Node.h"

class IfNode
    : public Node
{
private:
    Node *condition;
    Node *iftrue;
    Node *iffalse;

public:
    IfNode(Node *condition, Node *iftrue);
    IfNode(Node *conditon, Node *iftrue, Node *iffalse);
    virtual ~IfNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
