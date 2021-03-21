/*
Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen uno, dos, tres cuatro, cinco y seis
puntos negros, respectivamente. Una vez que los dados dejan de moverse, se calcula la suma de los puntos
negros en las dos caras superiores. Si la suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2,
3 o 12 en el primer tiro (llamado “craps”), el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9
o 10 en el primer tiro, esta suma se convierte en el “punto” del jugador. Para ganar, el jugador debe seguir
tirando los dados hasta que salga otra vez “su punto” (es decir, que tire ese mismo valor de punto). El jugador
pierde si tira un 7 antes de llegar a supunto.
• Guarde en un objeto pila llamado Craps, cada uno de los jugadores, el estado de su juego (gana o
pierde), con cuantos puntos ganó o perdió cada uno y, si fue en el primero tiro o con “punto del
jugador”
*/


#include <iostream>
#include <cstdlib> //funcion RAND
#include<ctime>//funcion time
#include<conio.h>
using namespace std;

struct Nodo{
	string nombre;
	string estado;
	int puntos; 
	Nodo *siguiente;
};

//Prototipo (nodo, nombre, gano o perdio, puntuacion)
void agregarPila(Nodo *&, string, string, int);
void sacarPila(Nodo *&, string &, string &, int &);

int tirarDados(){
    int dado1= 1+rand()%6;//primer dado
    int dado2= 1+rand()%6;//segundo dado
    int suma=dado1+dado2; //Suma de valores de los dados
    //mostrando resultado de este tiro
	cout<<"El jugador tira "<<dado1<<" + "<<dado2<<" = "<<suma<<endl;
	return suma;//devuelve la suma de los dados
}

int main(){
	Nodo *pila = NULL;

	int no=1;
	string name="";
	char otro='s';
	string estado="";
	int miPunto;//punto si no se gana o pierde en el primer turno	
	
	do{
        cout<<"ingrese el nombre del jugador No. ";
        cout<<no<<endl;
        cin>>name;
        no=no+1;
        //*********************************************
    //    string estado="";
	//	int miPunto;//punto si no se gana o pierde en el primer turno
		srand(time(0));
		int sumaDeDados=tirarDados();
		int numeroaleatorio = (1 + rand() % 100);

		//determinando estado del juego
		switch(sumaDeDados){
		case 7: //gana con 7 en el primer turno
		case 11: //gana con 11 en el primer turno
    	estado= "gano";
		break;
		case 2: //pierde con 2 en el primer turno
		case 3: //pierde con 3 en el primer turno
		case 12: //pierde con 12 en el primer turno
		estado= "perdio";
		break;
		default: //no gano ni perdio por lo que recuerda el numero
		estado= "continuar";
		miPunto=sumaDeDados; //recuerda el punto
		cout<<"El punto es "<<miPunto<<endl;
   		break; //final de switch
		}
	
    	//mientras el juego no este completo
		while(estado=="continuar")//no gano ni perdio
    	{
	    sumaDeDados=tirarDados();//tira los dados de nuevo
		//determina el estadi dek juego
    	if(sumaDeDados==miPunto){
        estado="gano";
        }else if(sumaDeDados==7){//pierde al tirar 7 antes de punto      	                 
		estado="perdio";
        }
		} //fin del while

		//muestra mensaje que gano o perdio
		if(estado=="gano"){
		cout<<"El jugador gana"<<endl;
		}
		else{
		cout<<"El jugador pierde"<<endl;
		}
		//*********************************************
        agregarPila(pila,name,estado,miPunto);
        cout<<endl;
		cout<<"\t*******************************************************"<<endl;
        cout<<"Desea anadir otro jugador? (s|n)"<<endl;
        cin>>otro;
	}while(otro != 'n');
	
	cout<<"\t*******************************************************"<<endl;
	cout<<"Sacando los datos de la pila"<<endl;
	while(pila !=NULL){
		sacarPila(pila,name,estado,miPunto);
		cout<<name<<" , "<<estado<<" , "<<miPunto<<"."<<endl;
	}
	
}

void agregarPila(Nodo *&pila, string nom, string est, int pun){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->nombre =nom;
	nuevo_nodo->estado =est;
	nuevo_nodo->puntos =pun;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tEl jugador "<<nom<<" Ha sido agregado a la pila correctamente";
}

void sacarPila(Nodo *&pila, string &nom, string &est, int &pun){
	Nodo *aux = pila;
	nom = aux->nombre;
	est = aux->estado;
	pun = aux->puntos;
	pila = aux->siguiente;
	delete aux;
}
