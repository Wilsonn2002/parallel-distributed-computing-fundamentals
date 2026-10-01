#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {

    int *arreglo;

    long long suma_secuencial = 0;
    long long suma_paralela = 0;

    double inicio, fin;
    double Ts, Tp;

    int hilos;

    // Reservar memoria
    arreglo = (int *)malloc(N * sizeof(int));

    if (arreglo == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Inicializar arreglo con valor 1
    for (int i = 0; i < N; i++) {
        arreglo[i] = 1;
    }

    printf("=== EJERCICIO 6: SUMA DE ARREGLO CON OPENMP ===\n\n");
    printf("Tamano del arreglo: %d elementos\n\n", N);

    // ==========================
    // VERSION SECUENCIAL
    // ==========================

    inicio = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        suma_secuencial += arreglo[i];
    }

    fin = omp_get_wtime();

    Ts = fin - inicio;

    // ==========================
    // VERSION PARALELA
    // ==========================

    inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:suma_paralela)
    for (int i = 0; i < N; i++) {
        suma_paralela += arreglo[i];
    }

    fin = omp_get_wtime();

    Tp = fin - inicio;

    // Obtener numero de hilos
    #pragma omp parallel
    {
        #pragma omp single
        {
            hilos = omp_get_num_threads();
        }
    }

    // ==========================
    // METRICAS
    // ==========================

    double speedup = Ts / Tp;
    double eficiencia = (speedup / hilos) * 100.0;

    printf("RESULTADOS\n");
    printf("-----------------------------------\n");

    printf("Suma secuencial = %lld\n", suma_secuencial);
    printf("Suma paralela   = %lld\n\n", suma_paralela);

    printf("Numero de hilos = %d\n", hilos);

    printf("Ts = %.9f segundos\n", Ts);
    printf("Tp = %.9f segundos\n", Tp);

    printf("Speedup experimental = %.4f\n", speedup);
    printf("Eficiencia = %.2f %%\n", eficiencia);

    free(arreglo);

    return 0;
}