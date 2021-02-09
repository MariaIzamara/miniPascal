#include "Variable.h"

Variable::Variable(int line, StringValue* name) : Expr(line), m_name(name) {
}

Variable::~Variable() {
}

Type* Variable::expr() {
}

void Variable::setValue(Type* value) {
	//
}

StringValue* Variable::name(){
	return m_name;
}
