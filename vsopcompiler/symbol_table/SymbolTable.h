#ifndef INFO0085_VSOPCOMPILER_2_SYMBOLTABLE_H
#define INFO0085_VSOPCOMPILER_2_SYMBOLTABLE_H


#include <string>
#include <vector>
#include <map>


class Node;
class Debugger;

extern Debugger *debugger;


class SymbolTableEntry {
private:
    std::string *id;
    std::string *type;

public:
    SymbolTableEntry(std::string *id, std::string *type);
    virtual ~SymbolTableEntry();

    std::string *getId();
    std::string *getType();

};


class VariableEntry
        : public SymbolTableEntry {
public:
    VariableEntry(std::string *id, std::string *type);
    virtual ~VariableEntry();
};


class MethodEntry
        : public SymbolTableEntry {
private:
    std::vector<VariableEntry *> *formals;

public:
    MethodEntry(std::string *id, std::string *type, std::vector<VariableEntry *> *formals);
    virtual ~MethodEntry();

    long unsigned int formalsNumber() const;
    std::vector<VariableEntry *> *getFormals() const;
    VariableEntry *getFormal(int i) const;
};


class SymbolTableScope {
private:
    SymbolTableScope *parent;
    std::map<std::string, VariableEntry *> *variables;
    std::map<std::string, MethodEntry *> *methods;

public:

    SymbolTableScope(SymbolTableScope *parent);
    virtual ~SymbolTableScope();

    void emplace(std::string *id, std::string *type);
    VariableEntry *findVariable(std::string *id) const;
    VariableEntry *lookupVariable(std::string *id) const;
    std::vector<VariableEntry *> *getVariables() const;

    void emplace(std::string *id, std::string *type, std::vector<VariableEntry *> *formals);
    MethodEntry *findMethod(std::string *id) const;
    MethodEntry *lookupMethod(std::string *id) const;
    std::vector<MethodEntry *> *getMethods() const;

    SymbolTableScope *getParent() const;
};


class SymbolTable{
private:
    SymbolTableScope *rootScope;
    SymbolTableScope *currentScope;
    SymbolTableScope *previousScope;

    std::map<std::string, SymbolTableScope*> *savedScope;

public:
    SymbolTable();
    virtual ~SymbolTable();

    void enterNewScope();
    void enterSavedScope(std::string *id=new std::string());
    void exitToRoot();
    void exitToPrevious();
    void exitToParent();

    void createNewSavedScope(std::string *id);
    void createNewSavedScope(std::string *id, std::string *parent);
    bool hasScope(std::string *id);

    void addEntry(std::string *id, std::string *type);
    void addEntry(std::string *id, std::string *type, std::vector<VariableEntry *> *formals);

    VariableEntry *findVariable(std::string *id) const;
    VariableEntry *lookupVariable(std::string *id) const;
    std::vector<VariableEntry *> *getVariablesInScope() const;

    MethodEntry *findMethod(std::string *id) const;
    MethodEntry *lookupMethod(std::string *id) const;
    std::vector<MethodEntry *> *getMethodsInScope() const;
};

#endif