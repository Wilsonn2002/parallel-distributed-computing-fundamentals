/*
 ============================================================================
 Archivo        : ejercicio_04_factorial_paridad.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que calcula el factorial de un numero entero
                  positivo y determina si el resultado es par o impar.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>

/*
*Funcion        : factorial
*Descripcion    : Calcula el factorial de un numero entero positivo.
*Parametro      : numero - Numero entero positivo.
*Retorno        : El factorial del numero.
*/

long long factorial (int numero);

long long factorial (int numero){
    long long resultado = 1;

    for (int i = 1; i <= numero; i++){
        resultado = resultado * i;
    }

    return resultado;
}

int main (void){
    int numero;
    long long resultado;

    printf("ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    resultado = factorial(numero);

    printf("El factorial de %d es: %lld\n", numero, resultado);

    if (resultado % 2 == 0){
        printf("el resultado es par. \n");
    }else{
        printf("el resultado es impar. \n");
    }
    return 0;
}
