#ifndef SYNTATIC_ANALYSIS_H
#define SYNTATIC_ANALYSIS_H

#include <map>
#include "../lexical/LexicalAnalysis.h"
#include "../interpreter/value/Type.h"
#include "../interpreter/command/Command.h"
#include "../interpreter/command/WriteCommand.h"
#include "../interpreter/command/ReadCommand.h"
#include "../interpreter/command/AssignCmd.h"
#include "../interpreter/command/AssignCmd.cpp"
#include "../interpreter/command/BlocksCommand.h"
#include "../interpreter/command/BlocksCommand.cpp"
#include "../interpreter/command/CaseCommand.h"
#include "../interpreter/command/CaseCommand.cpp"
#include "../interpreter/command/CaseOption.h"
#include "../interpreter/command/CaseOption.cpp"
#include "../interpreter/command/Command.h"
#include "../interpreter/command/ForCommand.h"
#include "../interpreter/command/ForCommand.cpp"
#include "../interpreter/command/IfCommand.h"
#include "../interpreter/command/IfCommand.cpp"
#include "../interpreter/command/ReadCommand.h"
#include "../interpreter/command/ReadCommand.cpp"
#include "../interpreter/command/RepeatCommand.h"
#include "../interpreter/command/RepeatCommand.cpp"
#include "../interpreter/command/WhileCommand.h"
#include "../interpreter/command/WhileCommand.cpp"
#include "../interpreter/command/WriteCommand.h"
#include "../interpreter/command/WriteCommand.cpp"
#include "../interpreter/expr/BinaryExpr.h"
#include "../interpreter/expr/BinaryExpr.cpp"
#include "../interpreter/expr/BinaryOp.h"
#include "../interpreter/expr/BoolExpr.h"
#include "../interpreter/expr/BoolExpr.cpp"
#include "../interpreter/expr/BoolOp.h"
#include "../interpreter/expr/CompositeBoolExpr.h"
#include "../interpreter/expr/CompositeBoolExpr.cpp"
#include "../interpreter/expr/ConstExpr.h"
#include "../interpreter/expr/ConstExpr.cpp"
#include "../interpreter/expr/Expr.h"
#include "../interpreter/expr/Expr.cpp"
#include "../interpreter/expr/NotBoolExpr.h"
#include "../interpreter/expr/NotBoolExpr.cpp"
#include "../interpreter/expr/RelOp.h"
#include "../interpreter/expr/SingleBoolExpr.h"
#include "../interpreter/expr/SingleBoolExpr.cpp"
#include "../interpreter/expr/Variable.h"
#include "../interpreter/expr/Variable.cpp"
#include "../interpreter/util/Memory.h"
#include "../interpreter/util/Memory.cpp"

class Command;

class SyntaticAnalysis {
public:
    explicit SyntaticAnalysis(LexicalAnalysis& lex);
    virtual ~SyntaticAnalysis();

    Command* start();

private:
    LexicalAnalysis& m_lex;
    Lexeme m_current;

    void matchToken(enum TokenType type);
    void showError();

    Command* procProgram();
    void procConst();
    void procVar();
    Command* procBody();
    BlocksCommand* procBlock();
    Command* procCmd();
    AssignCommand* procAssign();
    IfCommand* procIf();
    CaseCommand* procCase();
    WhileCommand* procWhile();
    RepeatCommand* procRepeat();
    ForCommand* procFor();
    WriteCommand* procWrite();
    ReadCommand* procRead();
    BoolExpr* procBoolExpr();
    SingleBoolExpr* procCmpExpr();
    Expr* procExpr();
    Expr* procTerm();
    Expr* procFactor();
    Type* procValue();
    Variable* procId();
    IntegerValue* procInteger();
    RealValue* procReal();
    StringValue* procString();
};

#endif
