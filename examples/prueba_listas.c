#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    /* data */
    char *nombre;
    struct nodo *siguiente;
} Nodo;

Nodo *listaNodo(Nodo *nodo) {
    nodo = NULL;
    return nodo;
}

int main() {
    Nodo *nodo = listaNodo(nodo);
    printf("%p\n", nodo);
    return 0;
}