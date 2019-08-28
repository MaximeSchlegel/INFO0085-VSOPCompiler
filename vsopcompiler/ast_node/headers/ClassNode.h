#ifndef INFO0085_VSOPCOMPILER_2_CLASSNODE_H
#define INFO0085_VSOPCOMPILER_2_CLASSNODE_H

#include "Node.h"

class ClassNode
    : public Node
{
private:
    std::string *name;
    std::string *extends;
    std::vector<Node *> *fields;
    std::vector<Node *> *methods;

public:
    ClassNode(std::string *name, std::string *extends,
              std::pair<std::vector<Node *> *, std::vector<Node *> *> *fieldsAndMethods);
    virtual ~ClassNode();

    std::string *getName() const;
    std::string *getExtends() const;

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    void preprocess(ASTProcessor *ast_processor) override;
    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

#endif
