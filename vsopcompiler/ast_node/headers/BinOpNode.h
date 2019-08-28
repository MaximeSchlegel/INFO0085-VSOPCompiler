#ifndef INFO0085_VSOPCOMPILER_2_BINOPNODE_H
#define INFO0085_VSOPCOMPILER_2_BINOPNODE_H

#include "Node.h"

class BinOpNode
    : public Node
{
protected:
    Node *left;
    Node *right;

public:
    BinOpNode(Node *left, Node *right);
    virtual ~BinOpNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;
    void printBinOp(std::ostream &os, std::string str) const;

    virtual void check(ASTProcessor *ast_processor) override;
    void checkBinOp(ASTProcessor *ast_processor, std::string returnType);
    void checkBinOp(ASTProcessor *ast_processor, std::string returnType, std::string testType);
};

#endif
