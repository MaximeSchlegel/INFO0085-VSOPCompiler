#include "../headers/IsNullNode.h"


IsNullNode::IsNullNode(Node *expr)
        : UnOpNode(expr) {
    debugger->printCall("IsNullNode::IsNullNode");
    debugger->printEnd();
}

IsNullNode::~IsNullNode() {
    debugger->printCall("IsNullNode::~IsNullNode");
    debugger->printEnd();
}

void IsNullNode::print(std::ostream &os) const {
    debugger->printCall("IsNullNode::print");

    this->printUnOp(os, "isnull");

    debugger->printEnd();
}

void IsNullNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("IsNullNode::check");

    /// Check the Subtree
    this->expression->check(ast_processor);

    ///Check the type of the expression - expected : child of Object
    if (!ast_processor->isChildOf(this->expression->getReturnType(), new std::string("Object"))) {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "SubType of Object expected -- " + *this->expression->getReturnType());
    }

    this->setReturnType(new std::string("bool"));

    debugger->printEnd();
}

llvm::Value *IsNullNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("IsNullNode::codeGen");

    llvm::Value *value = this->expression->codeGen(ast_processor);

    if (!value)
    {
        return nullptr;
    }

    debugger->printEnd();
    return ast_processor->llvmBuilder->CreateIsNull(value, "isnulltmp");
}
