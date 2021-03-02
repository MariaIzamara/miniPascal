#ifndef CASE_COMMAND_H
#define CASE_COMMAND_H

#include <list>
#include "Command.h"
#include "CaseOption.h"
#include "../expr/Expr.h"

class CaseCommand : public Command{
    public:
        CaseCommand(int line, Expr* expr);
        virtual ~CaseCommand();
        virtual void addOption(Type* value, Command* cmd);
        virtual void setOtherwise(Command* cmd);
        virtual void execute();

    private:
        Expr* m_expr;
        std::list<CaseOption*> m_options;
        Command* m_otherwise;
};

#endif
