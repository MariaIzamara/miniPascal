#ifndef MEMORY_H
#define MEMORY_H

#include "../value/Type.h"
#include "../value/StringValue.h"

class Memory {
	public:
		void registryVariable(StringValue name, Type* value = NULL);
		void registryConstant(StringValue name, Type* value);
		Type* read(StringValue name);
		void write(StringValue name, Type* value);

	private:
		// Map<String, Type*> memory;
		// Set<String> consts;
};

#endif
