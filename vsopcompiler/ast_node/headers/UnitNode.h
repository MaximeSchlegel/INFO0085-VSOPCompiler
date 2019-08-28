#ifndef INFO0085_VSOPCOMPILER_2_UNITNODE_H
#define INFO0085_VSOPCOMPILER_2_UNITNODE_H

#include "Node.h"

class UnitNode
    : public Node
{
public:
    UnitNode();
    virtual ~UnitNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
