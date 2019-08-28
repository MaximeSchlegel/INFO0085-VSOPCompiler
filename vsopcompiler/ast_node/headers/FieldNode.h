#ifndef INFO0085_VSOPCOMPILER_2_FIELDNODE_H
#define INFO0085_VSOPCOMPILER_2_FIELDNODE_H

#include "Node.h"

class FieldNode
    : public Node
{
private:
    std::string *name;
    std::string *staticType;
    Node *expr;

public:
    FieldNode(std::string *name, std::string *type);
    FieldNode(std::string *name, std::string *type, Node *expr);
    virtual ~FieldNode();

    std::string *getName() const;

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    void preprocess(ASTProcessor *ast_processor) override;
    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
