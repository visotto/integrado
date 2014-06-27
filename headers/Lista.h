#ifndef LISTA_H
#define LISTA_H

template <class T>
class Lista
{
	private:
		T info;
		T *next;

	public:
		Lista()
		{
			next = NULL;
		}

		bool insere(T elemento)
		{
			Lista <T> *novo = new Lista;
			novo->info = elemento.info;
			novo->next = next;
			next = novo;
		}

		T acessa(int posicao)
		{
			Lista <T> *aux = next;

			while
		}

};


// template <class T>
// bool Lista<T>::insere(T elemento)
// {
// 	Lista <T> *novo = new Lista;
// }

// template <class T> bool remove(T elemento);
// template <class T> bool acessa(int posicao);

#endif // LISTA_H