#include "Memory.h"

void Memory::registryVariable(const std::string& name, Type* value) {
	write(name, value);
}

void Memory::registryConstant(const std::string& name, Type* value) {
	write(name, value);
	m_consts.insert(name);
}

Type* Memory::read(const std::string& name) {
	return m_memory[name];
}

void Memory::write(const std::string& name, Type* value) {
	if(m_consts.find(name) == Memory::m_consts.end())
		m_memory[name] = value;
	else
		printf("Operação de sobrescrita impossível");
}


