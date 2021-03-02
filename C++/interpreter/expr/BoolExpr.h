#ifndef BOOL_EXPR_H
#define BOOL_EXPR_H

class BoolExpr {
	public:
		BoolExpr(int line);
		virtual ~BoolExpr();
		int line();
		bool expr();

	private:
		int m_line;
};

#endif
