#include <iostream>

using namespace std;

#include "headers/assento.h"

int main()
{
	Assento **assentos;

	assentos = new Assento*[5];
	for (int i = 0; i < 5; i++)
	{
		assentos[i] = new Assento(i+1, true, 'A');
		cout << assentos[i]->getIdAssento() << " " << assentos[i]->getIdFileira() << endl;
	}

}
