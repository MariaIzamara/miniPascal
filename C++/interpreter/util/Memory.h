#ifndef MEMORY_H
#define MEMORY_H

#include <map>
#include <set>
#include <string>
#include "../value/Type.h"

class Memory {
	public:
		static void registryVariable(const std::string& name, Type* value = NULL);
		static void registryConstant(const std::string& name, Type* value);

		static Type* read(const std::string& name);
		static void write(const std::string& name, Type* value);

	private:
		static std::map<std::string, Type*> m_memory;
		static std::set<std::string> m_consts;
};

#endif
