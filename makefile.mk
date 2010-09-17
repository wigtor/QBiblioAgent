
CXX=g++ -pg -g3
CXXFLAGS=-Wall -Wextra -Wshadow -pedantic -std=c++98 -pg -g3 -I./ -L./
SUFFIXES=cpp

CXX_FILES =						\
		nodo.cpp				\
		entero.cpp				\
		ListaEnlazada.cpp		\
		main.cpp

CXX_OBJECTS =				\
		nodo.o				\
		entero.o			\
		ListaEnlazada.o		\
		main.o

CXX_HEADERS =					\
		entero.h				\
		ListaEnlazada.h			\
		nodo.h

PROGRAM = QBiblioAgent

.SUFFIXES:		.cpp

.cpp.o: $(CXX_FILES) $(CXX_HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

QBiblioAgent:		$(CXX_OBJECTS)
	$(CXX) -o $(PROGRAM) -lm $(CXX_FILES)

clean:
	@rm -f *.o

all:	$(PROGRAM)
	@echo "done..."

