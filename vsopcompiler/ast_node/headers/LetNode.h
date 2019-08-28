#ifndef INFO0085_VSOPCOMPILER_2_LETNODE_H
#define INFO0085_VSOPCOMPILER_2_LETNODE_H

#include "Node.h"

class LetNode
    : public Node
{
private:
    std::string *objectName;
    std::string *staticType;
    Node *assign;
    Node *expression;

public:
    LetNode(std::string *name, std::string *type, Node *expr);
    LetNode(std::string *name, std::string *type, Node *assign, Node *expr);
    virtual ~LetNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
