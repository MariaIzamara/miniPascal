CXX=g++
CXXFLAGS=-g -ggdb -O2 -Wall

TARGET=mpasi

OBJS=mpasi.o \
	 lexical/SymbolTable.o \
	 lexical/LexicalAnalysis.o \
	 syntatic/SyntaticAnalysis.o \

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

mpasi.o:

lexical/SymbolTable.o: lexical/TokenType.h

lexical/LexicalAnalysis.o: lexical/TokenType.h lexical/SymbolTable.h

syntatic/SyntaticAnalysis.o: lexical/LexicalAnalysis.h

$(TARGET):  $(OBJS)
			$(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
