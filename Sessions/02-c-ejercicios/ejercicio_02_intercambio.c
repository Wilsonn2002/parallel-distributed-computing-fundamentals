/*
 ============================================================================
 Archivo        : ejercicio_02_intercambio.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que intercambia los valores de dos numeros
                  enteros utilizando punteros.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>

/*
 * Funcion      : intercambiar
 * Descripcion  : Intercambia los valores de dos numeros enteros
 *                utilizando punteros.
 * Parametro    : a - Puntero al primer numero.
 * Parametro    : b - Puntero al segundo numero.
 * Retorno      : No retorna ningun valor.
 */
void intercambiar (int *a, int *b);

void intercambiar (int *a, int *b){
    int temporal;

    temporal = *a;
    *a = *b;
    *b = temporal;
}

int main (void){
    int numero1;
    int numero2;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);

    printf("\nAntes del intercambio:\n");
    printf("Numero 1: %d\n", numero1);
    printf("Numero 2: %d\n", numero2);

    intercambiar(&numero1, &numero2);

    printf("\nDespues del intercambio:\n");
    printf("Numero 1: %d\n", numero1);
    printf("Numero 2: %d\n", numero2);

    return 0;
}