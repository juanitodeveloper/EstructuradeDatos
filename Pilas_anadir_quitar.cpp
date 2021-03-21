/*
Ejercicio1: Hacer un programa para agregar numeros enteros a una pila, hasta que el
usuario lo decida, despues mostrar todos los numeros introducidos en la pila.
*/

#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Prototipo
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
int main(){
	Nodo *pila = NULL;
	int dato;
	char rpt;
	
	do{
		cout<<"Digite un numero: ";
		cin>>dato;
		agregarPila(pila,dato);
		
		cout<<"\nDesea agg otro elemento a pila(s/n): ";
		cin>>rpt;
	}while((rpt=='S')||(rpt=='s'));
	
	cout<<"\nSacando todos los elementos de pila: ";
	while(pila !=NULL){
		sacarPila(pila,dato);
		if(pila !=NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
		
	}
	
	
	getch ();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato =n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tElemento "<<n<<" Ha sido agg a pila correctamente";
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
