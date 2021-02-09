//Executar o bloco do corpo da repetição enquanto a expressão for verdadeira

#include<stdio.h>
#include<iostream.h>

public class WhileCommand extends Command {

    private BoolRxExpr cond;
    private Command cmds;

    public WhileCommand(int line, BoolExpr cond, Command cmds){
        super(line);        this.cond=cond;
        this.cmds=cmds;


    public void execute(){
        while(cond.expr())
            cmds.execute;
    }

}
