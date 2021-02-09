#ifndef EXPR_H
#define EXPR_H

#include "../value/Type.h"

class Expr {
	public:
		virtual ~Expr();
		int line();
		Type* expr();

	protected:
		Expr(int line);

	private:
		int m_line;
};

#endif
