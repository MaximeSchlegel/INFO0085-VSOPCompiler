#ifndef INFO0085_VSOPCOMPILER_2_UNOPNODE_H
#define INFO0085_VSOPCOMPILER_2_UNOPNODE_H

#include "Node.h"

class UnOpNode
    : public Node
{
protected:
    Node *expression;

public:
    UnOpNode(Node *expr);
    virtual ~UnOpNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;
    void printUnOp(std::ostream &os, std::string str) const;

    virtual void check(ASTProcessor *ast_processor) override;
};

#endif
