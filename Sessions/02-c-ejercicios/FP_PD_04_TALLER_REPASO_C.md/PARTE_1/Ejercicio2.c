#include <stdio.h>

int main() {

    int arreglo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *ptr = arreglo;

    int suma = 0;

    printf("=== EJERCICIO 2: SUMA USANDO PUNTEROS ===\n\n");

    for (int i = 0; i < 10; i++) {

        suma += *(ptr + i);

        printf("Elemento %d = %d | Suma acumulada = %d\n",
               i,
               *(ptr + i),
               suma);
    }

    printf("\nResultado final de la suma = %d\n", suma);

    return 0;
}