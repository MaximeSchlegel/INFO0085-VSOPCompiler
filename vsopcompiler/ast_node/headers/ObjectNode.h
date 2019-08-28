#ifndef INFO0085_VSOPCOMPILER_2_OBJECTNODE_H
#define INFO0085_VSOPCOMPILER_2_OBJECTNODE_H

#include "Node.h"

class ObjectNode
    : public Node
{
private:
    std::string *name;
    std::string *type;

public:
    ObjectNode(std::string *name);
    ObjectNode(std::string *name, std::string *type);
    virtual ~ObjectNode();

    void setType(std::string *type);

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
