/*
 ============================================================================
 Archivo        : ejercicio_08_notas_calificaciones.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa que asigna una calificacion de letra a partir
                  de una nota numerica.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>

int main (void){
    float nota;
    char calificacion;

    printf("Ingrese la nota (0 - 5.0): ");
    scanf("%f", &nota);

    if (nota < 0 || nota > 5.0f){
        printf("La nota ingresada no es valida.\n");
        return 0;
    }

    if (nota >= 4.5f){
        calificacion = 'A';
    } else if (nota >= 4.0f){
        calificacion = 'B';
    } else if (nota >= 3.0f){
        calificacion = 'C';
    } else if (nota >= 2.0f){
        calificacion = 'D';
    } else {
        calificacion = 'F';
    }

    printf("Calificacion: %c\n", calificacion);

    return 0;
}