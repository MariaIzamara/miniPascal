#include "./CaseCommand.h"

CaseCommand::CaseCommand(int line, Expr* expr)
  : Command(line), m_expr(expr), m_otherwise(NULL) {
}

CaseCommand::~CaseCommand() {
  for(CaseOption* opt:m_options) delete opt;
  delete m_expr;
}

void CaseCommand::addOption(Type* value, Command* cmd) {
  CaseOption* c = new CaseOption(value, cmd);
  m_options.push_back(c);
}

void CaseCommand::setOtherwise(Command* cmd) {
  m_otherwise = cmd;
}

void CaseCommand::execute() {
  bool dontFind = true;

  for(CaseOption* opt:m_options){
    if(m_expr->expr() == opt->m_value){
      opt->m_cmd->execute();
      dontFind = false;
      break;
    }
  }

  if(dontFind) m_otherwise->execute();
}
