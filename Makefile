facasopa:
	g++ main.cpp classes/assento.cpp classes/fileira.cpp classes/sala.cpp classes/gerenciasala.cpp classes/sessao.cpp classes/venda.cpp classes/ingresso.cpp -o cinema.exe

testesvenda:
	g++ testesvenda.cpp classes/assento.cpp classes/fileira.cpp classes/sala.cpp classes/sessao.cpp classes/venda.cpp classes/ingresso.cpp classes/filme.cpp classes/horario.cpp -o cinema.exe
