#include "SingleBoolExpr.h"

SingleBoolExpr::SingleBoolExpr(int line, Expr* left, RelOp* op, Expr* right)
	: BoolExpr(line), m_left(left), m_op(op), m_right(right) {
}

SingleBoolExpr::~SingleBoolExpr() {
}

int SingleBoolExpr::line(){
	return BoolExpr::line();
}

bool SingleBoolExpr::expr() {
}
