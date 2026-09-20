/*
 ============================================================================
 Archivo        : ejercicio_06_invertir_arreglo.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que invierte los elementos de un arreglo
                  utilizando aritmetica de punteros.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>

/*
 * Funcion      : invertir_arreglo
 * Descripcion  : Invierte los elementos de un arreglo utilizando punteros.
 * Parametro    : arr - Puntero al arreglo.
 * Parametro    : tamaño - Cantidad de elementos del arreglo.
 * Retorno      : No retorna ningun valor.
 */
void invertir_arreglo (int *arr, int tamaño);

void invertir_arreglo (int *arr, int tamaño){
    int temporal;

    for (int i = 0; i < tamaño / 2; i++){
        temporal = *(arr + i);
        *(arr + i) = *(arr + tamaño - 1 - i);
        *(arr + tamaño - 1 - i) = temporal;
    }
}

/*
 * Funcion      : imprimir_arreglo
 * Descripcion  : Imprime los elementos del arreglo.
 * Parametro    : arr - Puntero al arreglo.
 * Parametro    : tamaño - Cantidad de elementos del arreglo.
 * Retorno      : No retorna ningun valor.
 */

void imprimir_arreglo (int *arr, int tamaño);

void imprimir_arreglo (int *arr, int tamaño){
    printf("[");

    for (int i = 0; i < tamaño; i++){
        printf("%d", *(arr + i));

        if (i < tamaño - 1){
            printf(", ");
        }
    }

    printf("]\n");
}

int main (void){
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Arreglo original: ");
    imprimir_arreglo(arreglo, tamaño);

    invertir_arreglo(arreglo, tamaño);

    printf("Arreglo invertido: ");
    imprimir_arreglo(arreglo, tamaño);

    return 0;
}