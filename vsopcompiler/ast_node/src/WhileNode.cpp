#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


WhileNode::WhileNode(Node *condition, Node *expr) {
    debugger->printCall("WhileNode::WhileNode");

    this->condition = condition;
    this->expression = expr;

    debugger->printEnd();
}

WhileNode::~WhileNode() {
    debugger->printCall("WhileNode::~WhileNode");

    delete (this->condition);
    delete (this->expression);

    debugger->printEnd();
}

bool WhileNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("WhileNode::doesSubTreeContains");

    if (condition->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }
    if (expression->doesSubTreeContains(id)) {
        debugger->printEnd();
        return true;
    }

    debugger->printEnd();
    return false;
}

void WhileNode::print(std::ostream &os) const {
    debugger->printCall("WhileNode::print");

    os << "While("; this->indent += 7;
    os << *this->condition << "," << std::endl;

    for (int i = 0; i < this->indent; ++i) { os << " "; }
    os << *this->expression << ")"; this->indent -= 7;

    if (this->getReturnType()) {
        os << " : " << *this->getReturnType();
    }

    debugger->printEnd();
}

void WhileNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("WhileNode::check");

    /// Check Subtree
    ast_processor->symbolTable->enterNewScope();
    this->condition->check(ast_processor);
    ast_processor->symbolTable->exitToParent();
    ast_processor->symbolTable->enterNewScope();
    this->expression->check(ast_processor);
    ast_processor->symbolTable->exitToParent();


    /// Check that the conditon has bool type
    if (*this->condition->getReturnType() != "bool") {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                "While condition is expected of type bool -- " + *this->condition->getReturnType());
    }

    this->setReturnType(new std::string("unit"));

    debugger->printEnd();
}

llvm::Value *WhileNode::codeGen(ASTProcessor *ast_processor)
{
    debugger->printCall("WhileNode::codeGen");

    /// Create condition block
    llvm::Function *function = ast_processor->llvmbuilder->GetInsertBlock()->getParent();

    llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ast_processor->llvmContext, "condBlock", function);

    /// Evaluate condition
    ast_processor->llvmBuilder->SetInsertPoint(condBlock);

    llvm::Value *condValue = this->condition->codeGen(ast_processor);
    if (!condValue)
    {
        return nullptr;
    }

    /// Convert condition to a bool by comparing non-equal to 0.0
    condValue = ast_processor->llvmBuilder->CreateFCmpONE(condValue, llvm::ConstantFP::get(ast_processor->llvmContext, llvm::APFloat(0.0)), "ifcond");

    /// Create blocks for loop and end of loop
    llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ast_processor->llvmContext, "loopBlock");
    llvm::BasicBlock *endWhileBlock = llvm::BasicBlock::Create(ast_processor->llvmContext, "endWhileBlock");

    /// Conditional branch according to the condition
    ast_processor->llvmBuilder->CreateCondBr(condValue, loopBlock, endWhileBlock);

    /// Emit loop block
    function->getBasicBlockList().push_back(loopBlock);
    ast_processor->llvmBuilder->SetInsertPoint(loopBlock);

    llvm::Value *loopValue = this->expression->codeGen(ast_processor);
    if (!loopValue)
    {
        return nullptr;
    }

    /// End of loop. Go to condition
    ast_processor->llvmBuilder->CreateBr(endWhileBlock);
    loopBlock = ast_processor->llvmBuilder->GetInsertBlock();

    /// Emit end block
    function->getBasicBlockList().push_back(endWhileBlock);
    ast_processor->llvmBuilder->SetInsertPoint(endWhileBlock);

    debugger->printEnd();
    return Constant::getNullValue(Type::getDoubleTy(TheContext));
}
