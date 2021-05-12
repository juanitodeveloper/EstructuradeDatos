/*
(simulación de Supermercado) Escriba un programa que simule una línea para
pagar en un supermercado. La línea es un objeto cola. Los clientes (es decir,
los objetos clientes) llegan en intervalos enteros aleatorios de 1 a 4 minutos.
además, a cada cliente se le atiende en intervalos enteros aleatorios de 1 a 4
minutos. Obviamente, los ritmos necesitan balancearse. Si el ritmo promedio
de llegada es mayor que el ritmo promedio de atención, la cola crecerá
infinitamente, incluso con ritmos “balanceados”, el factor aleatorio puede aún
provocar largas líneas. Ejecute la simulación del supermercado durante un día
de 12 horas (720 minutos), utilizando el siguiente algoritmo:
1.  Elegir un entero aleatorio entre 1 y 4 para determinar el minuto en el
que debe llegar el primer cliente
2.  Al momento en que llegue el cliente:
Determinar el tiempo de atención del cliente (entero aleatorio de 1 a 4 al
tiempo actual)
3.  Para cada minuto del día:
Si llega el siguiente cliente,
Decirlo así.
Poner el cliente en la cola.
Programar la hora de llegada del siguiente
cliente Si se terminó de atender al último cliente,
Decirlo así,
Sacar la cola al siguiente cliente al que va a atender
Determinar el tiempo requerido para dar servicio al cliente (se
suma un entero aleatorio de 1 al tiempo actual).
Ahora ejecute su simulación durante 720 minutos y responda a cada una de las
siguientes preguntas:
a.  ¿Cuál es el máximo número de clientes en la cola, en cualquier
momento dado?
b.  ¿Cuál es el tiempo de espera más largo que experimenta un cliente?
c.  Que ocurre si el intervalo de llegada se cambia de 1 a 4 minutos por
un intervalo de 1 a 3 minutos.
*/

#include <stdio.h>   // printf()
#include <malloc.h>  // malloc()
#include <time.h>    // time_t structure
#include <stdlib.h>  // srand()
//#include <conio.h>   // getch()

// #definir INTERVALO_MAX 4
#define CLIENTE_MAX 10001 // el rango de nombre de clientes (0 ~ 10000)


typedef struct _qnodo
{
	int esperaTiempo; 
	struct _qnodo *prev; 
	struct _qnodo *next; 
} qnodo; 


typedef struct _tnodo
{
	int clienteNo;
	struct _tnodo *left; 
	struct _tnodo *right;
} tnodo; 

/* Variables para la Cola */
qnodo *cabeza, *cola; 
int colaDataCount;
int maxNumero = 0; 
int maxTiempo; 
int maxWaitTiempo = 0; 

tnodo *base; 
bool clienteNo[10001]; // 0 ~ 10000
int curClienteNo; 

/* Funciones para Cola */
void InitCola(); 
int Encola(int value); 
int Decola();
void ClearCola(); 
void AddWaitTiempoToCola(); 


void Initarbol(int initValue); 
tnodo* InsertToarbol(int value);
int GetNewClienteNumero();
void Outputarbol(tnodo *nodo, int totalSpace, int fondo);


int main(int argc, char **argv) // parametros (max-llegada, max-servicio, tiempo)
{
	int intervaloMaxLlegada = 4; 
	int intervaloMaxServicio = 4; 
	int PeriodoSimulacion = 720;

	if (argc == 4) 
	{
		intervaloMaxLlegada = atoi(argv[1]);
		intervaloMaxServicio = atoi(argv[2]);
		PeriodoSimulacion = atoi(argv[3]);
	}

	time_t t; 
	srand(time(&t)); 
	int count = 0; 
    int esperaTiempo; 
	int llegadaTiempo; 
	int servicioTiempo; 
	
	InitCola(); 
	Initarbol(0); 

	for(int i = 0; i < CLIENTE_MAX; i++)
		clienteNo[i] = true;

	llegadaTiempo = rand() % intervaloMaxLlegada + 1; 
	count += llegadaTiempo; 

	curClienteNo = GetNewClienteNumero(); 

	InsertToarbol(curClienteNo); 
	clienteNo[curClienteNo] = false; 

	servicioTiempo = rand() % intervaloMaxServicio + 1; 
	llegadaTiempo = rand() % intervaloMaxLlegada + 1; 
	
	while(count < PeriodoSimulacion) 
	{
		if(maxNumero < colaDataCount) 
		{
			maxNumero = colaDataCount; 
			maxTiempo = count; 
		}

		llegadaTiempo--; 

		if(llegadaTiempo == 0) 
		{
		//	printf(" dentro "); 
			Encola(0); 
			InsertToarbol(GetNewClienteNumero());
			llegadaTiempo = rand() % intervaloMaxLlegada + 1;
		}

		servicioTiempo--; 

		if(servicioTiempo == 0) 
		{
		//	printf(" fuera "); 
			esperaTiempo = Decola(); 
			servicioTiempo = rand() % intervaloMaxServicio + 1;

			if(maxWaitTiempo < esperaTiempo) 
			{
				maxWaitTiempo = esperaTiempo; 
			}
		}

		AddWaitTiempoToCola(); 
		count++; 
		printf("\nNumero de Clientes en la linea : %2d, Tiempo Actual: %3d", colaDataCount, count); 
	}

	printf("\n\nMaximo Numero : %d clientes al %d minuto", maxNumero, maxTiempo); 
	printf("\nMaximo Tiempo de espera : %d minutos", maxWaitTiempo); 
	printf("\n\n");



	ClearCola(); 
	return 0;
}


/* Inicializar cola */
void InitCola()
{
	cabeza = (qnodo *)malloc(sizeof(qnodo)); 
	cola = (qnodo *)malloc(sizeof(qnodo)); 
	cabeza->prev = cabeza; 
	cabeza->next = cola;
	cola->prev = cabeza; 
	cola->next = cola; 
	colaDataCount = 0; 
}


int Encola(int value)
{
	qnodo *newNodo; 

	if((newNodo = (qnodo *)malloc(sizeof(qnodo))) == NULL) 
	{
		printf("\nOut of memory."); 
		return -1;
	}

	newNodo->esperaTiempo = value; 
	cola->prev->next = newNodo; 
	newNodo->prev = cola->prev; 
	cola->prev = newNodo;
	newNodo->next = cola; 

	colaDataCount++;

	return value;
}


int Decola() 
{
	qnodo *delNodo; 
	delNodo = cabeza->next; 

	if(delNodo == cola) 
	{
		printf("\nNo Clientes"); 
		return -1;
	}

	int i = delNodo->esperaTiempo; 
	cabeza->next = delNodo->next; 
	delNodo->next->prev = cabeza; 
	free(delNodo); 

	colaDataCount--; 
	return i;
}


void ClearCola() 
{
	qnodo *nodo1; 
	qnodo *nodo2; 
	nodo1 = cabeza->next; 
	while(nodo1 != cola) 
	{  
		nodo2 = nodo1;
		nodo1 = nodo1->next;
		free(nodo2); 
	}

	cabeza->next = cola; 
	cola->prev = cabeza;
}


void AddWaitTiempoToCola()
{
	qnodo *curNodo; 
	curNodo = cabeza->next; 

	while(curNodo != cola) 
	{
		curNodo->esperaTiempo++;
		curNodo = curNodo->next; 
	}
}


void Initarbol(int initValue)
{
	base = (tnodo *)malloc(sizeof(qnodo)); 
	base->clienteNo = initValue; 
	base->left = NULL; 
	base->right = NULL; 
}


tnodo* InsertToarbol(int value)
{
	tnodo *nodo1, *nodo2;
	nodo1 = base; 
	nodo2 = base->left; 

	while(nodo2 != NULL) 
	{
		nodo1 = nodo2; 

		if(value < nodo2->clienteNo) 
			nodo2 = nodo2->left;
		else
			nodo2 = nodo2->right; 
	}

	if((nodo2 = (tnodo *)malloc(sizeof(tnodo))) == NULL) 
		return NULL;

	nodo2->clienteNo = value; 
	nodo2->left = NULL; 
	nodo2->right = NULL;

	if(value < nodo1->clienteNo || nodo1 == base) 
		nodo1->left = nodo2; 
	else
		nodo1->right = nodo2; 

	return nodo2;
}


int GetNewClienteNumero()
{
	int number; 

	while(1) 
	{
		number = rand() % CLIENTE_MAX; 
		if(clienteNo[number] == true) 
		{
			clienteNo[number] = false; 
			break; 
		}
	}

	return number; 
}
