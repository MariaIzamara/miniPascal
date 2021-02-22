#include "BlocksCommand.h"

BlocksCommand::BlocksCommand(int line)
	: Command(line) {
}

BlocksCommand::~BlocksCommand() {
	for (std::list<Command*>::iterator i = m_cmds.begin(), e = m_cmds.end(); i != e; i++) {
		Command* cmd = *i;
		delete cmd;
	}
}

void BlocksCommand::addCommand(Command* cmd) {
	m_cmds.push_back(cmd);
}

void BlocksCommand::execute() {
	for (std::list<Command*>::iterator i = m_cmds.begin(), e = m_cmds.end(); i != e; i++) {
		Command* cmd = *i;
		cmd->execute();
	}
}
