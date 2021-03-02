// Executar o bloco then se a expressão for verdadeira, caso contrário executar o bloco else se esse existir
#include "IfCommand.h"
#include "../expr/BoolExpr.h"

IfCommand::IfCommand(int line, BoolExpr* cond, Command* thenCmds, Command* elseCmds)
	: Command(line), m_cond(cond), m_thenCmds(thenCmds), m_elseCmds(elseCmds) {
}

IfCommand::~IfCommand() {
	delete m_cond;
}

void IfCommand::setElseCommands(Command* elseCmds){
  m_elseCmds = elseCmds;
};

void IfCommand::execute() {
	if (m_cond->expr())
		m_thenCmds->execute();
	else if (m_elseCmds)
		m_elseCmds->execute();
}
