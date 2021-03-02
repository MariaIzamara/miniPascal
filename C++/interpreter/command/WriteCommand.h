#ifndef WRITE_COMMAND_H
#define WRITE_COMMAND_H

#include <list>
#include "Command.h"
#include "../expr/Expr.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include "../value/StringValue.h"

class WriteCommand : public Command {
    public:
		WriteCommand(int line, bool writeln = false);
		virtual ~WriteCommand();
        void addExpr(Expr* expr);
		void execute();

    private:
		bool m_writeln;
    	std::List<Expr*> m_exprs;
};

#endif
