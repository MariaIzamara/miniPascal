#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <string>

enum TokenType {
    // SPECIALS
    TKN_UNEXPECTED_EOF = -2,
    TKN_INVALID_TOKEN = -1,
    TKN_END_OF_FILE = 0,

    // SYMBOLS
    TKN_DOT,           // .
    TKN_COMMA,         // ,
    TKN_COLON,         // :
    TKN_SEMICOLON,     // ;
    TKN_OPEN_PAR,      // (
    TKN_CLOSE_PAR,     // )

    // OPERATORS
    TKN_ASSIGN,        // :=
    TKN_EQUAL,         // =
    TKN_NOT_EQUAL,     // <>
    TKN_LOWER,         // <
    TKN_GREATER,       // >
    TKN_LOWER_EQ,      // <=
    TKN_GREATER_EQ,    // >=
    TKN_ADD,           // +
    TKN_SUB,           // -
    TKN_MUL,           // *
    TKN_DIV,           // /
    TKN_MOD,           // %

    // KEYWORDS
    TKN_PROGRAM,       // program
    TKN_CONST,         // const
    TKN_VAR,           // var
    TKN_BEGIN,         // begin
    TKN_END,           // end
    TKN_IF,            // if
    TKN_THEN,          // then
    TKN_ELSE,          // else
    TKN_CASE,          // case
    TKN_OF,            // of
    TKN_WHILE,         // while
    TKN_DO,            // do
    TKN_REPEAT,        // repeat
    TKN_UNTIL,         // until
    TKN_FOR,           // for
    TKN_TO,            // to
    TKN_WRITE,         // write
    TKN_WRITELN,       // writeln
    TKN_READLN,        // readln
    TKN_NOT,           // not
    TKN_AND,           // and
    TKN_OR,            // or

    // OTHERS
    TKN_ID,            // identifier
    TKN_INTEGER,       // integer
    TKN_REAL,          // real
    TKN_STRING,        // string
};

inline std::string tt2str(enum TokenType type) {
	switch (type) {
		// SPECIALS
		case TKN_UNEXPECTED_EOF:
			return "UNEXPECTED_EOF";
		case TKN_INVALID_TOKEN:
			return "INVALID_TOKEN";
		case TKN_END_OF_FILE:
			return "END_OF_FILE";

		// SYMBOLS
		case TKN_DOT:
			return "DOT";
		case TKN_COMMA:
			return "COMMA";
		case TKN_COLON:
			return "COLON";
		case TKN_SEMICOLON:
			return "SEMICOLON";
		case TKN_OPEN_PAR:
			return "OPEN_PAR";
		case TKN_CLOSE_PAR:
			return "CLOSE_PAR";

		// OPERATORS
		case TKN_ASSIGN:
			return "ASSIGN";
		case TKN_EQUAL:
			return "EQUAL";
		case TKN_NOT_EQUAL:
			return "NOT_EQUAL";
		case TKN_LOWER:
			return "LOWER";
		case TKN_GREATER:
			return "GREATER";
		case TKN_LOWER_EQ:
			return "LOWER_EQ";
		case TKN_GREATER_EQ:
			return "GREATER_EQ";
		case TKN_ADD:
			return "ADD";
		case TKN_SUB:
			return "SUB";
		case TKN_MUL:
			return "MUL";
		case TKN_DIV:
			return "DIV";
		case TKN_MOD:
			return "MOD";

		// KEYWORDS
		case TKN_PROGRAM:
			return "PROGRAM";
		case TKN_CONST:
			return "CONST";
		case TKN_VAR:
			return "VAR";
		case TKN_BEGIN:
			return "BEGIN";
		case TKN_END:
			return "END";
		case TKN_IF:
			return "IF";
		case TKN_THEN:
			return "THEN";
		case TKN_ELSE:
			return "ELSE";
		case TKN_CASE:
			return "CASE";
		case TKN_OF:
			return "OF";
		case TKN_WHILE:
			return "WHILE";
		case TKN_DO:
			return "DO";
		case TKN_REPEAT:
			return "REPEAT";
		case TKN_UNTIL:
			return "UNTIL";
		case TKN_FOR:
			return "FOR";
		case TKN_TO:
			return "TO";
		case TKN_WRITE:
			return "WRITE";
		case TKN_WRITELN:
			return "WRITELN";
		case TKN_READLN:
			return "READLN";
		case TKN_NOT:
			return "NOT";
		case TKN_AND:
			return "AND";
		case TKN_OR:
			return "OR";

		// OTHERS
		case TKN_ID:
			return "ID";
		case TKN_INTEGER:
			return "INTEGER";
		case TKN_REAL:
			return "REAL";
		case TKN_STRING:
			return "STRING";

		default:
			throw std::string("invalid token type");
	}
};

#endif
