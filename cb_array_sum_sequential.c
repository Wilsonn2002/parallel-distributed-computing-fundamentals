/**
 * @file cb_array_sum_sequential.c
 * @brief Sums the elements of a dynamic array using pointer arithmetic
 * @author Wilson Nova
 * @date 2026-09-21
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 2000000000



long long sum_pointers_array(int *arr, int size) {

    long long total_sum = 0;

    for (int i = 0; i < size; i++) {
        total_sum += *(arr + i);
    }

    return total_sum;
}



void fill_array(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        *(arr + i) = i % 100;
    }

}



/*
void print_array(int *arr, int size) {

    printf("[");

    for (int i = 0; i < size; i++) {

        if (i == size - 1) {
            printf("%d]", *(arr + i));
            break;
        }

        printf("%d, ", *(arr + i));
    }

}
*/



int main() {


    // 1. Create array with dynamic memory

    int size = N;

    int *arr = (int *) malloc(size * sizeof(int));



    // 2. Check if the pointer is not null

    if (arr == NULL) {

        printf("No hay suficiente memoria, para N = %d\n", size);

        return 1;

    }



    // 3. Fill array

    fill_array(arr, size);



    // 4. Return total sum of array

    clock_t start_time = clock();


    long long total_sum = sum_pointers_array(arr, size);



    // 5. Measurement time

    double elapsed_time =
        (double)(clock() - start_time) / CLOCKS_PER_SEC;



    // 6. Print results

    printf("Total Sum: %lld\n", total_sum);

    printf("Size: %d\n", size);

    printf("Sequential time: %.3fs\n", elapsed_time);



    // 7. Free memory

    free(arr);


    return 0;

}