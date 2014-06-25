# Parametros 
CC = g++
CFLAGS = 
LIBS = 
EXE = teste
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
INC = $(wildcard *.h)

# Comandos
%.o: %.cpp 
	$(CC) -c $(CFLAGS) $< -o $@ 

all:teste clean

teste:$(OBJ)
	$(CC) -o $(EXE) $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o

uninstall:
	rm -f $(EXE)
