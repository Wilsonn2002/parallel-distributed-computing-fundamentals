# Ejercicio 2. Cálculo de Speedup Experimental

## Objetivo

Ejecutar un programa de búsqueda de números primos en versión secuencial
y paralela con el propósito de comparar sus tiempos de ejecución y calcular
el speedup experimental obtenido mediante paralelización con OpenMP.

El speedup permite determinar cuántas veces más rápida resulta la ejecución
paralela respecto a la ejecución secuencial.

---

## Programas utilizados

Para desarrollar este ejercicio se utilizaron dos programas escritos en
lenguaje C:

- `primes_number_sequential.c`
- `primes_number_parallel.c`

Ambos programas realizan la misma tarea: buscar y contar números primos
dentro de un rango determinado.

Para garantizar que la comparación sea válida, ambos programas fueron
configurados con el mismo límite de búsqueda:

```c
#define N 50000
```

De esta manera, la versión secuencial y la versión paralela procesan
exactamente el mismo rango de números.

---

## Versión secuencial

La versión secuencial realiza la búsqueda de números primos utilizando un
único flujo de ejecución.

Para compilar el programa se ejecutó:

```powershell
gcc primes_number_sequential.c -o sequential.exe
```

Posteriormente se ejecutó mediante:

```powershell
./sequential.exe
```

### Resultado obtenido

```text
Primes found: 5133
Sequential Time: 0.013 s
```

Por lo tanto, el tiempo de ejecución secuencial registrado fue:

```text
Ts = 0.013 s
```

---

## Versión paralela

La versión paralela utiliza OpenMP para distribuir las iteraciones del ciclo
entre varios hilos de ejecución.

La paralelización se realiza mediante la siguiente directiva:

```c
#pragma omp parallel for reduction(+:counterPrimes)
```

El programa paralelo se compiló mediante:

```powershell
gcc primes_number_parallel.c -o parallel.exe -fopenmp
```

Para esta prueba se configuraron 12 hilos de ejecución:

```powershell
$env:OMP_NUM_THREADS=12
```

Posteriormente se ejecutó:

```powershell
./parallel.exe
```

### Resultado obtenido

```text
Primes found: 5133
Parallel Time: 0.005 s
```

Por lo tanto:

```text
Tp = 0.005 s
```

---

## Evidencia de ejecución

La siguiente captura muestra la compilación y ejecución de las versiones
secuencial y paralela del programa:

![Evidencia de ejecución secuencial y paralela](Evidencia_Powershell2.docx)

---

## Datos experimentales

| Parámetro | Resultado |
|---|---:|
| Límite de búsqueda `N` | 50000 |
| Números primos encontrados | 5133 |
| Tiempo secuencial `Ts` | 0.013 s |
| Número de hilos utilizados | 12 |
| Tiempo paralelo `Tp` | 0.005 s |

---

## Cálculo del Speedup Experimental

El speedup experimental se calcula mediante:

```text
S = Ts / Tp
```

Donde:

- `S` = speedup experimental.
- `Ts` = tiempo de ejecución secuencial.
- `Tp` = tiempo de ejecución paralelo.

Sustituyendo los valores experimentales:

```text
S = 0.013 / 0.005
```

Por lo tanto:

```text
S = 2.60
```

El speedup experimental obtenido fue:

**S = 2.60**

---

## Interpretación del resultado

El resultado indica que, en esta ejecución, el programa paralelo utilizando
12 hilos fue aproximadamente **2.6 veces más rápido** que la versión
secuencial.

En ambos casos se encontraron exactamente:

```text
5133 números primos
```

Esto confirma que la paralelización no modificó el resultado del algoritmo,
sino únicamente la forma en la que se distribuye el trabajo.

La reducción del tiempo de ejecución se debe al uso de OpenMP, que permite
distribuir las iteraciones del ciclo de búsqueda entre varios hilos.

---

## Análisis

El tiempo de ejecución disminuyó de:

```text
0.013 s
```

en la versión secuencial a:

```text
0.005 s
```

en la versión paralela utilizando 12 hilos.

Aunque se utilizaron 12 hilos, el speedup experimental fue solamente de 2.60.
Esto demuestra que aumentar la cantidad de hilos no produce necesariamente
una aceleración proporcional.

Existen diferentes factores que pueden explicar este comportamiento:

- La sobrecarga generada por la creación y administración de los hilos.
- La existencia de operaciones que no pueden ejecutarse de manera paralela.
- La cantidad limitada de núcleos físicos disponibles.
- El uso compartido de recursos entre los procesadores lógicos.
- La planificación realizada por el sistema operativo.
- La pequeña duración total de la ejecución.

El procesador utilizado en este taller dispone de 4 núcleos físicos y
8 procesadores lógicos. Sin embargo, en esta prueba se utilizaron 12 hilos.

Esto significa que la cantidad de hilos solicitados es superior al número de
procesadores lógicos disponibles en el equipo. Por esta razón, varios hilos
deben compartir los mismos recursos de procesamiento y ser administrados por
el sistema operativo.

Además, los tiempos registrados son del orden de milisegundos. Cuando una
ejecución es tan corta, pequeñas variaciones en la carga del sistema,
procesos en segundo plano o la planificación del sistema operativo pueden
generar diferencias apreciables entre distintas ejecuciones.

Por esta razón, no debe esperarse que todas las ejecuciones produzcan
exactamente los mismos tiempos.

---

## Conclusión

La ejecución de las versiones secuencial y paralela permitió calcular el
speedup experimental del programa de búsqueda de números primos.

La versión secuencial registró:

```text
Ts = 0.013 s
```

mientras que la versión paralela utilizando 12 hilos registró:

```text
Tp = 0.005 s
```

Aplicando la expresión:

```text
S = Ts / Tp
```

se obtuvo:

```text
S = 2.60
```

Por lo tanto, en la ejecución registrada, la versión paralela fue
aproximadamente **2.6 veces más rápida** que la versión secuencial.

El resultado también evidencia que el incremento en el número de hilos no
genera necesariamente una mejora proporcional del rendimiento debido a las
limitaciones físicas del procesador, la sobrecarga del paralelismo y la
distribución de recursos entre los hilos.

Este valor de speedup será utilizado posteriormente para estimar la fracción
paralelizable del programa mediante la Ley de Amdahl.