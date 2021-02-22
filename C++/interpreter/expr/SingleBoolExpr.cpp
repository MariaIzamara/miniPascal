#include "SingleBoolExpr.h"

SingleBoolExpr::SingleBoolExpr(int line, Expr* left, RelOp* op, Expr* right)
	: BoolExpr(line), m_left(left), m_op(op), m_right(right) {
}

SingleBoolExpr::~SingleBoolExpr() {
	delete m_left;
	delete m_op;
	delete m_right;
}

int SingleBoolExpr::line(){
	return BoolExpr::line();
}

bool SingleBoolExpr::expr() {
	Type* type_left = m_left -> expr();
	Type* type_right = m_right -> expr();

	float var_left = 0, var_right = 0;

	if(type_left->type() == Type::IntegerType)
		var_left = ((IntegerValue*) type_left) -> value();
	else if(type_left->type() == Type::RealType)
		var_left = ((RealValue*) type_left) -> value();

	if(type_right->type() == Type::IntegerType)
		var_right = ((IntegerValue*) type_right) -> value();
	else if(type_right->type() == Type::RealType)
		var_right = ((RealValue*) type_right) -> value();

	switch(*SingleBoolExpr::m_op) {
		case RelOp::Equal:
			return var_left == var_right;
			break;
		case RelOp::NotEqual:
			return var_left != var_right;
			break;
		case RelOp::LowerThan:
			return var_left < var_right;
			break;
		case RelOp::LowerEqual:
			return var_left <= var_right;
			break;
		case RelOp::GreaterThan:
			return var_left > var_right;
			break;
		case RelOp::GreaterEqual:
			return var_left >= var_right;
			break;
		default:
			return NULL;
	}
}
