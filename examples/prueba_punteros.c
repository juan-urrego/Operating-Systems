#include <stdio.h>

void jugar(int *n) {
    int y = *n;
    y = (y+2)/2+2 - (3*y);
    *n = y;
    printf("%d\n" , y);
}

int main() {
    int x=10;
    int *puntero = &x;
    int valor = *puntero;
    printf("puntero %d\n", puntero);
    printf("valor %d\n", valor);
    jugar(&x);
    printf("%d\n", x);


    const char *const city_names[9];
    city_names[0] = "New York";  // Error: el puntero es constante
    *city_names[0] = 'N';   
    printf("este es constante: %d\n", *numeroConstante);
    return 0;
}