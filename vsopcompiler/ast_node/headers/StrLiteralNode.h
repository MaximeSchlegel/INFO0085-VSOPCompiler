#ifndef INFO0085_VSOPCOMPILER_2_STRLITERALNODE_H
#define INFO0085_VSOPCOMPILER_2_STRLITERALNODE_H

#include "Node.h"

class StrLiteralNode
    : public Node
{
private:
    std::string *value;

public:
    StrLiteralNode(std::string *value);
    virtual ~StrLiteralNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
