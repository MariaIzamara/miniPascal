#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(int line, Expr* left, BinaryOp* op, Expr* right)
	: Expr(line), m_left(left), m_op(op), m_right(right) {
}

BinaryExpr::~BinaryExpr() {
}

Type* BinaryExpr::expr() {
}
