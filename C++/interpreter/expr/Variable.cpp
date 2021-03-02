#include "Variable.h"

Variable::Variable(int line, StringValue* name) : Expr(line), m_name(name) {
}

Variable::~Variable() {
}

Type* Variable::expr() {
	return Memory::read(m_name->value());
}

void Variable::setValue(Type* value) {
	Memory::write(m_name->value(), value);
}

StringValue* Variable::name(){
	return m_name;
}
