template <class Classe> class No
{
	public;
		Classe info;
		No<Classe> *esq, *dir;
		No();
		No(Classe c);
}

typedef No* Arvore;
