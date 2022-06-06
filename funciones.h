#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void *dato;
    unsigned cantBytes;
    sNodo *sig;
}tNodo;

typedef tNodo *tLista;

void crearLista(tLista *l);
int ponerAlPrincipio(tLista *l,const void *dato, unsigned tam);
int ponerAlFinal(tLista *l,const void *dato, unsigned tam);
int ponerSegundo(tLista *l,const void *dato, unsigned tam); // Más barato

#endif // FUNCIONES_H_INCLUDED
