CXX=g++
CXXFLAGS=-g -ggdb -O2 -Wall

TARGET=mpasi

OBJS=mpasi.o \
	 lexical/SymbolTable.o \
	 lexical/LexicalAnalysis.o \
	 syntatic/SyntaticAnalysis.o \
	 interpreter/command/AssignCommand.o \
	 interpreter/command/BlocksCommand.o \
	 interpreter/command/WriteCommand.o \
	 interpreter/command/ReadCommand.o \
	 interpreter/command/IfCommand.o \
	 interpreter/command/RepeatCommand.o \
	 interpreter/command/WhileCommand.o \
	 interpreter/command/ForCommand.o \
	 interpreter/command/CaseCommand.o \
	 interpreter/expr/Variable.o \
	 interpreter/expr/ConstExpr.o \
	 interpreter/expr/NotBoolExpr.o \
	 interpreter/expr/SingleBoolExpr.o \
	 interpreter/expr/BinaryExpr.o \
	 interpreter/expr/CompositeBoolExpr.o \
	 interpreter/value/IntegerValue.o \
	 interpreter/value/RealValue.o \
	 interpreter/value/StringValue.o \
	 interpreter/util/Memory.o \

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

mpasi.o:

$(TARGET):  $(OBJS)
			$(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
