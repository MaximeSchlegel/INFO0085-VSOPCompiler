#include "../ASTNode.h"

#include "../../compiler/src/ASTProcessor.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"


UnitNode::UnitNode()
        :Node() {
    debugger->printCall("UnitNode::UnitNode");
    debugger->printEnd();

}

UnitNode::~UnitNode() {
    debugger->printCall("UnitNode::~UnitNode");
    debugger->printEnd();
}

bool UnitNode::doesSubTreeContains(std::string *id) {
    debugger->printCall("UnitNode::doesSubTreeContains");

    debugger->printEnd();
    return false;
}

void UnitNode::print(std::ostream &os) const {
    debugger->printCall("UnitNode::print");

    os << "()";
    if(this->getReturnType()) {
        std::cout << " : unit";
    }

    debugger->printEnd();
}

void UnitNode::check(ASTProcessor *ast_processor) {
    debugger->printCall("UnitNode::check");

    this->setReturnType(new std::string("unit"));

    debugger->printEnd();
}

llvm::Value *UnitNode::codeGen(ASTProcessor *ast_processor) {
    return llvm::Constant::getNullValue(llvm::Type::getDoubleTy(ast_processor->llvmContext));
}
