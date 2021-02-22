#ifndef FOR_COMMAND_H
#define FOR_COMMAND_H

#include ".../expr/Expr.h"
#include ".../expr/Variable.h"
#include ".../value/IntegerValue.h"
#include "Command.h"

class ForCommand:public Command{

	public:
		ForCommand(int line, Variable* var, Expr* src, Expr* dst, Command* cmd);

		virtual ~ForCommand();

		virtual void execute();

	private:
		Expr* src;
		Expr* dst;
		Command* cmd;
		Variable* var;

};

#endif
