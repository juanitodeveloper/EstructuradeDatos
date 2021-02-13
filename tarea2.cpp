/*Supongamos que en una elección hubo 12 candidatos (con identificadores
1,2,3,...,12). Por otra parte, los votos para cada candidato se teclean de manera
desorganizada como se muestra a continuación:
1 2 3 1 4 5 3 7 3 8 9 1 10 12 12 …….
Donde el numero del voto representa 1 voto para ese candidato.
Ejemplo: el voto 1 representa un voto para el candidato 1
El voto 10 representa un voto para el candidato 10
Escriba un programa que pueda proporcionar la siguiente información:
a) El número de votos de cada candidato al final de la elección.
b) El candidato ganador, el número de votos que obtuvo y el porcentaje
correspondiente del total de la elección. Suponemos que el candidato
ganador no empató en número de votos con otro candidato.*/

#include <iostream>

using namespace std;

int tarea2() {
	int arreglo[12];
	double mayor = 0;
	int noCandidato = 0;
	int noVotosTotal = 0;
	double porcentaje = 0;
	int bandera = 0;
	cout<<"A continuacion se le pedira ingresar el numero de votos de 12 candidatos"<<"\n";
	for (int x=0; x<12; x++){
		cout<<"Ingrese la cantidad de votos del candidato No. "<<x+1<<": ";
		cin>>arreglo[x];
		noVotosTotal=noVotosTotal+arreglo[x];		
	}
	mayor = arreglo [0];
	for (int y=0; y<12; y++){
		if (mayor < arreglo [y]){
		mayor = arreglo [y];
		noCandidato = y+1;
		}
	}

	for (int z=0; z<12; z++){
		if(mayor==arreglo[z])
		bandera=bandera+1;
	}
	
	if (bandera<=1){
		porcentaje =(mayor/noVotosTotal)*100;
		cout<<"El candidato ganador es el candidato No.: "<<noCandidato<<"\n";
		cout<<"Obtuvo la cantidad de votos: "<<mayor<<"\n";
		cout<<"Gano con un porcentaje total de: "<<porcentaje<<"%"<<"\n";
	}
	else{
	cout<<"Hubo empate"<<"\n";	
	}
	

	
	system("pause");
	return 0;
}
