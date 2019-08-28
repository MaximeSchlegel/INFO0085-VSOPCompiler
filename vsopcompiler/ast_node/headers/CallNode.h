#ifndef INFO0085_VSOPCOMPILER_2_CALLNODE_H
#define INFO0085_VSOPCOMPILER_2_CALLNODE_H

#include "Node.h"

class CallNode
    : public Node
{
private:
    std::string *methodName;
    Node *caller;
    std::vector<Node *> *arguments;

public:
    CallNode(std::string *methodName, Node *caller, std::vector<Node *> *args);
    virtual ~CallNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
