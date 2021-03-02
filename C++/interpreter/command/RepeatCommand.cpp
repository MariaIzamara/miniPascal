#include "RepeatCommand.h"

RepeatCommand::RepeatCommand(int line, std::List<Command*> cmds, BoolExpr* cond)
	: Command(line), m_cmds(cmds), m_cond(cond) {
}

RepeatCommand::~RepeatCommand() {
}

void RepeatCommand::execute(){
	do {
		for(std::List<Command*>::iterator i = m_cmds.begin(), e = m_cmds.end(); i!=e; i++){
			Command *m = i;
			m->execute();
		}
	} while(m_cond->expr());
}
