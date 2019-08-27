#ifndef INFO0085_VSOPCOMPILER_2_ASTNODE_H
#define INFO0085_VSOPCOMPILER_2_ASTNODE_H


#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

//#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/APInt.h"
#include "llvm/ADT/SmallString.h"
//#include "llvm/ADT/STLExtras.h"
// #include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
//#include "llvm/IR/Function.h"
//#include "llvm/IR/IRBuilder.h"
//#include "llvm/IR/LLVMContext.h"
//#include "llvm/IR/Module.h"
//#include "llvm/IR/Type.h"
//#include "llvm/IR/Verifier.h"
#include "llvm/IR/Value.h"


class ASTProcessor;
class Debugger;

extern Debugger *debugger;


class Node {
private:
    std::string *filename;
    int line;
    int column;
    std::string *returnType;

protected:
    static int indent;

public:
    Node();
    virtual ~Node();

    void setPosition(std::string filename, int line = -1, int column = -1);
    std::string *getFilename() const;
    int getLine() const;
    int getColumn() const;

    void setReturnType(std::string *type);
    std::string *getReturnType() const;

    virtual bool doesSubTreeContains(std::string *id);

    friend std::ostream &operator<<(std::ostream &os, const Node &node);
    virtual void print(std::ostream &os) const;

    virtual void preprocess(ASTProcessor *ast_processor);
    virtual void check(ASTProcessor *ast_processor);
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor) = 0;
};


class ProgramNode
        : public Node {
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


class ClassNode
        : public Node {
private:
    std::string *name;
    std::string *extends;
    std::vector<Node *> *fields;
    std::vector<Node *> *methods;

public:
    ClassNode(std::string *name, std::string *extends,
              std::pair<std::vector <Node *> *, std::vector<Node *> *> *fieldsAndMethods);
    virtual ~ClassNode();

    std::string *getName() const;
    std::string *getExtends() const;

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    void preprocess(ASTProcessor *ast_processor) override;
    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class FieldNode
        : public Node {
private:
    std::string *name;
    std::string *staticType;
    Node *expr;

public:
    FieldNode(std::string *name, std::string *type);
    FieldNode(std::string *name, std::string *type, Node *expr);
    virtual ~FieldNode();

    std::string *getName() const;

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    void preprocess(ASTProcessor *ast_processor) override;
    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class MethodNode
        : public Node {
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


class FormalNode
        : public Node {
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


class BlockNode
        : public Node {
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


class IfNode
        : public Node {
private:
    Node *condition;
    Node *iftrue;
    Node *iffalse;

public:
    IfNode(Node *condition, Node *iftrue);
    IfNode(Node *conditon, Node *iftrue, Node *iffalse);
    virtual ~IfNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class WhileNode
        : public Node {
private:
    Node *condition;
    Node *expression;

public:
    WhileNode(Node *condition, Node *expr);
    virtual ~WhileNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class LetNode
        : public Node {
private:
    std::string *objectName;
    std::string *staticType;
    Node *assign;
    Node *expression;

public:
    LetNode(std::string *name, std::string *type, Node *expr);
    LetNode(std::string *name, std::string *type, Node *assign, Node *expr);
    virtual ~LetNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class AssignNode
        : public Node {
private:
    std::string *objectName;
    Node *expression;

public:
    AssignNode(std::string *object, Node *expr);
    virtual ~AssignNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class CallNode
        : public Node {
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


class NewNode
        : public Node {
private:
    std::string *staticType;

public:
    NewNode(std::string *type);
    virtual ~NewNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class BinOpNode
        : public Node {
protected:
    Node *left;
    Node *right;

public:
    BinOpNode(Node *left, Node *right);
    virtual ~BinOpNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;
    void printBinOp(std::ostream &os, std::string str) const;

    virtual void check(ASTProcessor * ast_processor) override;
    void checkBinOp(ASTProcessor  *ast_processor, std::string returnType);
    void checkBinOp(ASTProcessor  *ast_processor, std::string returnType, std::string testType);
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor) = 0;
};


class AndNode
        : public BinOpNode {
public:
    AndNode(Node *left, Node *right);
    virtual ~AndNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class EqualNode
        : public BinOpNode {
public:
    EqualNode(Node *left, Node *right);
    virtual ~EqualNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class LowerNode
        : public BinOpNode {
public:
    LowerNode(Node *left, Node *right);
    virtual ~LowerNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class LowerEqualNode
        : public BinOpNode {
public:
    LowerEqualNode(Node *left, Node *right);
    virtual ~LowerEqualNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class PlusNode
        : public BinOpNode {
public:
    PlusNode(Node *left, Node *right);
    virtual ~PlusNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class MinusNode
        : public BinOpNode {
public:
    MinusNode(Node *left, Node *right);
    virtual ~MinusNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class TimesNode
        : public BinOpNode {
public:
    TimesNode(Node *left, Node *right);
    virtual ~TimesNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class DivNode
        : public BinOpNode {
public:
    DivNode(Node *left, Node *right);
    virtual ~DivNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class PowNode
        : public BinOpNode {
public:
    PowNode(Node *left, Node *right);
    virtual ~PowNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class UnOpNode
        : public Node {
protected:
    Node *expression;

public:
    UnOpNode(Node *expr);
    virtual ~UnOpNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;
    void printUnOp(std::ostream &os, std::string str) const;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor) = 0;
};


class NotNode
        : public UnOpNode {
public:
    NotNode(Node *expr);
    virtual ~NotNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class NegNode
        : public UnOpNode {
public:
    NegNode(Node *expr);
    virtual ~NegNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class IsNullNode
        : public UnOpNode {
public:
    IsNullNode(Node *expr);
    virtual ~IsNullNode();

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class ObjectNode
        : public Node {
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


class BoolLiteralNode
        : public Node {
private:
    bool value;

public:
    BoolLiteralNode(bool value);
    virtual ~BoolLiteralNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};

class IntLiteralNode
        : public Node {
private:
    int value;

public:
    IntLiteralNode(int value);
    virtual ~IntLiteralNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


class StrLiteralNode
        : public Node {
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

class UnitNode
        : public Node {
public:
    UnitNode();
    virtual ~UnitNode();

    virtual bool doesSubTreeContains(std::string *id) override;

    virtual void print(std::ostream &os) const override;

    virtual void check(ASTProcessor *ast_processor) override;
    virtual llvm::Value *codeGen(ASTProcessor *ast_processor);
};


#endif //INFO0085_VSOPCOMPILER_2_ASTNODE_H
