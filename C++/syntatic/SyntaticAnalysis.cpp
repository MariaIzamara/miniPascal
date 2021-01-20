#include <cstdlib>
#include "SyntaticAnalysis.h"

#include "../interpreter/command/Command.h"

SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex) :
    m_lex(lex), m_current(m_lex.nextToken()) {
}

SyntaticAnalysis::~SyntaticAnalysis() {
}

Command* SyntaticAnalysis::start() {
	procProgram();
	matchToken(TKN_END_OF_FILE);
    return 0;
}

void SyntaticAnalysis::matchToken(enum TokenType type) {
    printf("Match token: %s -> %s (\"%s\")\n", tt2str(m_current.type).c_str(), tt2str(type).c_str(), m_current.token.c_str());
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
            printf("Lexema invalido [%s]\n", m_current.token.c_str());
            break;
        case TKN_UNEXPECTED_EOF:
        case TKN_END_OF_FILE:
            printf("Fim de arquivo inesperado\n");
            break;
        default:
            printf("Lexema nao esperado [%s]\n", m_current.token.c_str());
            break;
    }

    exit(1);
}

// <program>  ::= program <id> ';'
//                [ const <const> { <const> } ]
//                [ var <var> { <var> } ]
//                <block> '.'
void SyntaticAnalysis::procProgram() {
	matchToken(TKN_PROGRAM);
	procId();
	matchToken(TKN_SEMICOLON);
	if (m_current.type == TKN_CONST) {
		matchToken(TKN_CONST);
		procConst();
		while (m_current.type == TKN_ID)
			procConst();
	}
	if (m_current.type == TKN_VAR) {
		matchToken(TKN_VAR);
		procVar();
		while (m_current.type == TKN_ID)
			procVar();
	}
	procBlock();
	matchToken(TKN_DOT);
}

// <const>    ::= <id> = <value> ';'
void SyntaticAnalysis::procConst() {
	procId();
	matchToken(TKN_EQUAL);
	procValue();
	matchToken(TKN_SEMICOLON);
}

// <var>      ::= <id> { ',' <id> } [ = <value> ] ';'
void SyntaticAnalysis::procVar() {
	procId();
	while (m_current.type == TKN_COMMA) {
		matchToken(TKN_COMMA);
		procId();
	}
	if (m_current.type == TKN_EQUAL) {
		matchToken(TKN_EQUAL);
		procValue();
	}
	matchToken(TKN_SEMICOLON);
}

// <block>    ::= begin [ <cmd> { ';' <cmd> } ] end
void SyntaticAnalysis::procBlock() {
	matchToken(TKN_BEGIN);
	if (m_current.type == TKN_ID || m_current.type == TKN_IF || m_current.type == TKN_CASE ||
		m_current.type == TKN_WHILE || m_current.type == TKN_FOR || m_current.type == TKN_REPEAT ||
		m_current.type == TKN_WRITE || m_current.type == TKN_WRITELN || m_current.type == TKN_READLN) {
		procCmd();
		while (m_current.type == TKN_SEMICOLON) {
			matchToken(TKN_SEMICOLON);
			procCmd();
		}
	}
	matchToken(TKN_END);
}

// <body>     ::= <block> | <cmd>
void SyntaticAnalysis::procBody() {
	if (m_current.type == TKN_BEGIN)
		procBlock();
	else if (m_current.type == TKN_ID || m_current.type == TKN_IF || m_current.type == TKN_CASE ||
			 m_current.type == TKN_WHILE || m_current.type == TKN_FOR || m_current.type == TKN_REPEAT ||
			 m_current.type == TKN_WRITE || m_current.type == TKN_WRITELN || m_current.type == TKN_READLN)
		procCmd();
	else
		showError();
}

// <cmd>      ::= <assign> | <if> | <case> | <while> | <for> | <repeat> | <write> | <read>
void SyntaticAnalysis::procCmd() {
	if (m_current.type == TKN_ID)
		procAssign();
	else if (m_current.type == TKN_IF)
		procIf();
	else if (m_current.type == TKN_CASE)
		procCase();
	else if (m_current.type == TKN_WHILE)
		procWhile();
	else if (m_current.type == TKN_FOR)
		procFor();
	else if (m_current.type == TKN_REPEAT)
		procRepeat();
	else if (m_current.type == TKN_WRITE || m_current.type == TKN_WRITELN)
		procWrite();
	else if (m_current.type == TKN_READLN)
		procRead();
}

// <assign>   ::= <id> := <expr>
void SyntaticAnalysis::procAssign() {
	procId();
	matchToken(TKN_ASSIGN);
	procExpr();
}

// <if>       ::= if <boolexpr> then <body> [else <body>]
void SyntaticAnalysis::procIf() {
	matchToken(TKN_IF);
	procBoolExpr();
	matchToken(TKN_THEN);
	procBody();
	if (m_current.type == TKN_ELSE) {
		matchToken(TKN_ELSE);
		procBody();
	}
}

// <case>     ::= case <expr> of { <value> : <body> ';' } [ else <body> ';' ] end
void SyntaticAnalysis::procCase() {
	matchToken(TKN_CASE);
	procExpr();
	matchToken(TKN_OF);
	while (m_current.type == TKN_INTEGER || m_current.type == TKN_REAL || m_current.type == TKN_STRING) {
		procValue();
		matchToken(TKN_COLON);
		procBody();
		matchToken(TKN_SEMICOLON);
	}
	if (m_current.type == TKN_ELSE) {
		matchToken(TKN_ELSE);
		procBody();
		matchToken(TKN_COMMA);
	}
	matchToken(TKN_AND);
}

// <while>    ::= while <boolexpr> do <body>
void SyntaticAnalysis::procWhile() {
	matchToken(TKN_WHILE);
	procBoolExpr();
	matchToken(TKN_DO);
	procBody();
}

// <repeat>   ::= repeat [ <cmd> { ';' <cmd> } ] until <boolexpr>
void SyntaticAnalysis::procRepeat() {
	matchToken(TKN_REPEAT);
	if (m_current.type == TKN_ID || m_current.type == TKN_IF || m_current.type == TKN_CASE ||
		m_current.type == TKN_WHILE || m_current.type == TKN_FOR || m_current.type == TKN_REPEAT ||
		m_current.type == TKN_WRITE || m_current.type == TKN_WRITELN || m_current.type == TKN_READLN) {
		procCmd();
		while (m_current.type == TKN_SEMICOLON) {
			matchToken(TKN_SEMICOLON);
			procCmd();
		}
	}
	matchToken(TKN_UNTIL);
	procBoolExpr();
}

// <for>      ::= for <id> := <expr> to <expr> do <body>
void SyntaticAnalysis::procFor() {
	matchToken(TKN_FOR);
	procId();
	matchToken(TKN_ASSIGN);
	procExpr();
	matchToken(TKN_TO);
	procExpr();
	matchToken(TKN_DO);
	procBody();
}

// <write>    ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
void SyntaticAnalysis::procWrite() {
	if (m_current.type == TKN_WRITE)
		matchToken(TKN_WRITE);
	else if (m_current.type == TKN_WRITELN)
		matchToken(TKN_WRITELN);
	else
		showError();
	matchToken(TKN_OPEN_PAR);
	if (m_current.type == TKN_INTEGER || m_current.type == TKN_REAL ||
		m_current.type == TKN_STRING || m_current.type == TKN_ID ||
		m_current.type == TKN_OPEN_PAR) {
		procExpr();
		while (m_current.type == TKN_COMMA) {
			matchToken(TKN_COMMA);
			procExpr();
		}
	}
	matchToken(TKN_CLOSE_PAR);
}

// <read>     ::= readln '(' <id> { ',' <id> } ')'
void SyntaticAnalysis::procRead() {
	matchToken(TKN_READLN);
	matchToken(TKN_OPEN_PAR);
	procId();
	while (m_current.type == TKN_COMMA) {
		matchToken(TKN_COMMA);
		procId();
	}
	matchToken(TKN_CLOSE_PAR);
}

// <boolexpr> ::= [ not ] <cmpexpr> { (and | or) <boolexpr> }
void SyntaticAnalysis::procBoolExpr() {
	if (m_current.type == TKN_NOT)
		matchToken(TKN_NOT);
	procCmpExpr();
	while (m_current.type == TKN_AND || m_current.type == TKN_OR) {
		if (m_current.type == TKN_AND)
			matchToken(TKN_AND);
		else if (m_current.type == TKN_OR)
			matchToken(TKN_OR);
		else
			showError();
		procBoolExpr();
	}
}

// <cmpexpr>  ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr> | '(' <boolexpr> ')'
void SyntaticAnalysis::procCmpExpr() {
	if (m_current.type == TKN_OPEN_PAR) {
		matchToken(TKN_OPEN_PAR);
		procBoolExpr();
		matchToken(TKN_CLOSE_PAR);
	} else if (m_current.type == TKN_INTEGER || m_current.type == TKN_REAL ||
		m_current.type == TKN_STRING || m_current.type == TKN_ID ||
		m_current.type == TKN_OPEN_PAR) {
		procExpr();
		switch (m_current.type) {
			case TKN_EQUAL:
				matchToken(TKN_EQUAL);
				break;
			case TKN_NOT_EQUAL:
				matchToken(TKN_NOT_EQUAL);
				break;
			case TKN_LOWER:
				matchToken(TKN_LOWER);
				break;
			case TKN_GREATER:
				matchToken(TKN_GREATER);
				break;
			case TKN_LOWER_EQ:
				matchToken(TKN_LOWER_EQ);
				break;
			case TKN_GREATER_EQ:
				matchToken(TKN_GREATER_EQ);
				break;
			default:
				showError();
		}
		procExpr();
	} else
		showError();
}

// <expr>     ::= <term> { ('+' | '-') <term> }
void SyntaticAnalysis::procExpr() {
	procTerm();
	while (m_current.type == TKN_ADD || m_current.type == TKN_SUB) {
		if (m_current.type == TKN_ADD)
			matchToken(TKN_ADD);
		else if (m_current.type == TKN_SUB)
			matchToken(TKN_SUB);
		else
			showError();
		procTerm();
	}
}

// <term>     ::= <factor> { ('*' | '/' | '%') <factor> }
void SyntaticAnalysis::procTerm() {
	procFactor();
	while (m_current.type == TKN_MUL || m_current.type == TKN_DIV || m_current.type == TKN_MOD) {
		if (m_current.type == TKN_MUL)
			matchToken(TKN_MUL);
		else if (m_current.type == TKN_DIV)
			matchToken(TKN_DIV);
		else if (m_current.type == TKN_MOD)
			matchToken(TKN_MOD);
		else
			showError();
		procFactor();
	}
}

// <factor>   ::= <value> | <id> | '(' <expr> ')'
void SyntaticAnalysis::procFactor() {
	if (m_current.type == TKN_INTEGER || m_current.type == TKN_REAL || m_current.type == TKN_STRING)
		procValue();
	else if (m_current.type == TKN_ID)
		procId();
	else if (m_current.type == TKN_OPEN_PAR) {
		matchToken(TKN_OPEN_PAR);
		procExpr();
		matchToken(TKN_CLOSE_PAR);
	} else
		showError();
}

// <value>    ::= <integer> | <real> | <string>
void SyntaticAnalysis::procValue() {
	if (m_current.type == TKN_INTEGER)
		procInteger();
	else if (m_current.type == TKN_REAL)
		procReal();
	else if (m_current.type == TKN_STRING)
		procString();
	else
		showError();
}

void SyntaticAnalysis::procId() {
	matchToken(TKN_ID);
}

void SyntaticAnalysis::procInteger() {
	matchToken(TKN_INTEGER);
}

void SyntaticAnalysis::procReal() {
	matchToken(TKN_REAL);
}

void SyntaticAnalysis::procString() {
	matchToken(TKN_STRING);
}
