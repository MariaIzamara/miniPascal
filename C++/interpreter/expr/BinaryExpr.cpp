#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(int line, Expr* left, enum BinaryExpr::BinaryOp op, Expr* right)
	: Expr(line), m_left(left), m_op(op), m_right(right) {
}

BinaryExpr::~BinaryExpr() {
	delete m_left;
	delete m_right;
}

Type* BinaryExpr::expr() {
	Type* type0 = m_right -> expr();
	Type* type1 = m_left -> expr();

	int var1 =((IntegerValue*)type0)->value(),
		var2 =((IntegerValue*)type1)->value();

		switch(m_op){
			default:
			return NULL;
			break;
			case BinaryOp::ModOp:
			return new IntegerValue(var1%var2);
			break;
			case BinaryOp::AddOp:
			return new IntegerValue(var1+var2);
			break;
			case BinaryOp::MulOp:
			return new IntegerValue(var1*var2);
			break;
			case BinaryOp::SubOp:
			return new IntegerValue(var1-var2);
			break;
			case BinaryOp::DivOp:
			return new IntegerValue(var1/var2);
			break;
		}
}
