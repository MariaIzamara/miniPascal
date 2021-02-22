#include "RepeatCommand.h"

RepeatCommand::RepeatCommand(int line, std::List<Command*> cmds, BoolExpr *cond): Command(line), cmds(cmds), cond(cond){};

RepeatCommand::~RepeatCommand(){}

void RepeatCommand::execute(){
	do{
		for(std::List<Command*>::iterator i = cmds.begin(), e = cmds.end(); i!=e; i++){
			Command *m = i;
			m->execute();
		}

	}while(cond->expr());
}
