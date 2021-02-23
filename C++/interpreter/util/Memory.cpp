#include "Memory.h"

void Memory::registryVariable(StringValue* name, Type* value) {
	write(name, value);
}

void Memory::registryConstant(StringValue* name, Type* value) {
	write(name, value);
	m_consts.insert(name);
}

Type* Memory::read(StringValue* name) {
	return m_memory[name];
}

void Memory::write(StringValue* name, Type* value) {
	if(m_consts.find(name) == Memory::m_consts.end())
		m_memory[name] = value;
	else
		printf("Operação de sobrescrita impossível");
}


