#include "../headers/ObjectNode.h"

ObjectNode::ObjectNode(std::string *name)
{
    debugger->printCall("ObjectNode::ObjectNode : name=" + *name);

    this->name = name;
    this->type = nullptr;

    debugger->printEnd();
}

ObjectNode::ObjectNode(std::string *name, std::string *type)
{
    debugger->printCall("ObjectNode::ObjectNode : name=" + *name + ", type=" + *type);

    this->name = name;
    this->type = type;

    debugger->printEnd();
}

ObjectNode::~ObjectNode()
{
    debugger->printCall("ObjectNode::~ObjectNode");

    delete (this->name);
    delete (this->type);

    debugger->printEnd();
}

void ObjectNode::setType(std::string *type)
{
    this->type = type;

    debugger->printEnd();
}

bool ObjectNode::doesSubTreeContains(std::string *id)
{
    debugger->printCall("ObjectNode::doesSubTreeContains");

    if (*this->name == *id)
    {
        debugger->printEnd();
        return true;
    }
    if (this->type && *this->type == *id)
    {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void ObjectNode::print(std::ostream &os) const
{
    debugger->printCall("ObjectNode::print");

    os << *this->name;
    if (this->getReturnType())
    {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void ObjectNode::check(ASTProcessor *ast_processor)
{
    debugger->printCall("ObjectNode::check");

    /// Check that the object is declare in the scope
    VariableEntry *object = ast_processor->symbolTable->lookupVariable(this->name);
    if (!object)
    {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                    "Object is not define in scope -- " + *this->name);
    }

    this->setReturnType(object->getType());

    debugger->printEnd();
}

llvm::Value *ObjectNode::codeGen(ASTProcessor *ast_processor)
{

llvm::Value *ObjectNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("ObjectNode::codeGen");

    debugger->printEnd();
    return nullptr;
}
