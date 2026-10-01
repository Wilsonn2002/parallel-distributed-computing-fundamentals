#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {

    int *vectorA;
    int *vectorB;

    long long producto_secuencial = 0;
    long long producto_paralelo = 0;

    double inicio, fin;
    double Ts, Tp;

    int hilos = 0;

    // Reservar memoria para los vectores
    vectorA = (int *)malloc(N * sizeof(int));
    vectorB = (int *)malloc(N * sizeof(int));

    if (vectorA == NULL || vectorB == NULL) {
        printf("Error al reservar memoria.\n");

        free(vectorA);
        free(vectorB);

        return 1;
    }

    // Inicializar vectores
    for (int i = 0; i < N; i++) {
        vectorA[i] = 1;
        vectorB[i] = 2;
    }

    printf("=== EJERCICIO 7: PRODUCTO ESCALAR CON OPENMP ===\n\n");

    printf("Tamano de los vectores: %d elementos\n\n", N);

    // ==================================================
    // VERSION SECUENCIAL
    // ==================================================

    inicio = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        producto_secuencial +=
            (long long)vectorA[i] * vectorB[i];
    }

    fin = omp_get_wtime();

    Ts = fin - inicio;

    // ==================================================
    // MOSTRAR HILOS PARTICIPANTES
    // Esta parte NO se incluye en el tiempo paralelo
    // ==================================================

    printf("HILOS PARTICIPANTES\n");
    printf("-----------------------------------\n");

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        #pragma omp single
        {
            hilos = omp_get_num_threads();

            printf("Numero total de hilos: %d\n", hilos);
        }

        #pragma omp critical
        {
            printf("Hilo %d activo\n", id);
        }
    }

    // ==================================================
    // VERSION PARALELA
    // ==================================================

    inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:producto_paralelo)
    for (int i = 0; i < N; i++) {

        producto_paralelo +=
            (long long)vectorA[i] * vectorB[i];
    }

    fin = omp_get_wtime();

    Tp = fin - inicio;

    // ==================================================
    // METRICAS DE RENDIMIENTO
    // ==================================================

    double speedup = Ts / Tp;

    double eficiencia =
        (speedup / hilos) * 100.0;

    // ==================================================
    // RESULTADOS
    // ==================================================

    printf("\nRESULTADOS\n");
    printf("-----------------------------------\n");

    printf("Producto secuencial = %lld\n",
           producto_secuencial);

    printf("Producto paralelo   = %lld\n\n",
           producto_paralelo);

    printf("Numero de hilos = %d\n", hilos);

    printf("Ts = %.9f segundos\n", Ts);

    printf("Tp = %.9f segundos\n", Tp);

    printf("Speedup experimental = %.4f\n",
           speedup);

    printf("Eficiencia = %.2f %%\n",
           eficiencia);

    // Liberar memoria
    free(vectorA);
    free(vectorB);

    return 0;
}