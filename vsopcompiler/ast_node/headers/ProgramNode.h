#ifndef INFO0085_VSOPCOMPILER_2_PROGRAMNODE_H
#define INFO0085_VSOPCOMPILER_2_PROGRAMNODE_H

#include "Node.h"

class ProgramNode
    : public Node
{
private:
    std::vector<Node *> *classes;

public:
    ProgramNode();
    virtual ~ProgramNode();

    void addClass(Node *toAdd);

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    void preprocess(ASTProcessor *ast_processor) override;
    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
