#include "CompositeBoolExpr.h"

CompositeBoolExpr::CompositeBoolExpr(int line, BoolExpr* left, BoolOp* op, BoolExpr* right)
	: BoolExpr(line), m_left(left), m_op(op), m_right(right) {
}

CompositeBoolExpr::~CompositeBoolExpr() {
	delete m_left;
	delete m_op;
	delete m_right;
}

int CompositeBoolExpr::line(){
	return BoolExpr::line();
}

bool CompositeBoolExpr::expr() {
	bool var_left = m_left -> expr();
	bool var_right = m_right -> expr();

	switch(*CompositeBoolExpr::m_op) {
		case BoolOp::And:
			return var_left && var_right;
			break;
		case BoolOp::Or:
			return var_left || var_right;
			break;
		default:
			return NULL;
	}
}


