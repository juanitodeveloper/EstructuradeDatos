/*Elabore un programa que lea los datos de una matriz 3x4 y muestra en pantalla la
suma de los datos de cada fila. Arreglo multidimensional*/

#include <iostream>

using namespace std;

int tarea5() {
	
	cout<<"A continuacion ingrese los valores del arreglo 3x4"<<"\n";
	
	//llenar arreglo
	int suma=0;
	int arreglo[3][4];
	int vector[3];
	
	for (int i=0; i<3; i++){

			cout<<"esta en la fila No. "<<i+1<<"\n";
				for (int j=0; j<4; j++){
				cout<<"Ingrese el valor de la columna No. "<<j+1<<": ";
				cin>>arreglo[i][j];
				suma=suma+arreglo[i][j];
				}
			//aprovechando el ciclo para ir sumando las columas por fila
			vector[i]=suma;
			suma=0;
	}
	
	cout<<"\n";
	//imprimir el vector
	cout<<"Resultados de la suma de cada fila por columnas"<<"\n";
	for (int i=0;i<3;i++){
		cout<<vector[i]<<"\n";
	}
	
	
	system("pause");
	return 0;
}
