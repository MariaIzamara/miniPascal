#ifndef REPEAT_COMMAND_H
#define REPEAT_COMMAND_H

#include <list>
#include ".../expr/BoolExpr.h"
#include "Command.h"
class RepeatCommand:public Command {

    private :
		BoolExpr cond;
    	std::List<Command> exprs;

    public :
		RepeatCommand(int line, std::List<Command*> cmds, BoolExpr* cond);

        virtual ~RepeatCommand();
        virtual void execute();
}




