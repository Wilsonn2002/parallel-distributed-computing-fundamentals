#include <stdio.h>

int main() {

    int arreglo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *ptr = arreglo;

    printf("=== EJERCICIO 1: ARREGLO CON PUNTEROS ===\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Elemento %d = %d\n", i, *(ptr + i));
    }

    return 0;
}