#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN( X , Y ) ((X) < (Y) ? (X) : (Y))

typedef struct sNodo
{
    void *dato;
    unsigned cantBytes;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tLista;

void crearPila(tLista *pila);
int ponerEnPila(tLista *pila,const void *dato,unsigned tam);
int sacarDePila(tLista *pila,void *dato,unsigned tam);
int pilaVacia(const tLista *pila);
int pilaLlena(const tLista *pila,unsigned tam);
int verTope(const tLista *pila,void *dato,unsigned tam);
void vaciarPila(tLista *pila);

void crearCola(tLista *cola);
int ponerEnCola(tLista *cola,const void *dato,unsigned tam);
int sacarDeCola(tLista *cola,void *dato,unsigned tam);
int colaVacia(const tLista *cola);
int colaLlena(const tLista *cola,unsigned tam);
int verPrimero(const tLista *cola,void *dato,unsigned tam);
void vaciarCola(tLista *cola);

#endif // LISTACIRCULAR_H_INCLUDED
