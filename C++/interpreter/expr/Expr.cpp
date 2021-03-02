#include "Expr.h"

Expr::Expr(int line) : m_line(line) {
}

Expr::~Expr() {
}

int Expr::line(){
	return m_line;
}

Type* Expr::expr() {
}
