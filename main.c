#include "ListaCircular.h"

int main()
{
    tLista pila,
           cola;
    int num = 10,
        num2 = 5,
        num3 = 15,
        otro;

    //-----PILA-----//
    puts("-----PILA-----");
    crearPila(&pila);

    ponerEnPila(&pila,&num,sizeof(int));
    ponerEnPila(&pila,&num2,sizeof(int));
    ponerEnPila(&pila,&num3,sizeof(int));
    verTope(&pila,&otro,sizeof(int));
    printf("En el tope hay: %d\n",otro);

    sacarDePila(&pila,&otro,sizeof(int));
    sacarDePila(&pila,&otro,sizeof(int));
    printf("Lo ultimo que saque fue: %d\n",otro);

    vaciarPila(&pila);
    if(pilaVacia(&pila))
        printf("La pila esta vacia\n");

    //-----COLA-----//
    puts("-----COLA-----");
    crearCola(&cola);

    ponerEnCola(&cola,&num,sizeof(int));
    ponerEnCola(&cola,&num2,sizeof(int));
    ponerEnCola(&cola,&num3,sizeof(int));
    verPrimero(&cola,&otro,sizeof(int));
    printf("El primero de la cola es: %d\n",otro);

    sacarDeCola(&cola,&otro,sizeof(int));
    sacarDeCola(&cola,&otro,sizeof(int));
    printf("Lo ultimo que saque fue: %d\n",otro);

    vaciarCola(&cola);
    if(colaVacia(&cola))
        printf("La cola esta vacia");

    return 0;
}
