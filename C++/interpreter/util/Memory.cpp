#include "Memory.h"

std::map<std::string, Type*> Memory::m_memory;
std::set<std::string>, Memory::consts;

int Memory::read(const std::string& name) {
	return Memory::m_memory[name];
}

void Memory::write(const std::string& name, Type* value) {
	if(consts.find(name)==Memory::consts.end())
		m_memory[name] = value;
	else
		printf("Operacao de sobrescrita impossivel");
}

void Memory::registryConstant(const std::string& name, Type* value){
	write(name, value);
	consts.insert(name);

}

void Memory:registryVariable(const std::string& name, Type* value){
	write(name, value);
}

