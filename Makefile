CC = g++
EXE = cinema.exe

all: $(EXE) clean

$(EXE):
	$(CC) classes/*.cpp -c
	$(CC) main.cpp *.o -o $(EXE)

clean:
	rm -r -f *.o
	rm -r -f *~

uninstall:
	rm -f $(EXE)
