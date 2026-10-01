#include <stdio.h>

int main() {

    char cadena[] = "OpenMP";

    char *ptr = cadena;

    printf("=== EJERCICIO 5: CADENA CON PUNTEROS ===\n\n");

    while (*ptr != '\0') {

        printf("Caracter: %c | Direccion de memoria: %p\n",
               *ptr,
               (void *)ptr);

        ptr++;
    }

    return 0;
}