#include <cstdlib>
#include "SyntaticAnalysis.h"

#include "../interpreter/command/Command.h"

SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex) :
    m_lex(lex), m_current(m_lex.nextToken()) {
}

SyntaticAnalysis::~SyntaticAnalysis() {
}

Command* SyntaticAnalysis::start() {
    return 0;
}

void SyntaticAnalysis::matchToken(enum TokenType type) {
    // printf("Match token: %d -> %d (\"%s\")\n", m_current.type, type, m_current.token.c_str());
    if (type == m_current.type) {
        m_current = m_lex.nextToken();
    } else {
        showError();
    }
}

void SyntaticAnalysis::showError() {
    printf("%02d: ", m_lex.line());

    switch (m_current.type) {
        case TKN_INVALID_TOKEN:
            printf("Lexema inválido [%s]\n", m_current.token.c_str());
            break;
        case TKN_UNEXPECTED_EOF:
        case TKN_END_OF_FILE:
            printf("Fim de arquivo inesperado\n");
            break;
        default:
            printf("Lexema não esperado [%s]\n", m_current.token.c_str());
            break;
    }

    exit(1);
}

// <program>  ::= program <id> ';'
//                [ const <const> { <const> } ]
//                [ var <var> { <var> } ]
//                <block> '.'
void SyntaticAnalysis::procProgram() {
}

// <const>    ::= <id> = <value> ';'
void SyntaticAnalysis::procConst() {
}

// <var>      ::= <id> { ',' <id> } [ = <value> ] ';'
void SyntaticAnalysis::procVar() {
}

// <block>    ::= begin [ <cmd> { ';' <cmd> } ] end
void SyntaticAnalysis::procBlock() {
}

// <body>     ::= <block> | <cmd>
void SyntaticAnalysis::procBody() {
}

// <cmd>      ::= <assign> | <if> | <case> | <while> | <for> | <repeat> | <write> | <read>
void SyntaticAnalysis::procCmd() {
}

// <assign>   ::= <id> := <expr>
void SyntaticAnalysis::procAssign() {
}

// <if>       ::= if <boolexpr> then <body> [else <body>]
void SyntaticAnalysis::procIf() {
}

// <case>     ::= case <expr> of { <value> : <body> ';' } [ else <body> ';' ] end
void SyntaticAnalysis::procCase() {
}

// <while>    ::= while <boolexpr> do <body>
void SyntaticAnalysis::procWhile() {
}

// <repeat>   ::= repeat [ <cmd> { ';' <cmd> } ] until <boolexpr>
void SyntaticAnalysis::procRepeat() {
}

// <for>      ::= for <id> := <expr> to <expr> do <body>
void SyntaticAnalysis::procFor() {
}

// <write>    ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
void SyntaticAnalysis::procWrite() {
}

// <read>     ::= readln '(' <id> { ',' <id> } ')'
void SyntaticAnalysis::procRead() {
}

// <boolexpr> ::= [ not ] <cmpexpr> { (and | or) <boolexpr> }
void SyntaticAnalysis::procBoolExpr() {
}

// <cmpexpr>  ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr> | '(' <boolexpr> ')'
void SyntaticAnalysis::procCmpExpr() {
}

// <expr>     ::= <term> { ('+' | '-') <term> }
void SyntaticAnalysis::procExpr() {
}

// <term>     ::= <factor> { ('*' | '/' | '%') <factor> }
void SyntaticAnalysis::procTerm() {
}

// <factor>   ::= <value> | <id> | '(' <expr> ')'
void SyntaticAnalysis::procFactor() {
}

// <value>    ::= <integer> | <real> | <string>
void SyntaticAnalysis::procValue() {
}

void SyntaticAnalysis::procId() {
}

void SyntaticAnalysis::procInteger() {
}

void SyntaticAnalysis::procReal() {
}

void SyntaticAnalysis::procString() {
}
