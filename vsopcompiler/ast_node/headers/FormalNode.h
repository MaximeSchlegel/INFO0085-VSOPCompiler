#ifndef INFO0085_VSOPCOMPILER_2_FORMALNODE_H
#define INFO0085_VSOPCOMPILER_2_FORMALNODE_H

#include "Node.h"

class FormalNode
    : public Node
{
private:
    std::string *name;
    std::string *staticType;

public:
    FormalNode(std::string *name, std::string *type);
    virtual ~FormalNode();

    std::string *getName() const;
    std::string *getStaticType() const;

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
