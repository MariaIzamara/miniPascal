#ifndef REPEAT_COMMAND_H
#define REPEAT_COMMAND_H

#include <list>
#include "Command.h"
#include "../expr/BoolExpr.h"

class RepeatCommand : public Command {
    public:
		RepeatCommand(int line, std::List<Command*> cmds, BoolExpr* cond);
        virtual ~RepeatCommand();
        virtual void execute();

    private:
		BoolExpr* m_cond;
    	std::List<Command*> m_cmds;
};

#endif
