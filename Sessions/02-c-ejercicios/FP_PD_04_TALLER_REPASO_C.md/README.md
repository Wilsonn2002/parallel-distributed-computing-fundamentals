# Taller Repaso C Pointers + OpenMP Basics

## Universidad de Pamplona
**Facultad de Ingenierías y Arquitectura**  
**Programa de Ingeniería de Sistemas**  
**Asignatura:** Fundamentos de Computación Paralela y Distribuida  
**Docente:** Juan Alejandro Carrillo Jaimes  

---

## Descripción

Este repositorio contiene el desarrollo del taller de repaso sobre programación en C, manejo de punteros y fundamentos básicos de paralelización mediante OpenMP.

El taller se divide en dos partes:

- Parte I: ejercicios orientados al uso de punteros, aritmética de punteros, punteros dobles y manipulación de memoria.
- Parte II: ejercicios secuenciales y paralelos implementados con OpenMP, incluyendo medición de tiempos y análisis de rendimiento.

---

# Parte I - Ejercicios con punteros en C

## Ejercicio 1 - Acceso a elementos de un arreglo con punteros

Se declara un arreglo de 10 enteros con valores del 1 al 10.

Los elementos se recorren mediante aritmética de punteros utilizando:

`*(ptr + i)`

El objetivo es acceder a los valores del arreglo mediante punteros.

---

## Ejercicio 2 - Suma de elementos usando punteros

Se implementa la suma de los elementos de un arreglo mediante un puntero.

La operación utilizada es:

`suma += *(ptr + i);`

Para el arreglo:

`1 2 3 4 5 6 7 8 9 10`

el resultado obtenido es:

`Suma final = 55`

---

## Ejercicio 3 - Matrices y punteros a punteros

Se implementa una matriz dinámica de tamaño 3 x 3 utilizando:

`int **matriz;`

La memoria se reserva dinámicamente mediante `malloc()`.

El acceso a cada posición se realiza utilizando:

`*(*(matriz + i) + j)`

La matriz utilizada contiene:

1 2 3  
4 5 6  
7 8 9  

Al finalizar se libera la memoria mediante `free()`.

---

## Ejercicio 4 - Intercambio de valores con punteros

Se implementa la función:

`void swap(int *a, int *b)`

La función recibe las direcciones de memoria de dos variables y modifica directamente sus valores.

Ejemplo:

Antes del intercambio:

Numero 1 = 10  
Numero 2 = 20  

Después del intercambio:

Numero 1 = 20  
Numero 2 = 10  

---

## Ejercicio 5 - Cadena de caracteres con punteros

Se declara una cadena de caracteres y se recorre mediante un puntero.

Por cada carácter se muestra:

- El carácter.
- Su dirección de memoria.

El puntero avanza mediante:

`ptr++;`

hasta encontrar el carácter nulo:

`'\0'`

---

# Parte II - Ejercicios paralelos con OpenMP

Los ejercicios de esta sección fueron implementados primero de manera secuencial y luego en paralelo mediante OpenMP.

Para las mediciones de tiempo se utilizó:

`omp_get_wtime()`

Las métricas de rendimiento utilizadas fueron:

Tiempo secuencial:

`Ts`

Tiempo paralelo:

`Tp`

Speedup experimental:

`Speedup = Ts / Tp`

Eficiencia:

`Eficiencia = (Speedup / P) * 100`

donde `P` representa el número de hilos utilizados.

En las pruebas se utilizaron 8 hilos.

---

# Ejercicio 6 - Suma de un arreglo en paralelo

Se utilizó un arreglo de:

`N = 1,000,000 elementos`

Todos los elementos fueron inicializados con valor 1.

La versión paralela se implementó utilizando:

`#pragma omp parallel for reduction(+:suma_paralela)`

El resultado de ambas versiones fue:

`Suma = 1,000,000`

## Resultados experimentales

| Ejecución | Ts (s) | Tp (s) | Speedup | Eficiencia |
|---|---:|---:|---:|---:|
| 1 | 0.003000021 | 0.001999855 | 1.5001 | 18.75 % |
| 2 | 0.001999855 | 0.001000166 | 1.9995 | 24.99 % |
| 3 | 0.003000021 | 0.000999928 | 3.0002 | 37.50 % |

Promedios aproximados:

- Ts promedio = 0.002667 s
- Tp promedio = 0.001333 s
- Speedup promedio = 2.17
- Eficiencia promedio = 27.08 %

---

# Ejercicio 7 - Producto escalar de dos vectores

Se utilizaron dos vectores de:

`N = 1,000,000 elementos`

Los vectores fueron inicializados así:

- Vector A = 1
- Vector B = 2

El producto escalar esperado fue:

`2,000,000`

La implementación paralela utiliza `reduction`.

También se utilizaron:

`omp_get_thread_num()`

y

`omp_get_num_threads()`

para mostrar los hilos participantes.

## Resultados experimentales

| Ejecución | Ts (s) | Tp (s) | Speedup | Eficiencia |
|---|---:|---:|---:|---:|
| 1 | 0.003000021 | 0.001000166 | 2.9995 | 37.49 % |
| 2 | 0.002000093 | 0.001000166 | 1.9998 | 25.00 % |
| 3 | 0.003000021 | 0.001000166 | 2.9995 | 37.49 % |

Promedios aproximados:

- Ts promedio = 0.002667 s
- Tp promedio = 0.001000 s
- Speedup promedio = 2.67
- Eficiencia promedio = 33.33 %

---

# Ejercicio 8 - Multiplicación de matrices en paralelo

Se utilizaron dos matrices cuadradas de tamaño:

`500 x 500`

Ambas matrices fueron inicializadas con valores iguales a 1.

La versión paralela utiliza:

`#pragma omp parallel for`

El valor esperado de cada elemento de la matriz resultante es:

`500`

Se verificó:

- C[0][0] secuencial = 500
- C[0][0] paralelo = 500
- Resultados iguales

## Resultados experimentales

| Ejecución | Ts (s) | Tp (s) | Speedup | Eficiencia |
|---|---:|---:|---:|---:|
| 1 | 0.398000000 | 0.104000092 | 3.8269 | 47.84 % |
| 2 | 0.375999928 | 0.103999853 | 3.6154 | 45.19 % |
| 3 | 0.386000156 | 0.106999874 | 3.6075 | 45.09 % |

Promedios aproximados:

- Ts promedio = 0.386667 s
- Tp promedio = 0.105000 s
- Speedup promedio = 3.68
- Eficiencia promedio = 46.04 %

---

# Compilación

## Ejercicios de la Parte I

Ejemplo:

`gcc ejercicio1.c -o ejercicio1.exe`

Ejecución:

`.\ejercicio1.exe`

---

## Ejercicios con OpenMP

Para los ejercicios 6, 7 y 8 se utiliza:

`-fopenmp`

Ejemplo:

`gcc ejercicio6.c -o ejercicio6.exe -fopenmp`

Ejecución:

`.\ejercicio6.exe`

---

# Estructura del proyecto

FP_PD_04_TALLER_REPASO_C/

PARTE_1/
- ejercicio1.c
- ejercicio2.c
- ejercicio3.c
- ejercicio4.c
- ejercicio5.c

PARTE_2/
- ejercicio6.c
- ejercicio7.c
- ejercicio8.c

README.md

---

# Conclusiones

Los ejercicios permitieron reforzar el uso de punteros y aritmética de punteros en lenguaje C, incluyendo acceso a arreglos, matrices dinámicas, intercambio de variables y recorrido de cadenas.

La implementación con OpenMP permitió comparar algoritmos secuenciales y paralelos mediante mediciones experimentales de tiempo.

En todos los ejercicios paralelos se verificó que las versiones secuenciales y paralelas produjeran los mismos resultados.

El mayor beneficio de paralelización se observó en la multiplicación de matrices, ya que este problema presenta una carga computacional mayor.

Las mediciones también muestran que utilizar varios hilos no implica alcanzar una eficiencia del 100 %, debido a costos asociados con creación, coordinación y sincronización de los hilos.

---

# Autor

**Wilson Alexander Silva Nova**  
Ingeniería de Sistemas  
Universidad de Pamplona