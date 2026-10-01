#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500

int main() {

    int **A;
    int **B;
    long long **C_secuencial;
    long long **C_paralela;

    double inicio, fin;
    double Ts, Tp;

    int hilos = 0;

    // ==================================================
    // RESERVA DE MEMORIA
    // ==================================================

    A = (int **)malloc(N * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));

    C_secuencial = (long long **)malloc(N * sizeof(long long *));
    C_paralela = (long long **)malloc(N * sizeof(long long *));

    if (A == NULL || B == NULL ||
        C_secuencial == NULL || C_paralela == NULL) {

        printf("Error al reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {

        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));

        C_secuencial[i] =
            (long long *)malloc(N * sizeof(long long));

        C_paralela[i] =
            (long long *)malloc(N * sizeof(long long));
    }

    // ==================================================
    // INICIALIZAR MATRICES
    // ==================================================

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            A[i][j] = 1;
            B[i][j] = 1;

            C_secuencial[i][j] = 0;
            C_paralela[i][j] = 0;
        }
    }

    printf("=== EJERCICIO 8: MULTIPLICACION DE MATRICES CON OPENMP ===\n\n");

    printf("Tamano de las matrices: %d x %d\n\n", N, N);

    // ==================================================
    // VERSION SECUENCIAL
    // ==================================================

    inicio = omp_get_wtime();

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            long long suma = 0;

            for (int k = 0; k < N; k++) {

                suma +=
                    (long long)A[i][k] * B[k][j];
            }

            C_secuencial[i][j] = suma;
        }
    }

    fin = omp_get_wtime();

    Ts = fin - inicio;

    // ==================================================
    // MOSTRAR HILOS PARTICIPANTES
    // No se incluye dentro de Tp
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

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            long long suma = 0;

            for (int k = 0; k < N; k++) {

                suma +=
                    (long long)A[i][k] * B[k][j];
            }

            C_paralela[i][j] = suma;
        }
    }

    fin = omp_get_wtime();

    Tp = fin - inicio;

    // ==================================================
    // VERIFICAR RESULTADOS
    // ==================================================

    int correcto = 1;

    for (int i = 0; i < N && correcto; i++) {

        for (int j = 0; j < N; j++) {

            if (C_secuencial[i][j] != C_paralela[i][j]) {

                correcto = 0;
                break;
            }
        }
    }

    // ==================================================
    // METRICAS
    // ==================================================

    double speedup = Ts / Tp;

    double eficiencia =
        (speedup / hilos) * 100.0;

    // ==================================================
    // RESULTADOS
    // ==================================================

    printf("\nRESULTADOS\n");
    printf("-----------------------------------\n");

    printf("Valor C[0][0] secuencial = %lld\n",
           C_secuencial[0][0]);

    printf("Valor C[0][0] paralelo   = %lld\n\n",
           C_paralela[0][0]);

    if (correcto) {
        printf("Verificacion: RESULTADOS IGUALES\n\n");
    }
    else {
        printf("Verificacion: ERROR EN LOS RESULTADOS\n\n");
    }

    printf("Numero de hilos = %d\n", hilos);

    printf("Ts = %.9f segundos\n", Ts);

    printf("Tp = %.9f segundos\n", Tp);

    printf("Speedup experimental = %.4f\n",
           speedup);

    printf("Eficiencia = %.2f %%\n",
           eficiencia);

    // ==================================================
    // LIBERAR MEMORIA
    // ==================================================

    for (int i = 0; i < N; i++) {

        free(A[i]);
        free(B[i]);

        free(C_secuencial[i]);
        free(C_paralela[i]);
    }

    free(A);
    free(B);

    free(C_secuencial);
    free(C_paralela);

    return 0;
}