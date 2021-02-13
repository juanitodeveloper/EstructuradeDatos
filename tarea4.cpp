/*Elabore un programa que permita guardar en un arreglo las sumas de las filas de
una matriz. Esto es, la suma de los elementos de la primera fila deberá quedar
guardada en la primera posición del arreglo, la suma de los elementos de la segunda
fila en la segunda posición, y así sucesivamente para todas las filas de la matriz. La
máxima dimensión de la matriz es 100x50 (100 filas y 50 columnas) y la del vector
es 100. Arreglo multidimensionales*/

#include <iostream>

using namespace std;

int tarea4() {
	
	int x,y;
	
	cout<<"\n";
	cout<<"A continuacion se le pediran las dimensiones de un arreglo"<<"\n";
	cout<<"para ingresar y sumar los valores de todas las filas"<<"\n";
	cout<<"****************************************************"<<"\n";	
	cout<<"Ingrese la cantidad de filas, no mayor a 100 (Sumas de fila a realizar)"<<"\n";
	cin>>x;
	cout<<"Ingrese la cantidad de columnas, no mayor a 50 (no. de elementos en las filas)"<<"\n";
	cin>>y;
	
	while (x>100 || y>50 ){
	cout<<"INGRESE DIMENSIONES DENTRO DEL RANGO"<<"\n";
	cout<<"Ingrese la cantidad de filas, no mayor a 100 (Sumas de fila a realizar)"<<"\n";
	cin>>x;
	cout<<"Ingrese la cantidad de columnas, no mayor a 50 (no. de elementos en las filas)"<<"\n";
	cin>>y;
	}
	
	//llenar arreglo
	int suma=0;
	int arreglo[x][y];
	int vector[x];
	
	for (int i=0; i<x; i++){

			cout<<"esta en la fila No. "<<i+1<<"\n";
				for (int j=0; j<y; j++){
				cout<<"Ingrese el valor de la columna No. "<<j+1<<": ";
				cin>>arreglo[x][y];
				suma=suma+arreglo[x][y];
				}
			//aprovechando el ciclo para ir sumando las columas por fila
			vector[i]=suma;
			suma=0;
	}
	
	cout<<"\n";
	//imprimir el vector
	cout<<"Resultados de la suma de cada fila por columnas"<<"\n";
	for (int i=0;i<x;i++){
		cout<<vector[i]<<"\n";
	}
	
	
	system("pause");
	return 0;
}
