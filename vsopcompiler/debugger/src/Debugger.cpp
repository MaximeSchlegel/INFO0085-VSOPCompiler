#include "../Debugger.h"


Debugger::Debugger(bool activate) {
    this->active = activate;
    this->indent = 0;
    if (this->active){
        std::cout << std::endl << "Debug Mode" << std::endl;
    }
}

Debugger::~Debugger() {}

void Debugger::print(std::string message) {
    if (this->active) {
        std::cout << std::endl << "DEBUG LOG : " << message << std::endl;
    }
}

void Debugger::printCall(std::string message) {
    if (this->active) {
        std::cout << std::endl << "DEBUG LOG : ";
        for (int i = 0; i < this->indent; ++i) {std::cout << " ";}
        std::cout << message << std::endl;
    }
    this->indent += 2;
}

void Debugger::printStep(std::string message) {
    if (this->active) {
        std::cout << std::endl << "DEBUG LOG : ";
        for (int i = 0; i < this->indent; ++i) {std::cout << " ";}
        std::cout << message << std::endl;
    }
}

void Debugger::printEnd() {
    if (this->active) {
        std::cout << std::endl << "DEBUG LOG : ";
        for (int i = 0; i < this->indent; ++i) {std::cout << " ";}
        std::cout << "END" << std::endl;
    }
    this->indent -= 2;
}