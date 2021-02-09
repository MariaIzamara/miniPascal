#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expr.h"
#include "../value/StringValue.h"
#include "../value/Type.h"

class Variable : public Expr {
	public:
		Variable(int line, StringValue* name);
		virtual ~Variable();
		Type* expr();
		void setValue(Type* value);
		StringValue* name();

	private:
		StringValue* m_name;
};

#endif
