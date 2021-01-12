package syntatic;

import java.io.IOException;
import java.util.Map;
import java.util.HashMap;

import lexical.Lexeme;
import lexical.TokenType;
import lexical.LexicalAnalysis;
import lexical.LexicalException;

import interpreter.command.Command;

public class SyntaticAnalysis {

    private LexicalAnalysis lex;
    private Lexeme current;

    public SyntaticAnalysis(LexicalAnalysis lex) throws LexicalException, IOException {
        this.lex = lex;
        this.current = lex.nextToken();
    }

    public Command start() throws LexicalException, IOException {
        return null;
    }

    private void matchToken(TokenType type) throws LexicalException, IOException {
        // System.out.println("Match token: " + current.type + " -> " + type +
        //     " (\"" + current.token + "\")");
        if (type == current.type) {
            current = lex.nextToken();
        } else {
            showError();
        }
    }

    private void showError() {
        System.out.printf("%02d: ", lex.getLine());

        switch (current.type) {
            case INVALID_TOKEN:
                System.out.printf("Lexema inválido [%s]\n", current.token);
                break;
            case UNEXPECTED_EOF:
            case END_OF_FILE:
                System.out.printf("Fim de arquivo inesperado\n");
                break;
            default:
                System.out.printf("Lexema não esperado [%s]\n", current.token);
                break;
        }

        System.exit(1);
    }

    // <program>  ::= program <id> ';'
    //                [ const <const> { <const> } ]
    //                [ var <var> { <var> } ]
    //                <block> '.'
    private void procProgram() throws LexicalException, IOException {
    }

    // <const>    ::= <id> = <value> ';'
    private void procConst() throws LexicalException, IOException {
    }

    // <var>      ::= <id> { ',' <id> } [ = <value> ] ';'
    private void procVar() throws LexicalException, IOException {
    }

    // <block>    ::= begin [ <cmd> { ';' <cmd> } ] end
    private void procBlock() throws LexicalException, IOException {
    }

    // <body>     ::= <block> | <cmd>
    private void procBody() throws LexicalException, IOException {
    }
    
    // <cmd>      ::= <assign> | <if> | <case> | <while> | <for> | <repeat> | <write> | <read>
    private void procCmd() throws LexicalException, IOException {
    }

    // <assign>   ::= <id> := <expr>
    private void procAssign() throws LexicalException, IOException {
    }

    // <if>       ::= if <boolexpr> then <body> [else <body>]
    private void procIf() throws LexicalException, IOException {
    }

    // <case>     ::= case <expr> of { <value> : <body> ';' } [ else <body> ';' ] end
    private void procCase() throws LexicalException, IOException {
    }

    // <while>    ::= while <boolexpr> do <body>
    private void procWhile() throws LexicalException, IOException {
    }

    // <repeat>   ::= repeat [ <cmd> { ';' <cmd> } ] until <boolexpr>
    private void procRepeat() throws LexicalException, IOException {
    }

    // <for>      ::= for <id> := <expr> to <expr> do <body>
    private void procFor() throws LexicalException, IOException {
    }

    // <write>    ::= (write | writeln) '(' [ <expr> { ',' <expr> } ] ')'
    private void procWrite() throws LexicalException, IOException {
    }

    // <read>     ::= readln '(' <id> { ',' <id> } ')'
    private void procRead() throws LexicalException, IOException {
    }
    
    // <boolexpr> ::= [ not ] <cmpexpr> { (and | or) <boolexpr> }
    private void procBoolExpr() throws LexicalException, IOException {
    }

    // <cmpexpr>  ::= <expr> ('=' | '<>' | '<' | '>' | '<=' | '>=') <expr> | '(' <boolexpr> ')'
    private void procCmpExpr() throws LexicalException, IOException {
    }

    // <expr>     ::= <term> { ('+' | '-') <term> }
    private void procExpr() throws LexicalException, IOException {
    }

    // <term>     ::= <factor> { ('*' | '/' | '%') <factor> }
    private void procTerm() throws LexicalException, IOException {
    }

    // <factor>   ::= <value> | <id> | '(' <expr> ')'
    private void procFactor() throws LexicalException, IOException {
    }

    // <value>    ::= <integer> | <real> | <string>
    private void procValue() throws LexicalException, IOException {
    }

    private void procId() throws LexicalException, IOException {
    }

    private void procInteger() throws LexicalException, IOException {
    }

    private void procReal() throws LexicalException, IOException {
    }

    private void procString() throws LexicalException, IOException {
    }

}
