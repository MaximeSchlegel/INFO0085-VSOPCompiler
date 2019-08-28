#ifndef INFO0085_VSOPCOMPILER_2_METHODNODE_H
#define INFO0085_VSOPCOMPILER_2_METHODNODE_H

#include "Node.h"

class MethodNode
    : public Node
{
private:
    std::string *name;
    std::string *staticType;
    std::vector<Node *> *formals;
    Node *block;

public:
    MethodNode(std::string *name, std::string *type, std::vector<Node *> *formals, Node *block);
    virtual ~MethodNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    void preprocess(ASTProcessor *ast_processor) override;
    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
