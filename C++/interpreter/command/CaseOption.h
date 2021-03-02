#ifndef CASE_OPTION_COMMAND_H
#define CASE_OPTION_COMMAND_H

#include <list>
#include "Command.h"
#include "../value/Type.h"

class CaseOption {
  public:
    CaseOption(Type* value, Command* cmd);
    virtual ~CaseOption();
    Type* m_value;
    Command* m_cmd;
};

#endif
