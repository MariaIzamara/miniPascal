#ifndef FOR_COMMAND_H
#define FOR_COMMAND_H

#include "Command.h"
#include "../expr/Expr.h"
#include "../expr/Variable.h"
#include "../value/IntegerValue.h"

class ForCommand : public Command{
	public:
		ForCommand(int line, Variable* var, Expr* src, Expr* dst, Command* cmd);
		virtual ~ForCommand();
		virtual void execute();

	private:
		Variable* m_var;
		Expr* m_src;
		Expr* m_dst;
		Command* m_cmd;
};

#endif
