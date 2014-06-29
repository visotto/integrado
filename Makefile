<<<<<<< HEAD
CC = g++
EXE = cinema.exe
=======
principal:
	g++ main.cpp classes/assento.cpp classes/fileira.cpp classes/sala.cpp classes/gerenciasala.cpp classes/filme.cpp classes/gerenciafilme.cpp classes/sessao.cpp classes/gerenciasessao.cpp classes/venda.cpp classes/horario.cpp classes/ingresso.cpp -o cinema.exe
>>>>>>> FETCH_HEAD

all: $(EXE) clean

$(EXE):
	$(CC) classes/*.cpp -c
	$(CC) main.cpp *.o -o $(EXE)

clean:
	rm -f *.o

uninstall:
	rm -f $(EXE)
