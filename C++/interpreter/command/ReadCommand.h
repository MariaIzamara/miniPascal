#ifndef READ_COMMAND_H
#define READ_COMMAND_H

#include <list>
#include <stdio.h>
#include "Command.h"
#include "../expr/Variable.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include "../value/StringValue.h"

class ReadCommand : public Command {
    public:
		ReadCommand(int line);
		virtual ~ReadCommand();
        void addVariable(Variable* var);
		void execute();

	private:
		std::List<Variable*> m_vars;
};

#endif
