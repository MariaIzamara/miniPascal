#include "Variable.h"

Variable::Variable(int line, const std::string& name) : Expr(line), m_name(name) {
}

Variable::~Variable() {
}

Type* Variable::expr() {
	return Memory::read(m_name);
}

void Variable::setValue(Type* value) {
	Memory::write(m_name, value);
}

const std::string& Variable::name(){
	return m_name;
}
