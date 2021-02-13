/*Realice un programa en C++ que defina un arreglo de enteros de 12 elementos,
permita ingresar los valores por teclado, encuentre el valor máximo y lo muestre en
pantalla.*/

//Ahora funciona con numeros negativos

#include <iostream>

using namespace std;

int tarea1() {
	int arreglo[12];
	int mayor = 0;
	cout<<"A continuacion se le pedira ingresar 12 numeros enteros"<<"\n";
	for (int x=0; x<12; x++){
		cout<<"Ingrese el elemento No. "<<x+1<<": ";
		cin>>arreglo[x];		
	}
	mayor = arreglo [0];
	for (int y=0; y<12; y++){
		if (mayor < arreglo [y]){
		mayor = arreglo [y];
		}
	}
	cout<<"El numero mayor ingresado es: "<<mayor<<"\n";
	system("pause");
	return 0;
}
