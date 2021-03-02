#include <cstdlib>
#include "SyntaticAnalysis.h"

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
	Variable* var = procId();
	matchToken(TKN_EQUAL);
	Type* value = procValue();
	Memory::registryConstant(var->getName(), value);
	matchToken(TKN_SEMICOLON);
}

// <var>      ::= <id> { ',' <id> } [ = <value> ] ';'
void SyntaticAnalysis::procVar() {
	Variable* var = procId();
	while (m_current.type == TKN_COMMA) {
		matchToken(TKN_COMMA);
		Variable* var = procId();
	}
	if (m_current.type == TKN_EQUAL) {
		matchToken(TKN_EQUAL);
		Type* value = procValue();
	}
	matchToken(TKN_SEMICOLON);
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
	else
		showError();
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
	int line = m_lex.line();
	matchToken(TKN_FOR);
	Variable* var = procId();
	Memory::registryVariable(var->getName(), new IntegerValue(0));
	matchToken(TKN_ASSIGN);
	Expr* src = procExpr();
	matchToken(TKN_TO);
	Expr* dst = procExpr();
	matchToken(TKN_DO);
	Command* cmd = procBody();
	return new ForCommand(line, var, src, dst, cmd);
}

// <write>    ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
WriteCommand* SyntaticAnalysis::procWrite() {
	int line = m_lex.line();
	WriteCommand* writec = new WriteCommand(line, false);
	if (m_current.type == TKN_WRITE)
		matchToken(TKN_WRITE);
	else if (m_current.type == TKN_WRITELN)
		matchToken(TKN_WRITELN);
		writec = new WriteCommand(line, true);
	else
		showError();
	matchToken(TKN_OPEN_PAR);
	if (m_current.type == TKN_INTEGER || m_current.type == TKN_REAL ||
		m_current.type == TKN_STRING || m_current.type == TKN_ID ||
		m_current.type == TKN_OPEN_PAR) {

		writec->addExpr(procExpr());
		while (m_current.type == TKN_COMMA) {
			matchToken(TKN_COMMA);
			writec->addExpr(procExpr());
		}
	}
	matchToken(TKN_CLOSE_PAR);
	return writec;
}

// <read>     ::= readln '(' <id> { ',' <id> } ')'
void SyntaticAnalysis::procRead() {
	int line = m_lex.line();
	ReadCommand* readC = new ReadCommand(line);
	matchToken(TKN_READLN);
	matchToken(TKN_OPEN_PAR);
	Variable* var = procId();
	readC->addVariable(var);
	while (m_current.type == TKN_COMMA) {
		matchToken(TKN_COMMA);
		var = procId();
		readC->addVariable(var);
	}
	matchToken(TKN_CLOSE_PAR);
	return readC;
}

// <boolexpr> ::= [ not ] <cmpexpr> [ (and | or) <boolexpr> ]
void SyntaticAnalysis::procBoolExpr() {
	int line = m_lex.line();
	bool falseBoolEx = false;
	if (m_current.type == TKN_NOT)
	    falseBoolEx = true;
		matchToken(TKN_NOT);
	BoolExpr* left = procCmpExpr();
	if (m_current.type == TKN_AND || m_current.type == TKN_OR) {
		enum CompositeBoolExpr:: BoolOp op;
		if (m_current.type == TKN_AND){
			op = CompositeBoolExpr::And;
			matchToken(TKN_AND);
		}else if (m_current.type == TKN_OR){
			op = CompositeBoolExpr::Or;
			matchToken(TKN_OR);
		}else
			showError();

		BoolExpr* right = procBoolExpr();
		left = new CompositeBoolExpr(line, left, op, right);
	}

	if(falseBoolEx)
		return new NotBoolExpr(line, left);
	else
		return left;
}

// <cmpexpr>  ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr>
void SyntaticAnalysis::procCmpExpr() {
	int line = m_lex.line();
	Expr* left = procExpr();
	enum SingleBoolExpr::Op op;
	if (m_current.type == TKN_EQUAL){
		op = SingleBoolExpr::EQUAL;
		matchToken(TKN_EQUAL);
	}else if (m_current.type == TKN_NOT_EQUAL){
		op = SingleBoolExpr::NOT_EQUAL;
		matchToken(TKN_NOT_EQUAL);
	}else if (m_current.type == TKN_LOWER){
		op = SingleBoolExpr::LOWER_THAN;
		matchToken(TKN_LOWER);
	}else if (m_current.type == TKN_GREATER){
		op = SingleBoolExpr::GREATER_THAN;
		matchToken(TKN_GREATER);
	}else if (m_current.type == TKN_LOWER_EQ){
		op = SingleBoolExpr::LOWER_EQUAL;
		matchToken(TKN_LOWER_EQ);
	}else if (m_current.type == TKN_GREATER_EQ){
		op = SingleBoolExpr::GREATER_EQUAL;
		matchToken(TKN_GREATER_EQ);
	}else
		showError();
	Expr* right = procExpr();
	return new SingleBoolExpr(line, left, op, right);
}

// <expr>     ::= <term> { ('+' | '-') <term> }
void SyntaticAnalysis::procExpr() {
	int line = m_lex.line();
	Expr* left = procTerm();
	while (m_current.type == TKN_ADD || m_current.type == TKN_SUB) {
		if (m_current.type == TKN_ADD){
			op = BinaryExpr::AddOp;
			matchToken(TKN_ADD);
		}else if (m_current.type == TKN_SUB){
			op = BinaryExpr::SubOp;
			matchToken(TKN_SUB);
		}else
			showError();
		Expr* right = procTerm();
		left = new BinaryExpr(line, left, op, right);
	}
	return left;
}

// <term>     ::= <factor> { ('*' | '/' | '%') <factor> }
void SyntaticAnalysis::procTerm() {
	int line = m_lex.line();
	enum BinaryExpr::BinaryOp op;
	Expr* left = procFactor();
	while (m_current.type == TKN_MUL || m_current.type == TKN_DIV || m_current.type == TKN_MOD) {
		if (m_current.type == TKN_MUL){
			op = BinaryExpr::MulOp;
			matchToken(TKN_MUL);
		}else if (m_current.type == TKN_DIV){
			op = BinaryExpr::DivOp;
			matchToken(TKN_DIV);
		}else if (m_current.type == TKN_MOD){
			op = BinaryExpr::ModOp;
			matchToken(TKN_MOD);
		}else
			showError();

		Expr* right = procFactor();
		left = new BinaryExpr(line, left, op, right);
	}
	return left;
}

// <factor>   ::= <value> | <id> | '(' <expr> ')'
void SyntaticAnalysis::procFactor() {
	if (m_current.type == TKN_INTEGER || m_current.type == TKN_REAL || m_current.type == TKN_STRING){
		int line = m_lex.line();
		Type* value = procValue();
		ConstExpr* constEx = new ConstExpr(line, value);
		return constEx;
	}else if (m_current.type == TKN_ID){
		return procId();
	}else if (m_current.type == TKN_OPEN_PAR) {
		matchToken(TKN_OPEN_PAR);

		return procExpr();

		matchToken(TKN_CLOSE_PAR);
	} else
		showError();

	return NULL;
}

// <value>    ::= <integer> | <real> | <string>
void SyntaticAnalysis::procValue() {
	if (m_current.type == TKN_INTEGER){
		return procInteger();
	}else if (m_current.type == TKN_REAL){
		return procReal();
	}else if (m_current.type == TKN_STRING){
		return procString();
	}else
		return showError();
	return NULL;
}

void SyntaticAnalysis::procId() {
	std::string name = m_current.token;
	matchToken(TKN_ID);
	int line = m_lex.line();
	Variable* var = new Variable(line, name);
	return var;
}

void SyntaticAnalysis::procInteger() {
	std::string tmp = m_current.token;
	matchToken(TKN_INTEGER);
	int value = atoi(tmp.c_str());
	IntegerValue* integerV = new IntegerValue(value);
	return integerV;
}

void SyntaticAnalysis::procReal() {
	std::string tmp = m_current.token;
	matchToken(TKN_REAL);
	float value = std::stof(tmp);
	RealValue* realV = new RealValue(value);
	return realV;
}

void SyntaticAnalysis::procString() {
	std::string tmp = m_current.token;
	tmp = tmp.substr(1, tmp.length()-2);
	matchToken(TKN_STRING);
	StringValue* stringV = new StringValue(tmp);
	return stringV;
}
