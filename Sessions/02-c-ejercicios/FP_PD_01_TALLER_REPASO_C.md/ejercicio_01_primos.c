/*
 ============================================================================
 Archivo        : ejercicio_01_primos.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que genera un arreglo de números aleatorios y
                  cuenta la cantidad de números primos que contiene.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANDOM 100

/*
 * Funcion      : es_primo
 * Descripcion  : Determina si un numero es primo.
 * Parametro    : numero - Numero entero que se desea evaluar.
 * Retorno      : 1 si el numero es primo, 0 en caso contrario.
 */
int es_primo (int numero);

int es_primo (int numero){
    if (numero < 2){
        return 0;
    }
    for (int i = 2; i < numero; i++){
        if (numero % i == 0){
            return 0;
        }
    }
    return 1;
}
int main (void){
    int tamano;
    int cantidad_primos = 0;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tamano);

    int arreglo[tamano];

    srand((unsigned int) time(NULL));

    for (int i = 0; i < tamano; i++){
        arreglo[i] = rand() % MAX_RANDOM + 1;
    }
    for (int i = 0; i < tamano; i++){
        if (es_primo (arreglo[i])){
            cantidad_primos++;
        }
    }
    printf("Cantidad de numeros primos: %d\n", cantidad_primos);
    return 0;
}