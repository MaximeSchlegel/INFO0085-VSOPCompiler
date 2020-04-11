#ifndef INFO0085_VSOPCOMPILER_2_EXCEPTION_H
#define INFO0085_VSOPCOMPILER_2_EXCEPTION_H


#include <exception>
#include <ostream>
#include <string>


class ProjectException
        : public std::exception {
private:
    std::string errorText;

public:
    ProjectException(std::string errorText);
    virtual ~ProjectException();

    virtual const char *what() const throw();

    friend std::ostream &operator<<(std::ostream &os, const ProjectException &exception);

    virtual void print(std::ostream &os) const;
    virtual void printError(std::ostream &os, std::string errorType) const;

};


class CompilerException
        : public ProjectException {
private:
    std::string filename;
    int linePos;
    int colPos;

public:
    CompilerException(std::string filename, int line, int column, std::string errorText);
    virtual ~CompilerException();

    virtual const char *getFilename() const;
    virtual int getLineNumber() const;
    virtual int getColumnNumber() const;

    virtual void print(std::ostream &os) const override ;
    virtual void printError(std::ostream &os, std::string errorType) const override;
};


class LexerException
        : public CompilerException {
public:
    LexerException(std::string filename, int line, int column, std::string errorText);
    virtual ~LexerException();

    void print(std::ostream &os) const override;
};


class ParserException
        : public CompilerException {
public:
    ParserException(std::string filename, int line, int column, std::string errorText);
    virtual ~ParserException();

    void print(std::ostream &os) const override;
};


class ASTProcessorException
        : public CompilerException {
public:
    ASTProcessorException(std::string filename, int line, int column, std::string errorText);
    virtual ~ASTProcessorException();

    void print(std::ostream &os) const override;
};


class ASTException
        : public ProjectException {
public:
    ASTException(std::string errorText);
    virtual ~ASTException();

    void print(std::ostream &os) const override;
};


class SymbolTableException
        : public ProjectException {

public:
    SymbolTableException(std::string errorTxt);
    ~SymbolTableException();

    void print(std::ostream &os) const override;
};


class ExceptionsHolder
        : public std::exception {
private:
    std::vector<ProjectException *> *errors;

public:
    ExceptionsHolder ();
    ExceptionsHolder (ProjectException error);
    ExceptionsHolder (ProjectException *error);
    virtual ~ExceptionsHolder();

    virtual const char *what() const throw();
    std::vector<std::exception> *getErrors();
    bool isEmpty();

    void add(ProjectException error);
    void add(ExceptionsHolder error);

    friend std::ostream &operator<<(std::ostream &os, const ProjectException &exception);
};


#endif //INFO0085_VSOPCOMPILER_2_EXCEPTION_H
