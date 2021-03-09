#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Expr.h"
#include "../util/Memory.h"
#include "../value/StringValue.h"
#include "../value/Type.h"

class Variable : public Expr {
	public:
		Variable(int line, const std::string& name);
		virtual ~Variable();
		Type* expr();
		void setValue(Type* value);
		const std::string& name();

	private:
		std::string m_name;
};

#endif
