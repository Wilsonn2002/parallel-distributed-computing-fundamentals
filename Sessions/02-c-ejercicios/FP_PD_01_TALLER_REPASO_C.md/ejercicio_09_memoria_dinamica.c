/*
 ============================================================================
 Archivo        : ejercicio_09_memoria_dinamica.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que crea un arreglo dinamico, almacena valores
                  ingresados por el usuario y calcula su suma.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
    int tamaño;
    int suma = 0;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &tamaño);

    int *arreglo = (int *) malloc(tamaño * sizeof(int));

    if (arreglo == NULL){
        printf("Error al reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < tamaño; i++){
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", arreglo + i);
    }

    for (int i = 0; i < tamaño; i++){
        suma += *(arreglo + i);
    }

    printf("La suma de los elementos es: %d\n", suma);

    free(arreglo);

    return 0;
}