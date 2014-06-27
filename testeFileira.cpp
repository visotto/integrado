#include <iostream>

using namespace std;

#include "headers/fileira.h"

int main()
{
	Fileira **fileiras;

	fileiras = new Fileira*[5];
	for (int i = 0; i < 5; i++)
	{
		fileiras[i] = new Fileira('A'+i, 5);
		cout << "ID Da fileira " << i << " : " << fileiras[i]->getIdFileira() << endl;
		cout << "Assentos desta fileira:" << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << fileiras[i]->getAssento(j)->getIdFileira() << fileiras[i]->getAssento(j)->getIdAssento() << endl;
		}
	}
}
