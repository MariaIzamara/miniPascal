#include <iostream.h>
#include "WriteCommand.h"


WriteCommand::WriteCommand(int line, bool writeln): Command(line), writeln(writeln) {}

WriteCommand::~WriteCommand(){}

void WriteCommand::addExpr(Expr* expr){
	exprs.push_back(expr);
}

void WriteCommand::execute(){
	if (writeln){
		for(std::List<Expr*>::iterator i = exprs.begin(), e = exprs.end(); i != e; i++){
			Expr* ex = *i;
			Type *ty = ex->expr();

			if(ty->type() == Type::IntegerType){
				IntegerValue* IntV = (IntegerValue *)ty;
				std::cout << (IntV->value()) << std::endl;
			}
			else if(ty->type() == Type::RealType){
				RealValue* ReaV = (RealValue *)ty;
				std::cout << (ReaV->value()) << std::endl;
			}
			else{
				StringValue* StrV = (StringValue *)ty;
				std::cout << (StrV->value()) << std::endL;
			}
		}
	}
	else{
		for(std::List<Expr*>::iterator i = exprs.begin(), e = exprs.end(); i != e; i++){
			Expr *ex = *i;
			Type *ty = ex->expr();

			if(ty->type() == Type::IntegerType){
				IntegerValue* IntV = (IntegerValue *)ty;
				std::cout << (IntV->value()) << std::endl;
			}
			else if(ty->type() == Type::RealType){
				RealValue* ReaV = (RealValue *)ty;
				std::cout << (ReaV->value()) << std::endl;
			}
			else{
				StringValue* StrV = (StringValue *)ty;
				std::cout << (StrV->value()) << std::endl;
			}


		}
	}





}
