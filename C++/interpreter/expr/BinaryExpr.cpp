#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(int line, Expr* left, BinaryOp* op, Expr* right)
	: Expr(line), m_left(left), m_op(op), m_right(right) {
}

BinaryExpr::~BinaryExpr() {
	delete m_left;
	delete m_right;
}

Type* BinaryExpr::expr() {
	Type* type_left = m_left -> expr();
	Type* type_right = m_right -> expr();

	int var_left = ((IntegerValue*)type_left)->value(),
		var_right = ((IntegerValue*)type_right)->value();

	switch(*BinaryExpr::m_op) {
		case BinaryOp::AddOp:
			return new IntegerValue(var_left+var_right);
			break;
		case BinaryOp::SubOp:
			return new IntegerValue(var_left-var_right);
			break;
		case BinaryOp::MulOp:
			return new IntegerValue(var_left*var_right);
			break;
		case BinaryOp::DivOp:
			return new IntegerValue(var_left/var_right);
			break;
		case BinaryOp::ModOp:
			return new IntegerValue(var_left%var_right);
			break;
		default:
			return NULL;
	}
}
