#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Nodo
{
	int Auto;
	int Fila;
	Nodo* Siguiente;
};

bool colaVacia(Nodo*);
void InsertarCola(Nodo*&, Nodo*&, int, int);
void ImprimirCola(Nodo*& Frente);
void SuprimirCola(Nodo*&, Nodo*&, int, int);

int AutoMaquina = 0;

int main()
{
	int Fila = 0, Maquina = 0, FilaIn = 0, MaquinaIn = 0, Auto = 1;
	Nodo* Frente = NULL;
	Nodo* Fin = NULL;

	srand(time(NULL));

	cout << endl;
	cout << "\t\t\tCarWash"<< endl;
	cout << "\t****************************************************" << endl;

	Fila = rand() % 30 + 1;
	Maquina = rand() % 15 + 10;
	FilaIn = Fila;
	MaquinaIn = Fila + Maquina;
	InsertarCola(Frente, Fin, Auto, FilaIn);

	for (size_t i = 1; i <= 540; i++)
	{
		if (i == FilaIn)
		{
			Fila = rand() % 30 + 1;

			FilaIn = i + Fila;
			Auto++;
			InsertarCola(Frente, Fin, Auto, Fila);
		}

		if (i == MaquinaIn)
		{
			Maquina = rand() % 15 + 10;
			SuprimirCola(Frente, Fin, Auto, MaquinaIn);
			MaquinaIn = i + Maquina;
		}
	}

	cout << endl;
	cout << "\tTotal de carros lavados : " << AutoMaquina  << endl;
	cout << "\tTotal cobrado : L." << AutoMaquina * 90 << endl;
	cout << "\t*************************************************" << endl;

	cout << endl;
	cout << "\tImprimiendo carros que quedan en la fila: \t" << endl;
	ImprimirCola(Frente);
	cout << "\t*************************************************" << endl;

	return 0;
}

bool colaVacia(Nodo* Frente)
{
	return (Frente == NULL) ? true : false;
}

void InsertarCola(Nodo*& Frente, Nodo*& Fin, int _auto, int _fila)
{
	Nodo* newNodo = new	Nodo();
	newNodo->Auto = _auto;
	newNodo->Fila = _fila;
	newNodo->Siguiente = NULL;

	if (colaVacia(Frente))
	{
		Frente = newNodo;
		Fin = newNodo;
	}
	else
	{
		Fin->Siguiente = newNodo;
		Fin = newNodo;
	}
	cout << "\tSe agrego a la fila el carro : " << _auto << endl;
}

void SuprimirCola(Nodo*& Frente, Nodo*& Fin, int _auto, int _fila)
{
	if (!colaVacia(Frente))
	{
		_auto = Frente->Auto;
		_fila = Frente->Fila;

		Nodo* Auxiliar = Frente;

		if (Frente == Fin)
		{
			Frente = NULL;
			Fin = NULL;
		}
		else
		{
			Frente = Frente->Siguiente;
		}

		delete Auxiliar;
		cout << "\tSe quito de la fila un carro" << endl;
		AutoMaquina++;
	}
}

void ImprimirCola(Nodo*& Frente)
{
	Nodo* ImprimirFrente = Frente;

	while (ImprimirFrente != NULL)
	{
		cout << "\tcarro: " << ImprimirFrente->Auto << endl;
		ImprimirFrente = ImprimirFrente->Siguiente;
	}
}
