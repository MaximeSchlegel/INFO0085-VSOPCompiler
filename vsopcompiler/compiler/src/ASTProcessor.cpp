#include "ASTProcessor.h"

#include "../../ast_node/ASTNode.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"



ASTProcessor::ASTProcessor(ProgramNode *root) {
    this->root = root;
    this->waitingQueue = new std::vector<ClassNode *>();
    this->declaredClasses = new std::map<std::string, Node*>();
    this->symbolTable = new SymbolTable();

    this->llvmBuilder = new llvm::IRBuilder<>(this->llvmContext);
    this->llvmModule = llvm::make_unique<llvm::Module>("llvmModule", this->llvmContext);

    /// Add the native types to the extend table
    this->declaredClasses->emplace("int32", nullptr);
    this->declaredClasses->emplace("bool", nullptr);
    this->declaredClasses->emplace("string", nullptr);
    this->declaredClasses->emplace("unit", nullptr);
    this->declaredClasses->emplace("Object", nullptr);
    this->declaredClasses->emplace("IO", nullptr);

    /// Add the Object and IO scopes
    std::string *obj = new std::string("Object");
    std::string *io = new std::string("IO");
    this->symbolTable->createNewSavedScope(obj);
    this->symbolTable->createNewSavedScope(io, obj);

    /// Create the base IO functions
    VariableEntry *formal;
    std::vector<VariableEntry *> *formals;
    this->symbolTable->enterSavedScope(io);

    formal = new VariableEntry(new std::string("input"), new std::string("string"));
    formals = new std::vector<VariableEntry *>();
    formals->push_back(formal);
    this->symbolTable->addEntry(new std::string("print"), io, formals);

    formal = new VariableEntry(new std::string("input"), new std::string("bool"));
    formals = new std::vector<VariableEntry *>();
    formals->push_back(formal);
    this->symbolTable->addEntry(new std::string("printBool"), io, formals);

    formal = new VariableEntry(new std::string("input"), new std::string("int32"));
    formals = new std::vector<VariableEntry *>();
    formals->push_back(formal);
    this->symbolTable->addEntry(new std::string("printInt32"), io, formals);

    formals = new std::vector<VariableEntry *>();
    this->symbolTable->addEntry(new std::string("inputLine"), new std::string("string"), formals);

    formals = new std::vector<VariableEntry *>();
    this->symbolTable->addEntry(new std::string("inputBool"), new std::string("bool"), formals);

    formals = new std::vector<VariableEntry *>();
    this->symbolTable->addEntry(new std::string("inputInt32"), new std::string("int32"), formals);

    this->symbolTable->exitToRoot();
}

ASTProcessor::~ASTProcessor() {
    delete (this->declaredClasses);
}

void ASTProcessor::registerClass(std::string *id, ClassNode *node) {
    debugger->printCall("Checker::registerClass : id=" + *id);

    this->declaredClasses->emplace(*id, node);

    debugger->printEnd();
}

Node* ASTProcessor::strToNode(std::string *id) const {
    debugger->printCall("Checker::strToNode : id=" + *id);

    std::map<std::string, Node*>::iterator target = this->declaredClasses->find(*id);

    debugger->printEnd();
    return (target != this->declaredClasses->end()) ? target->second : nullptr;
}

bool ASTProcessor::exist(std::string *id) const {
    std::map<std::string, Node*>::iterator target = this->declaredClasses->find(*id);
    return target != this->declaredClasses->end();
}

void ASTProcessor::addWaiting(ClassNode *node) {
    this->waitingQueue->push_back(node);
}

void ASTProcessor::popWaiting() {
    this->waitingQueue->pop_back();
}

bool ASTProcessor::isWaiting(std::string *id) {
    for (std::vector <ClassNode *>::iterator it = this->waitingQueue->begin(); it != this->waitingQueue->end(); it++) {
        if (*(*it)->getName() == *id) {
            return true;
        }
    }
    return false;
}

bool ASTProcessor::isChildOf(std::string *subClass, std::string *testClass) {
    debugger->printCall("Checker::isChildOf : subClass=" + *subClass + ", testClass=" + *testClass);

    if (*subClass == *testClass) {
        debugger->printEnd();
        return true;
    }
    debugger->printStep("Equal class check pass");

    ClassNode *entry = (ClassNode *) this->strToNode(subClass);
    debugger->printStep("Entry get");

    while (entry) {
        if (*entry->getExtends() == *testClass) {
            debugger->printEnd();
            return true;
        }
        entry = (ClassNode *) this->strToNode(entry->getExtends());
    }

    debugger->printEnd();
    return false;
}

std::string *ASTProcessor::getFirstCommonAncestor(std::string *c1, std::string *c2) {
    if (this->isChildOf(c1, c2)) {
        return c2;
    }
    return this->getFirstCommonAncestor(c1, ((ClassNode *) this->strToNode(c2))->getExtends());
}

void ASTProcessor::check() {
    debugger->printCall("ASTProcessor::preprocess");
    this->root->preprocess(this);
    debugger->printEnd();

    debugger->printCall("ASTProcessor::check");
    this->root->check(this);
    debugger->printEnd();
}

void ASTProcessor::codeGen() {
    this->root->codeGen(this);
}
