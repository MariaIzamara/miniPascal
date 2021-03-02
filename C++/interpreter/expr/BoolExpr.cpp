#include "BoolExpr.h"

BoolExpr::BoolExpr(int line) : m_line(line) {
}

BoolExpr::~BoolExpr() {
}

int BoolExpr::line() {
	return m_line;
}

bool BoolExpr::expr() {
}
