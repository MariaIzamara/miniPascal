//Executar o bloco do corpo da repetição enquanto a expressão for verdadeira
#include "WhileCommand.h"
#include "../expr/BoolExpr.h"

WhileCommand::WhileCommand(int line, BoolExpr* cond, Command* cmds)
	: Command(line), m_cond(cond), m_cmds(cmds) {
}

WhileCommand::~WhileCommand() {
	delete m_cond;
}

void WhileCommand::execute() {
	while(m_cond->expr())
		m_cmds->execute();
}
