#include "SingleBoolExpr.h"

SingleBoolExpr::SingleBoolExpr(int line, Expr* left, enum SingleBoolExpr::Op RelOp, Expr* right)
	: BoolExpr(line), m_left(left), RelOp(RelOp), m_right(right) {
}

SingleBoolExpr::~SingleBoolExpr() {
	delete m_right;
	delete m_left;
}

int SingleBoolExpr::line(){
	return BoolExpr::line();
}

bool SingleBoolExpr::expr() {
	Type* type0 = m_left -> expr();
	Type* type1 = m_right -> expr();

	float var1= 0.0,
	      var2= 0.0;

	if(type0->type()==Type::IntegerType)
		var1=((IntegerValue*) type0) -> value();
	else if(type0->type()==Type::RealType)
		var1=((RealValue*) type0) -> value();

	if(type1->type()==Type::IntegerType)
		var2=((IntegerValue*) type1) -> value();
	else if(type1->type()==Type::RealType)
		var2=((RealValue*) type1) -> value();

	switch(RelOp){
		default:
			return NULL;
			break;
		case SingleBoolExpr::EQUAL:
			return var1 == var2;
			break;
		case SingleBoolExpr::NOT_EQUAL:
			return var1 != var2;
			break;
		case SingleBoolExpr::GREATER_EQUAL:
			return var1 >= var2;
			break;
		case SingleBoolExpr::GREATER_THAN:
			return var1 > var2;
			break;
		case SingleBoolExpr::LOWER_EQUAL:
			return var1 <= var2;
			break;
		case SingleBoolExpr::LOWER_THAN:
			return var1 < var2;
			break;



	}

}
