#ifndef WRITE_COMMAND_H
#define WRITE_COMMAND_H

#include <list>
#include "Command.h"

public class WriteCommand extends Command {

    private bool writeln;
    private std::List<Expr> exprs;

    public WriteCommand(int line, bool writeln = false){

        public void addExpr(Expr expr);

        public void execute();
}
