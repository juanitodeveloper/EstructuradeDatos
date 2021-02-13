/*Hacer un programa que a través de una lista inicializadora de elementos, reciba un
arreglo de números reales de 10 de lementos y entregue el número mayor. Arreglos
unidimensionales*/

#include <iostream>

using namespace std;

int tarea6() {
	float arreglo[10]={0.01,-98,19,3.141516,2.71,45,10000,889.267,36.4,189};
	float mayor = 0;
	cout<<"A continuacion se le imprime el arreglo de dimension 10"<<"\n";
	
	for (int x=0; x<10; x++){
		cout<<arreglo[x]<<" | ";
	}
	mayor = arreglo [0];
	
	for (int y=0; y<10; y++){
		if (mayor < arreglo [y]){
		mayor = arreglo [y];
		}
	}
	cout<<"\n";
	cout<<"El numero mayor es: "<<mayor<<"\n";
	system("pause");
	return 0;
}
