#include "CompositeBoolExpr.h"

CompositeBoolExpr::CompositeBoolExpr(int line, BoolExpr* left, BoolOp* op, BoolExpr* right)
	: BoolExpr(line), m_left(left), m_op(op), m_right(right) {
}

CompositeBoolExpr::~CompositeBoolExpr() {
}

int CompositeBoolExpr::line(){
	return BoolExpr::line();
}

bool CompositeBoolExpr::expr() {
}


