/*
Realice un programa en C++ que defina un arreglo de tipo float de 12 elementos, 
permita ingresar los valores por teclado, 
encuentre el valor mínimo 
y lo muestre en pantalla.
*/

#include <iostream>
using namespace std;

int main() {
			
float arreglo[12], *dir_arreglo;
float menor = 0;

	cout<<"A continuacion se le pedira ingresar 12 numeros float"<<"\n";
	//Llenando el arreglo
	for (int x=0; x<12; x++){
		cout<<"Ingrese el elemento No. "<<x+1<<": ";
		cin>>arreglo[x];		
	}

	dir_arreglo = &arreglo[0]; //posicion donde comienza el arreglo
	menor = *arreglo; //se toma como menor el primer elemento del arreglo para comparar
	
	//buscando el numero menor en el arreglo
	for (int y=0; y<12; y++){
		if (*dir_arreglo < menor){
		menor = *dir_arreglo;
		}
		dir_arreglo++; //avanzando posicion en el recorrido del arreglo
	}
	
	cout<<"El numero menor ingresado es: "<<menor<<"\n";
	system("pause");
	return 0;
}

//Inmer Suazo 2021
