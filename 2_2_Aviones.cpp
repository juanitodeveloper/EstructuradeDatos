/*
Considere una situación de la vida real. Formule una pregunta y luego
diseñe una simulación que pueda ayudar a responderla. Las posibles
situaciones incluyen:

• Aviones despegando y aterrizando en una pista

Asegúrese de indicar cualquier suposición que usted haga y proporcione
cualquier dato probabilístico que deba considerarse como parte del escenario.

*/


#include<conio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int codCompa;
	string codPais;
	string piloto;
	int hora;
	int tiempo;
	Nodo *siguiente;
};

bool colanula(Nodo *&inicio);
void InsertarCola(Nodo *&inicio, Nodo *&fin, int codCompa, string codPais, string piloto, int hora, int tiempo);
void Mostrar(Nodo *&inicio);


int main(){
	
	int codCompa; 
	string codPais;   
	string piloto;
	int hora;
	int tiempo;
	char reg; 
	Nodo *inicio=NULL;
	Nodo  *fin=NULL;
	
	
	reg='s';
	cout<<"\n";
		
	while(reg=='s'){		
		cout<<"Ingrese el codigo de la compania de vuelos"<<endl;
		cin>>codCompa;
		cin.ignore();
		
		cout<<"Ingrese el codigo del pais de destino"<<endl;
		getline(cin,codPais);
	
		cout<<"Ingrese nombre de piloto"<<endl;
		cin>>piloto;
		cin.ignore();
		
		cout<<"Ingrese numero de pasajeros"<<endl;
		cin>>hora;
		
		cout<<"Ingrese tiempo de vuelo en minutos"<<endl;
		cin>>tiempo;
		
		InsertarCola(inicio, fin, codCompa, codPais, piloto, hora, tiempo);  
		cout<<"\n";  	
		
		
		cout<<"Registrar otro vuelo"<<"\n";
		cout<<"Si ingrese: 's' | No ingrese: 'n'\n";
		cin>>reg;	
	} 
	
	cout<<"\n";
	cout<<"Resumen de los vuelos ingresados\n";
	Mostrar(inicio);
	cout<<"\n";
	
	system("pause");
	return 0;
}

void InsertarCola(Nodo *&inicio, Nodo *&fin, int codCompa, string codPais, string piloto, int hora, int tiempo)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->codCompa=codCompa;
	nuevo_nodo->codPais=codPais;
	nuevo_nodo->piloto=piloto;
	nuevo_nodo->hora=hora;
	nuevo_nodo->tiempo=tiempo;
	
	if(colanula(inicio))
	{inicio = nuevo_nodo;
	    fin = nuevo_nodo;			
	}
	else
	{
		fin->siguiente=nuevo_nodo;
		fin=nuevo_nodo;			
	}		
}

bool colanula(Nodo *&inicio)
{
	return(inicio == NULL)? true : false;
}

void Mostrar(Nodo *&inicio)
{
	Nodo *MostrarNodo=new Nodo();
		MostrarNodo=inicio;
		while (MostrarNodo != NULL)
		{
			cout<<"Codigo de compania:"<<MostrarNodo->codCompa<<"\n";
			cout<<"Codigo del pais: "<<MostrarNodo->codPais<<"\n";
			cout<<"Piloto a cargo: "<<MostrarNodo->piloto<<"\n";
			cout<<"Numero de pasajeros: "<<MostrarNodo->hora<<"\n";
			cout<<"Tiempo de vuelo (min): "<<MostrarNodo->tiempo<<"\n";
			MostrarNodo=MostrarNodo->siguiente;
			cout<<"\n";
		}
}
