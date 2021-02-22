#include "ReadCommand.h"

ReadCommand::ReadCommand(int line):Command (line){};

ReadCommand::~ReadCommand(){

}

ReadCommand::addVariable(Variable* var){
	vars.push_back(var);
}

void ReadCommand::execute(){

	for(std::List<Variable*>:: iterator i = vars.begin(), e= vars.end(); i!=e; i++){
		Variable* var = *i;

		if(var->expr()->type()==Type::RealType){
			float val;
			std::cin >> val;
			RealValue* realV = new RealValue(val);
			var->setValue(realV);
		}
		else if(var->expr()->type()==Type::StringType){
			std::string val;
			std::cin >> val;
			StringValue* strV = new StringValue(val);
			var->setValue(strV);
		}
		//mesmo que nao tenha o valor, admite que é inteiro por padrão
		else
			int val;
			std::cin >> val;
			IntegerValue* intV = new IntegerValue(val);
			var->setValue(intV);
		}

	}






}
