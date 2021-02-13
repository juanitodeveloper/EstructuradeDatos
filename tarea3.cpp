/*Realizar un programa que permita inicializar dos matrices de 3 filas por 4 columnas
con valores enteros leídos desde el teclado. Calcular la suma de los valores de
ambas matrices e imprimir los arreglos iniciales y la resultante Arreglo
multidimensionales*/

#include <iostream>

using namespace std;

int tarea3() {
	int arreglo1[3][4];
	int arreglo2[3][4];
	int resultado[3][4];
	
	cout<<"A continuacion se le pedira llenar 2 matrices para sumarlas"<<"\n";
	cout<<"Matriz No. 1 "<<"\n";
	for (int x=0; x<3; x++){
		cout<<"esta en la fila No. "<<x+1<<"\n";
			for (int y=0; y<4; y++){
			cout<<"Ingrese el valor de la columna No. "<<y+1<<": ";
			cin>>arreglo1[x][y];
			}
	}
	cout<<"\n";
	cout<<"Matriz No. 2 "<<"\n";
	for (int x=0; x<3; x++){
		cout<<"esta en la fila No. "<<x+1<<"\n";
			for (int y=0; y<4; y++){
			cout<<"Ingrese el valor de la columna No. "<<y+1<<": ";
			cin>>arreglo2[x][y];
			}
	}
	//Imprimiendo
	cout<<"\n";
	cout<<"Matriz No. 1 "<<"\n";
	for (int x=0; x<3; x++){
			for (int y=0; y<4; y++){
			cout<<arreglo1[x][y];
			}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<"Matriz No. 2 "<<"\n";
	for (int x=0; x<3; x++){
			for (int y=0; y<4; y++){
			cout<<arreglo2[x][y];
			}
		cout<<"\n";
	}
	cout<<"\n";
	//sumando e imprimiendo resultado
	cout<<"Resultado "<<"\n";
	for (int x=0; x<3; x++){
			for (int y=0; y<4; y++){
			resultado[x][y]=arreglo1[x][y]+arreglo2[x][y];
			cout<<resultado[x][y]<<" ";
			}
		cout<<"\n";

	}
	
	system("pause");
	return 0;
}
