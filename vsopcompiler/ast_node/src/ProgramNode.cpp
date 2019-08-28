#include "../headers/ProgramNode.h"

ProgramNode::ProgramNode()
    : Node()
{
    debugger->printCall("ProgramNode::ProgramNode");

    this->classes = new std::vector<Node *>();

    debugger->printEnd();
}

ProgramNode::~ProgramNode()
{
    debugger->printCall("ProgramNode::~ProgramNode");

    for (std::vector<Node *>::iterator it = this->classes->begin(); it != this->classes->end(); it++)
    {
        delete (*it);
    }
    delete (this->classes);

    debugger->printEnd();
}

void ProgramNode::addClass(Node *toAdd)
{
    this->classes->push_back(toAdd);
}

bool ProgramNode::doesSubTreeContains(std::string *id)
{
    debugger->printCall("ProgramNode::doesSubTreeContains");

    for (std::vector<Node *>::iterator it = this->classes->begin(); it != this->classes->end(); it++)
    {
        if ((*it)->doesSubTreeContains(id))
        {
            debugger->printEnd();
            return true;
        }
    }

    debugger->printEnd();
    return false;
}

void ProgramNode::print(std::ostream &os) const
{
    debugger->printCall("ProgramNode::print");

    os << "[";
    this->indent++;

    if (this->classes->size() > 0)
    {
        os << *this->classes->front();

        std::vector<Node *>::iterator it = this->classes->begin();
        it++;
        for (; it != this->classes->end(); it++)
        {
            os << "," << std::endl;

            for (int i = 0; i < this->indent; ++i)
            {
                os << " ";
            }
            os << **it;
        }
    }

    os << "]";
    this->indent--;

    debugger->printEnd();
}

void ProgramNode::preprocess(ASTProcessor *ast_processor)
{
    debugger->printCall("ProgramNode::preprocess");

    /// Register all the declared classes
    for (std::vector<Node *>::iterator it = this->classes->begin(); it != this->classes->end(); it++)
    {
        /// Check that only classes are declared under program
        if (ClassNode *classNode = dynamic_cast<ClassNode *>(*it))
        {

            /// Check that the classes are only define once
            if (ast_processor->exist(classNode->getName()))
            {
                throw ASTProcessorException(*classNode->getFilename(), classNode->getLine(), classNode->getColumn(),
                                            "The class has been define several times -- " + *classNode->getName());
            }

            ast_processor->registerClass(classNode->getName(), classNode);
        }
        else
        {
            throw ASTProcessorException(*(*it)->getFilename(), (*it)->getLine(), (*it)->getColumn(),
                                        "Unexpected expression in program body");
        }
    }
    debugger->printStep("Declared class check pass");

    /// Preprocess all the classes
    for (std::vector<Node *>::iterator it = this->classes->begin(); it != this->classes->end(); it++)
    {
        (*it)->preprocess(ast_processor);
    }
    debugger->printStep("Class preprocess pass");

    /// Check if there is a Main class exist
    if (!ast_processor->symbolTable->hasScope(new std::string("Main")))
    {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                    "Can't find the Main class");
    }
    debugger->printStep("Main check pass");

    ast_processor->symbolTable->enterSavedScope(new std::string("Main"));
    MethodEntry *mainMethod = ast_processor->symbolTable->findMethod(new std::string("main"));

    /// Check that Main::main exist
    if (!mainMethod)
    {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                    "Can't find Main::main()");
    }
    debugger->printStep("Main::main existance check pass");

    /// Check the Main::main formals : none expected
    if (mainMethod->formalsNumber() != 0)
    {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                    "Main::main() should have no argument");
    }
    debugger->printStep("Main::main number of formals check pass");

    /// Check the output's type of Main::main : expected int32
    if (*mainMethod->getType() != "int32")
    {
        throw ASTProcessorException(*this->getFilename(), this->getLine(), this->getColumn(),
                                    "Main::main() return type should be int32");
    }
    debugger->printStep("Main::main output type check pass");

    debugger->printEnd();
}

void ProgramNode::check(ASTProcessor *ast_processor)
{
    debugger->printCall("ProgramNode::check");

    /// Check each class in the program
    for (std::vector<Node *>::iterator it = this->classes->begin(); it != this->classes->end(); it++)
    {
        (*it)->check(ast_processor);
    }

    debugger->printEnd();
}

llvm::Value *ProgramNode::codeGen(ASTProcessor *ast_processor) {
    debugger->printCall("ProgramNode::codeGen");

    // TODO

    debugger->printEnd();
    return nullptr;
}
