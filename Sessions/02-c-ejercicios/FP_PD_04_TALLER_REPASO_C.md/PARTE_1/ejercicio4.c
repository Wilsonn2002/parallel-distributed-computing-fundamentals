#include <stdio.h>

// Funcion que intercambia dos valores usando punteros
void swap(int *a, int *b) {

    int temporal;

    temporal = *a;
    *a = *b;
    *b = temporal;
}

int main() {

    int numero1 = 10;
    int numero2 = 20;

    printf("=== EJERCICIO 4: INTERCAMBIO CON PUNTEROS ===\n\n");

    printf("Antes del intercambio:\n");
    printf("Numero 1 = %d\n", numero1);
    printf("Numero 2 = %d\n\n", numero2);

    // Enviamos las direcciones de memoria
    swap(&numero1, &numero2);

    printf("Despues del intercambio:\n");
    printf("Numero 1 = %d\n", numero1);
    printf("Numero 2 = %d\n", numero2);

    return 0;
}