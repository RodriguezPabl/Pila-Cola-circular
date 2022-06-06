void crearLista(tLista *l)
{
    *l = NULL;
}

int ponerAlPrincipio(tLista *l,const void *dato, unsigned tam)
{
    tNodo *nuevo;

    nuevo = (tNodo *)malloc(sizeof(tNodo));
    if(nuevo == NULL)
    {
        free(nuevo);
        return 0;
    }
    nuevo->dato = malloc(tam);
    if(nuevo->dato == NULL)
    {
        free(nuevo->dato);
        free(nuevo);
        return 0;
    }

    if(*l == NULL)
    {
        nuevo->sig = nuevo;
        *l = nuevo;
        return 1;
    }

    nuevo->sig = *l;
    nuevo->cantBytes = tam;
    memcpy(nuevo->dato,dato,tam);

    l = &(*l)->sig;
    while(*l != nuevo->sig)
        l = &(*l)->sig;

    *l->sig = nuevo;
}

int ponerAlFinal(tLista *l,const void *dato, unsigned tam)
{

}

int ponerSegundo(tLista *l,const void *dato, unsigned tam)
{

}
