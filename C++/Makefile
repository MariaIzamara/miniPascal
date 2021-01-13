# o compilador
CXX=g++
# flags de compilação
CXXFLAGS=-g -ggdb -O2 -Wall
# alvo que vou gerar
TARGET=mpasi
# criar os objetos que vão formar o programa
OBJS=mpasi.o lexical/SymbolTable lexical/LexicalAnalysis

# regra all que vai compilar o alvo
all: $(TARGET)
# regra clean que vai apagar o alvo e os objetos
clean:
	rm -f $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

# compilar os programas:

# o programa encontra um cpp e gera esse .o
mpasi.o:

lexical/SymbolTable.o: lexical/TokenType.h

lexical/LexicalAnalysis.o: lexical/TokenType.h lexical/SymbolTable.h

$(TARGET):  $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# para todo programa .cpp, gera um .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
