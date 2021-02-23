#ifndef MEMORY_H
#define MEMORY_H

#include <map>
#include <set>
#include <string>
#include "../value/Type.h"
#include "../value/StringValue.h"

class Memory {
	public:
		static void registryVariable(StringValue* name, Type* value = NULL);
		static void registryConstant(StringValue* name, Type* value);

		static Type* read(StringValue* name);
		static void write(StringValue* name, Type* value);

	private:
		static std::map<StringValue*, Type*> m_memory;
		static std::set<StringValue*> m_consts;
};

#endif
