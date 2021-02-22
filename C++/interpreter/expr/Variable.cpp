#include "Variable.h"

Variable::Variable(int line, StringValue* name) : Expr(line), m_name(name) {
}

Variable::~Variable() {
}

Type* Variable::expr() {
	return Memory::read(name);
}

void Variable::setValue(Type* value) {
	Memory::write(name, value);
}

StringValue* Variable::name(){
	return m_name;
}
