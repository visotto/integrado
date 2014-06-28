CC = g++
EXE = teste

all: $(EXE) clean

$(EXE):
	$(CC) classes/*.cpp -c
	$(CC) main.cpp *.o -o $(EXE)

clean:
	rm -f *.o

uninstall:
	rm -f $(EXE)
