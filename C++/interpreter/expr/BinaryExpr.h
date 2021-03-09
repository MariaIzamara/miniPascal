#ifndef BINARY_EXPR_H
#define BINARY_EXPR_H

#include <iostream>
#include "Expr.h"
#include "BinaryOp.h"
#include "../value/Type.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include "../value/StringValue.h"

class BinaryExpr : public Expr {
	public:
		BinaryExpr(int line, Expr* left, BinaryOp* op, Expr* right);
		virtual ~BinaryExpr();
		Type* expr();

	private:
		Expr* m_left;
		BinaryOp* m_op;
		Expr* m_right;
};

#endif
