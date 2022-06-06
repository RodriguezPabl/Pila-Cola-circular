#include "ListaCircular.h"

//-----PILA CIRCULAR-----//
void crearPila(tLista *pila)
{
    *pila = NULL;
}

int ponerEnPila(tLista *pila,const void *dato,unsigned tam)
{
    tNodo *nuevo;

    if((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
            (nuevo->dato = (tNodo *)malloc(tam)) == NULL)
    {
        free(nuevo->dato);
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->dato,dato,tam);
    nuevo->cantBytes = tam;

    if(*pila == NULL)
    {
        nuevo->sig = nuevo;
        *pila = nuevo;
    }
    else
    {
        nuevo->sig = (*pila)->sig;
        (*pila)->sig = nuevo;
    }

    return 1;
}

int sacarDePila(tLista *pila,void *dato,unsigned tam)
{
    tNodo *elim = (*pila)->sig;

    if(*pila == NULL)
        return 0;

    memcpy(dato,elim->dato,MIN(tam,elim->cantBytes));
    if(*pila != (*pila)->sig)
        (*pila)->sig = elim->sig;
    else
        *pila = NULL;

    free(elim->dato);
    free(elim);

    return 1;
}

int pilaVacia(const tLista *pila)
{
    return (*pila == NULL);
}

int pilaLlena(const tLista *pila,unsigned tam)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tam);

    free(aux);
    free(info);

    return (aux == NULL || info == NULL);
}

int verTope(const tLista *pila,void *dato,unsigned tam)
{
    if(*pila == NULL)
        return 0;

    memcpy(dato,(*pila)->sig->dato,MIN(tam,((*pila)->sig->cantBytes)));

    return 1;
}

void vaciarPila(tLista *pila)
{
    tNodo *aux;

    aux = (*pila)->sig;
    (*pila)->sig = aux->sig;

    while(*pila != (*pila)->sig)
    {
        free(aux->dato);
        free(aux);

        aux = (*pila)->sig;
        (*pila)->sig = aux->sig;
    }

    *pila = NULL;
    free(aux->dato);
    free(aux);
}

//-----COLA CIRCULAR-----//
void crearCola(tLista *cola)
{
    *cola = NULL;
}

int ponerEnCola(tLista *cola,const void *dato,unsigned tam)
{
    tNodo *nuevo;

    if((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
            (nuevo->dato = (tNodo *)malloc(tam)) == NULL)
    {
        free(nuevo->dato);
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->dato,dato,tam);
    nuevo->cantBytes = tam;
    if(*cola == NULL)
        nuevo->sig = nuevo;
    else
    {
        nuevo->sig = (*cola)->sig;
        (*cola)->sig = nuevo;

    }
    *cola = nuevo;

    return 1;
}

int sacarDeCola(tLista *cola,void *dato,unsigned tam)
{
    tNodo *elim = (*cola)->sig;

    if(*cola == NULL)
        return 0;

    memcpy(dato,elim->dato,MIN(tam,elim->cantBytes));

    if(*cola != (*cola)->sig)
        (*cola)->sig = elim->sig;
    else
        *cola = NULL;

    free(elim->dato);
    free(elim);

    return 1;
}

int colaVacia(const tLista *cola)
{
    return (*cola == NULL);
}

int colaLlena(const tLista *cola,unsigned tam)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tam);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int verPrimero(const tLista *cola,void *dato,unsigned tam)
{
    if(*cola == NULL)
        return 0;

    memcpy(dato,(*cola)->sig->dato,MIN(tam,(*cola)->sig->cantBytes));

    return 1;
}

void vaciarCola(tLista *cola)
{
    tNodo *aux;

    while((*cola)->sig != *cola)
    {
        aux = (*cola)->sig;
        (*cola)->sig = aux->sig;

        free(aux->dato);
        free(aux);
    }

    aux = *cola;
    free(aux->dato);
    free(aux);
    *cola = NULL;
}
