#include "ForCommand.h"

ForCommand::ForCommand(int line, Variable* var, Expr* src, Expr* dst, Command* cmd )
	: Command(line), m_var(var), m_dst(dst), m_src(src), m_cmd(cmd) {
}

ForCommand::~ForCommand() {
	delete m_dst;
	delete m_var;
	delete m_cmd;
	delete m_src;
}

void ForCommand::execute() {
	m_var->setValue(m_src->expr());

	for(int aux = (IntegerValue* m_src->expr()->value())+1, int aux0 = IntegerValue* m_dst->expr()->value(); aux < aux0; aux++){
		m_cmd->execute();
		m_var->setValue(new IntegerValue(aux));
	}

}
