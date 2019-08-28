#ifndef INFO0085_VSOPCOMPILER_2_WHILENODE_H
#define INFO0085_VSOPCOMPILER_2_WHILENODE_H

#include "Node.h"

class WhileNode
    : public Node
{
private:
    Node *condition;
    Node *expression;

public:
    WhileNode(Node *condition, Node *expr);
    virtual ~WhileNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
