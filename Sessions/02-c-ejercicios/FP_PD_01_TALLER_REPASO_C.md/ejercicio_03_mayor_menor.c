/*
 ============================================================================
 Archivo        : ejercicio_03_mayor_menor.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que determina el mayor y el menor de tres
                  numeros enteros utilizando operadores ternarios.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>

/*
 * Funcion      : mayor
 * Descripcion  : Determina el mayor de tres numeros enteros.
 * Parametro    : a - Primer numero entero.
 * Parametro    : b - Segundo numero entero.
 * Parametro    : c - Tercer numero entero.
 * Retorno      : El mayor de los tres numeros.
 */

int mayor (int a, int b, int c);

int mayor (int a, int b, int c){
    int mayor;

    mayor = (a > b) ? a : b;
    mayor = (mayor > c) ?  mayor : c;

    return mayor;
}
/*
 * Funcion      : menor
 * Descripcion  : Determina el menor de tres numeros enteros.
 * Parametro    : a - Primer numero entero.
 * Parametro    : b - Segundo numero entero.
 * Parametro    : c - Tercer numero entero.
 * Retorno      : El menor de los tres numeros.
 */

int menor (int a, int b, int c);

int menor (int a, int b, int c){
    int menor;

    menor = (a < b) ? a : b;
    menor = (menor < c) ? menor : c;

    return menor;
}

int main (void){
    int n1;
    int n2;
    int n3;

    printf("Ingresa el primer numero: ");
    scanf("%d", &n1);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &n2);

    printf("Ingresa el tercer numero: ");
    scanf("%d", &n3);

    printf("\n El mayor de los 3 es:  %d\n", mayor(n1, n2, n3));
    printf("\n El menor de los 3 es: %d\n", menor(n1, n2, n3));

    return 0;
}