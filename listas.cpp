/*
1. Definición de listas
2. Implementación de una lista enlazada: Escriba un programa
utilizando listas enlazadas donde proporciones 5 funciones:
1) Insertar un valor al inicio de la lista
2) 2) insertar un valor al final de la lista
3) Eliminar un valor al inicio de la lista
4) Eliminar un valor al final de la lista
5) Terminar el procesamiento de la lista

*/


#include <iostream>
#include <stdlib.h>

using namespace std;
  
struct nodo{
       int numero;        
       struct nodo *sig;
};
 
typedef struct nodo *Lista;
 
 void menuSeleccion()
{
    cout<<" 1. Agregar un valor al inicio de la lista"<<endl;
    cout<<" 2. Agregar un valor al final de la lista"<<endl;
    cout<<" 3. Quitar un valor al inicio de la lista"<<endl;
    cout<<" 4. Quitar un valor al final de la lista"<<endl;
    cout<<" 5. Finalizar el procesamiento de la lista"<<endl;
    cout<<"Seleccione, ingrese un valor de 1 al 5"<<endl;
}
 
 
void insertarIni(Lista &lista, int valor)
{ 
    Lista a;
    a = new(struct nodo);
    a->numero = valor;
    a->sig = lista;
    lista  = a;
}
 
 
int insertAntesyDespues()
{
    int var1, var2;
    cout<<endl;
    cout<<"1. Antes"<<endl;
    cout<<"2. Despues"<<endl;
 
    cout<<"Opcion:"; cin>> var1;
 
    if(var1==1)
        var2 = -1;
    else
        var2 = 0;
 
    return var2;
}
 
void insertarFinal(Lista &lista, int valor)
{
    Lista t, a = new(struct nodo);
 
    a->numero  = valor;
    a->sig = NULL;
 
    if(lista==NULL)
    {
        lista = a;
    }
    else
    {
        t = lista;
        while(t->sig!=NULL)
        {
            t = t->sig;
        }
        t->sig = a;
    }
 
}
 
 
void eliminaRepetidos(Lista &lista, int valor)
{
    Lista a, ant;
    a = lista;
    ant = lista;
 
    while(a!=NULL)
    {
        if(a->numero==valor)
        {
            if(a==lista) 
            {
                lista = lista->sig;
                delete(a);
                a = lista;
            }
            else
            {
                ant->sig = a->sig;
                delete(a);
                a = ant->sig;
            }
        }
        else
        {
            ant = a;
            a = a->sig;
        }
 
    }
   
    cout<<"\n\n elementoes eliminados..!"<<endl;
}
 
 
void suprimirElement(Lista &lista, int valor)
{
    Lista b, ant;
    b = lista;
 
    if(lista!=NULL)
    {
        while(b!=NULL)
        {
            if(b->numero==valor)
            {
                if(b==lista)
                    lista = lista->sig;
                else
                    ant->sig =  b->sig;
 
                delete(b);
                return;
            }
            ant = b;
            b = b->sig;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 


 

int main()
{
    Lista lista = NULL;
    int seleccion;     
    int _dat;  
    int pos;    
 
    do
    {
        menuSeleccion();  cin>> seleccion;
 
        switch(seleccion)
        {
            case 1:
 
                 cout<< "elemento para agregar: "; cin>> _dat;
                 insertarIni(lista, _dat);
            break;
 
 
            case 2:
 
                 cout<< "elemento para agregar: "; cin>> _dat;
                 insertarFinal(lista, _dat );
            break;
 
            case 3:
 
                cout<<"elemento para eliminar"; cin>> _dat;
 
                suprimirElement(lista, _dat);
            break;
 
            case 4:
 
                cout<<"elemento repetido para eliminar"; cin>> _dat;
 
                eliminaRepetidos(lista, _dat);
            break;
 
                    }
 
        cout<<endl<<endl;
        system("pause");  
 
    }while(seleccion!=5);
 
 
   system("pause");
   return 0;
}
