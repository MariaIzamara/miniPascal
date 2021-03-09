#ifndef COMPOSITE_BOOL_EXPR_H
#define COMPOSITE_BOOL_EXPR_H

#include <iostream>
#include "BoolExpr.h"
#include "BoolOp.h"

class CompositeBoolExpr : public BoolExpr {
	public:
		CompositeBoolExpr(int line, BoolExpr* left, BoolOp* op, BoolExpr* right);
		virtual ~CompositeBoolExpr();
		int line();
		bool expr();

	private:
		BoolExpr* m_left;
		BoolOp* m_op;
		BoolExpr* m_right;
};

#endif
