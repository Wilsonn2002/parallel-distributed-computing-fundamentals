/*
 ============================================================================
 Archivo        : ejercicio_10_estudiantes.c
 Autor          : Wilson Alexander Silva Nova
 Descripción    : Programa para gestionar estudiantes utilizando structs,
                  punteros, arreglos dinamicos y funciones.
Fecha           : 13/09/2026
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define CANT_NOTAS 3
#define NOTA_APROBACION 3.0f

typedef struct {
    int id;
    char nombre[50];
    float notas[CANT_NOTAS];
} Estudiante;

/*
 * Funcion      : calcular_promedio
 * Descripcion  : Calcula el promedio de las notas de un estudiante.
 * Parametro    : estudiante - Puntero al estudiante.
 * Retorno      : Promedio de las notas.
 */
float calcular_promedio (Estudiante *estudiante);

float calcular_promedio (Estudiante *estudiante){
    float suma = 0;

    for (int i = 0; i < CANT_NOTAS; i++){
        suma += estudiante->notas[i];
    }

    return suma / CANT_NOTAS;
}

/*
 * Funcion      : mostrar_estudiante
 * Descripcion  : Muestra la informacion de un estudiante y su promedio.
 * Parametro    : estudiante - Puntero al estudiante.
 * Retorno      : No retorna ningun valor.
 */
void mostrar_estudiante (Estudiante *estudiante);

void mostrar_estudiante (Estudiante *estudiante){
    float promedio = calcular_promedio(estudiante);

    printf("ID: %d\n", estudiante->id);
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Promedio: %.2f\n", promedio);
}

/*
 * Funcion      : mostrar_aprobados
 * Descripcion  : Muestra los estudiantes que tienen promedio aprobatorio.
 * Parametro    : estudiantes - Puntero al arreglo de estudiantes.
 * Parametro    : cantidad - Cantidad de estudiantes.
 * Retorno      : No retorna ningun valor.
 */
void mostrar_aprobados (Estudiante *estudiantes, int cantidad);

void mostrar_aprobados (Estudiante *estudiantes, int cantidad){
    printf("\nEstudiantes aprobados:\n");

    for (int i = 0; i < cantidad; i++){
        float promedio = calcular_promedio(estudiantes + i);
        if (promedio >= NOTA_APROBACION){
            printf("%d - %s - %.2f\n",
                   (estudiantes + i)->id,
                   (estudiantes + i)->nombre,
                   promedio);
        }
    }
}

int main (void){
    int cantidad;

    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &cantidad);

    Estudiante *estudiantes =
        (Estudiante *) malloc(cantidad * sizeof(Estudiante));

    if (estudiantes == NULL){
        printf("Error al reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < cantidad; i++){
        printf("\nEstudiante %d\n", i + 1);

        printf("Ingrese el ID: ");
        scanf("%d", &(estudiantes + i)->id);

        printf("Ingrese el nombre: ");
        scanf(" %[^\n]", (estudiantes + i)->nombre);

        for (int j = 0; j < CANT_NOTAS; j++){
            printf("Ingrese la nota %d: ", j + 1);
            scanf("%f", &(estudiantes + i)->notas[j]);
        }
    }

    printf("\nInformacion de estudiantes:\n");

    for (int i = 0; i < cantidad; i++){
        printf("\n");
        mostrar_estudiante(estudiantes + i);
    }

    mostrar_aprobados(estudiantes, cantidad);

    free(estudiantes);

    return 0;
}