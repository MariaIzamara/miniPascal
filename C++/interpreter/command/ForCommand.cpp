#include "ForCommand.h"

ForCommand::ForCommand(int line, Variable* var, Expr* src, Expr* dst, Command* cmd ):Command(line), var(var), dst(dst), src(src), cmd(cmd){}

ForCommand::~ForCommand(){
	delete dst;
	delete var;
	delete cmd;
	delete src;

}

void ForCommand::execute(){

	var->setValue(src->expr());

	for(int aux = (IntegerValue* src->expr()->value())+1, int aux0 = IntegerValue* dst->expr()->value(); aux < aux0; aux++){
		cmd->execute();
		var->setValue(new IntegerValue(aux));
	}

}
