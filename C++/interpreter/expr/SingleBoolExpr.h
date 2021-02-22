#ifndef SINGLE_BOOL_EXPR_H
#define SINGLE_BOOL_EXPR_H

#include "BoolExpr.h"
#include "Expr.h"
#include "RelOp.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include "../value/StringValue.h"

class SingleBoolExpr : public BoolExpr {
	public:
		SingleBoolExpr(int line, Expr* left, RelOp* op, Expr* right);
		virtual ~SingleBoolExpr();
		int line();
		bool expr();

	private:
		Expr* m_left;
		RelOp* m_op;
		Expr* m_right;
};

#endif
