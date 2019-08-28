#ifndef INFO0085_VSOPCOMPILER_2_BLOCKNODE_H
#define INFO0085_VSOPCOMPILER_2_BLOCKNODE_H

#include "Node.h"

class BlockNode
    : public Node
{
private:
    std::vector<Node *> *expressions;

public:
    BlockNode();
    virtual ~BlockNode();

    void addExpr(Node *expr);

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
