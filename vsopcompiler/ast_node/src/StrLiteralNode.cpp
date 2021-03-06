#include "../headers/StrLiteralNode.h"

StrLiteralNode::StrLiteralNode(std::string *value)
    : Node()
{
    debugger->printCall("StrLiteralNode::StrLiteralNode");

    this->value = value;

    debugger->printEnd();
}

StrLiteralNode::~StrLiteralNode()
{
    debugger->printCall("StrLiteralNode::~StrLiteralNode");

    delete (this->value);

    debugger->printEnd();
}

bool StrLiteralNode::doesSubTreeContains(std::string *id)
{
    debugger->printCall("StrLiteralNode::doesSubTreeContains: id=" + *id);

    debugger->printEnd();
    return false;
}

void StrLiteralNode::print(std::ostream &os) const
{
    debugger->printCall("StrLiteralNode::print");

    os << *this->value;
    if (this->getReturnType())
    {
        os << " : string";
    }

    debugger->printEnd();
}

void StrLiteralNode::check(ASTProcessor *ast_processor)
{
    debugger->printCall("StrLiteralNode::check");

    this->setReturnType(new std::string("string"));

    debugger->printEnd();
}


llvm::Value * StrLiteralNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("StrLitteralNode::codeGen");
    debugger->printEnd();
    return llvm::ConstantDataArray::getString(ast_processor->llvmContext, *this->value, false);
}
