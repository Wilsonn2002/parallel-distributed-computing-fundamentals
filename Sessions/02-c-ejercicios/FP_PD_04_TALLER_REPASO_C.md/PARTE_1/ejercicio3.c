#include <stdio.h>
#include <stdlib.h>

int main() {

    int filas = 3;
    int columnas = 3;

    // Reservar memoria para las filas
    int **matriz = (int **)malloc(filas * sizeof(int *));

    // Reservar memoria para cada fila
    for (int i = 0; i < filas; i++) {
        *(matriz + i) = (int *)malloc(columnas * sizeof(int));
    }

    // Inicializar la matriz usando aritmética de punteros
    int valor = 1;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            *(*(matriz + i) + j) = valor;

            valor++;
        }
    }

    printf("=== EJERCICIO 3: MATRIZ 3x3 CON PUNTEROS ===\n\n");

    // Mostrar contenido de la matriz
    for (int i = 0; i < filas; i++) {

        for (int j = 0; j < columnas; j++) {

            printf("%d\t", *(*(matriz + i) + j));
        }

        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(*(matriz + i));
    }

    free(matriz);

    return 0;
}