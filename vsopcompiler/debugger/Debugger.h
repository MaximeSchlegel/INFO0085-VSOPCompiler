#ifndef INFO0085_VSOPCOMPILER_2_DEBUGGER_H
#define INFO0085_VSOPCOMPILER_2_DEBUGGER_H

#include <iostream>
#include <string>

class Debugger {
private:
    bool active;
    int indent;

public:
    Debugger(bool activate);
    ~Debugger();

    void print(std::string message);
    void printCall(std::string message);
    void printStep(std::string message);
    void printEnd();
};

#endif //INFO0085_VSOPCOMPILER_2_DEBUGGER_H
