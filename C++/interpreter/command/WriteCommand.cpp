#include "WriteCommand.h"

WriteCommand::WriteCommand(int line, bool writeln) : Command(line), m_writeln(writeln) {
}

WriteCommand::~WriteCommand(){
}

void WriteCommand::addExpr(Expr* expr){
	m_exprs.push_back(expr);
}

void WriteCommand::execute(){
	if(m_writeln) {
		for(std::list<Expr*>::iterator i = m_exprs.begin(), e = m_exprs.end(); i != e; i++) {
			Expr* ex = *i;
			Type *ty = ex->expr();

			if(ty->type() == Type::IntegerType) {
				IntegerValue* IntV = (IntegerValue *)ty;
				std::cout << (IntV->value()) << std::endl;
			} else if(ty->type() == Type::RealType) {
				RealValue* ReaV = (RealValue *)ty;
				std::cout << (ReaV->value()) << std::endl;
			} else {
				StringValue* StrV = (StringValue *)ty;
				std::cout << (StrV->value()) << std::endl;
			}
		}
	} else {
		for(std::list<Expr*>::iterator i = m_exprs.begin(), e = m_exprs.end(); i != e; i++) {
			Expr *ex = *i;
			Type *ty = ex->expr();

			if(ty->type() == Type::IntegerType) {
				IntegerValue* IntV = (IntegerValue *)ty;
				std::cout << (IntV->value()) << std::endl;
			} else if(ty->type() == Type::RealType) {
				RealValue* ReaV = (RealValue *)ty;
				std::cout << (ReaV->value()) << std::endl;
			} else {
				StringValue* StrV = (StringValue *)ty;
				std::cout << (StrV->value()) << std::endl;
			}
		}
	}
}
