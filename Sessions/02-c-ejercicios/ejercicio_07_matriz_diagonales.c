/*
 ============================================================================
 Archivo        : ejercicio_07_matriz_diagonales.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que genera una matriz cuadrada con numeros
                  aleatorios y compara las sumas de sus diagonales.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM 100

int main (void){
    int tamaño;
    int suma_principal = 0;
    int suma_secundaria = 0;

    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &tamaño);

    int matriz[tamaño][tamaño];

    srand((unsigned int) time(NULL));

    printf("\nMatriz:\n");

    for (int i = 0; i < tamaño; i++){
        for (int j = 0; j < tamaño; j++){
            matriz[i][j] = rand() % MAX_RANDOM + 1;
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < tamaño; i++){
        suma_principal += matriz[i][i];
        suma_secundaria += matriz[i][tamaño - 1 - i];
    }

    printf("\nSuma diagonal principal: %d\n", suma_principal);
    printf("Suma diagonal secundaria: %d\n", suma_secundaria);

    if (suma_principal > suma_secundaria){
        printf("La diagonal principal es mayor.\n");
    } else if (suma_secundaria > suma_principal){
        printf("La diagonal secundaria es mayor.\n");
    } else {
        printf("Las dos diagonales tienen la misma suma.\n");
    }

    return 0;
}