#include "NotBoolExpr.h"

NotBoolExpr::NotBoolExpr(int line, BoolExpr* expr) : BoolExpr(line), m_expr(expr) {
}

NotBoolExpr::~NotBoolExpr() {
	delete m_expr;
}

int NotBoolExpr::line() {
	return BoolExpr::line();
}

bool NotBoolExpr::expr() {
	return !(m_expr->expr());
}
