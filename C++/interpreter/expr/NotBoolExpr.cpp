#include "NotBoolExpr.h"

NotBoolExpr::NotBoolExpr(int line, BoolExpr expr) : BoolExpr(line), m_expr(expr) {
}

NotBoolExpr::~NotBoolExpr() {
}

int NotBoolExpr::line() {
	return BoolExpr::line();
}

bool NotBoolExpr::expr() {
}
