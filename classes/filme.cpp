#include "../headers/filme.h"

Filme::Filme(string _tituloFilme, int _fxetaria, char _idioma)
{
	tituloFilme = _tituloFilme;
	fxetaria = _fxetaria;
	idioma = _idioma;
}

void Filme::setTituloFilme(string _tituloFilme)
{
	tituloFilme = _tituloFilme;
}

void Filme::setFxEtaria(int _fxetaria)
{
	fxetaria = _fxetaria;
}

void Filme::setIdioma(char _idioma)
{
	idioma = _idioma;
}

string Filme::getTituloFilme()
{
	return tituloFilme;
}

int Filme::getFxEtaria()
{
	return fxetaria;
}

char Filme::getIdioma()
{
	return idioma;
}

string Filme::getQueryID()
{
	return tituloFilme;
}
