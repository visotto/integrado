#include "../headers/filme.h"

Filme()
{
	filme = new Filme[qtdFilmes];  
}

Filme(const Filme &s)
{
	
}


void Filme::setTituloFilme(string _tituloFilme)
{
	tituloFilme = _tituloFilme;
}

void Filme::setFxEtaria(string _tituloFilme, int _fxetaria)
{
	fxetaria = _fxetaria;
}

void Filme::setIdioma(string _tituloFilme, int _idioma)
{
	idioma = _idioma;
}

void Filme::getTituloFilme()
{
	return tituloFilme
}

void Filme::setFxEtaria()
{
	return fxetaria;
}

void Filme::setIdioma()
{
	return idioma;
}


