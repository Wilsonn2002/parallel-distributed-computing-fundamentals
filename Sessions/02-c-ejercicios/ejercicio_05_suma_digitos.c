/*
 ============================================================================
 Archivo        : ejercicio_05_suma_digitos.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que calcula recursivamente la suma de los
                  digitos de un numero entero positivo.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>

/*
 * Funcion      : sumar_digitos
 * Descripcion  : Calcula recursivamente la suma de los digitos.
 * Parametro    : numero - Numero entero positivo.
 * Retorno      : La suma de los digitos del numero.
 */
int sumar_digitos (int numero);

int sumar_digitos (int numero){
    if (numero < 10){
        return numero;
    }

    return (numero % 10) + sumar_digitos(numero / 10);
}

int main (void){
    int numero;
    int resultado;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    resultado = sumar_digitos(numero);

    printf("La suma de los digitos es: %d\n", resultado);

    return 0;
}