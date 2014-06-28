#include <iostream>

#include "headers/sala.h"
#include "headers/sessao.h"
#include "headers/venda.h"
#include "headers/filme.h"
#include "headers/horario.h"

int main()
{
	Horario h(14,30);

	Sala sala(1, 3, disponivel, 5);
	Filme filme("Pai de familia", 18, 'N');
	Sessao sessao(&sala, h, &filme);
	Venda venda(&sessao, dinheiro);
	venda.addIngresso(sessao.getIngresso('B', 3));

	return 0;
}
