# Ejercicio 4. Predicción Teórica del Speedup

## Objetivo

Calcular el speedup teórico de un programa utilizando la Ley de Amdahl para
diferentes cantidades de hilos, considerando una fracción paralelizable de:

```text
P = 0.85
```

Además, se determina el límite máximo teórico de speedup cuando el número de
procesadores tiende a infinito.

---

## Fórmula utilizada

La Ley de Amdahl permite calcular el speedup teórico mediante:

```text
S(N) = 1 / [(1 - P) + (P / N)]
```

Donde:

- `S(N)` = speedup teórico.
- `P` = fracción paralelizable.
- `N` = número de hilos o procesadores.

Para este ejercicio:

```text
P = 0.85
```

---

## Cálculo para N = 1

```text
S(1) = 1 / [(1 - 0.85) + (0.85 / 1)]
```

```text
S(1) = 1 / [0.15 + 0.85]
```

```text
S(1) = 1
```

---

## Cálculo para N = 2

```text
S(2) = 1 / [(1 - 0.85) + (0.85 / 2)]
```

```text
S(2) = 1 / [0.15 + 0.425]
```

```text
S(2) = 1 / 0.575
```

```text
S(2) ≈ 1.739
```

---

## Cálculo para N = 4

```text
S(4) = 1 / [(1 - 0.85) + (0.85 / 4)]
```

```text
S(4) = 1 / [0.15 + 0.2125]
```

```text
S(4) = 1 / 0.3625
```

```text
S(4) ≈ 2.759
```

---

## Cálculo para N = 6

```text
S(6) = 1 / [(1 - 0.85) + (0.85 / 6)]
```

```text
S(6) = 1 / [0.15 + 0.1417]
```

```text
S(6) ≈ 3.429
```

---

## Cálculo para N = 12

```text
S(12) = 1 / [(1 - 0.85) + (0.85 / 12)]
```

```text
S(12) = 1 / [0.15 + 0.0708]
```

```text
S(12) ≈ 4.528
```

---

## Resultados teóricos

| Número de hilos N | Speedup teórico |
|---:|---:|
| 1 | 1.000 |
| 2 | 1.739 |
| 4 | 2.759 |
| 6 | 3.429 |
| 12 | 4.528 |

---

## Límite máximo teórico

El límite máximo de speedup se obtiene cuando el número de procesadores tiende
a infinito:

```text
S∞ = 1 / (1 - P)
```

Sustituyendo:

```text
S∞ = 1 / (1 - 0.85)
```

```text
S∞ = 1 / 0.15
```

```text
S∞ ≈ 6.67
```

Por lo tanto, incluso utilizando una cantidad idealmente infinita de
procesadores, el speedup máximo teórico sería aproximadamente:

**S∞ ≈ 6.67**

---

## Evidencia del cálculo

La siguiente captura muestra los cálculos realizados en PowerShell:

![Evidencia del cálculo teórico](evidencia_ejercicio_04_sppedup_teorico.png)

---

## Análisis

Los resultados muestran que el incremento en el número de hilos mejora el
speedup teórico, pero esta mejora no es lineal.

Por ejemplo:

- Con 2 hilos se obtiene un speedup aproximado de 1.739.
- Con 4 hilos se obtiene aproximadamente 2.759.
- Con 6 hilos se alcanza aproximadamente 3.429.
- Con 12 hilos se obtiene aproximadamente 4.528.

Aunque el número de hilos aumenta, el rendimiento adicional obtenido en cada
incremento es cada vez menor.

Este comportamiento ocurre porque el 15 % del programa no puede
paralelizarse:

```text
1 - P = 1 - 0.85 = 0.15
```

Por tanto:

```text
Fracción secuencial = 15 %
```

Esta fracción secuencial establece un límite al speedup total.

Incluso con una cantidad infinita de procesadores, el speedup máximo no puede
superar aproximadamente 6.67.

Esto evidencia uno de los principios fundamentales de la Ley de Amdahl: la
parte secuencial de un programa limita la aceleración máxima alcanzable.

---

## Conclusión

Aplicando la Ley de Amdahl con una fracción paralelizable de:

```text
P = 0.85
```

se calcularon los speedups teóricos para diferentes cantidades de hilos.

Los resultados fueron:

```text
N = 1   → S = 1.000
N = 2   → S = 1.739
N = 4   → S = 2.759
N = 6   → S = 3.429
N = 12  → S = 4.528
```

Además, el límite máximo teórico fue:

```text
S∞ ≈ 6.67
```

Esto demuestra que, aunque se aumente indefinidamente la cantidad de
procesadores, la presencia de una fracción secuencial del 15 % impide que el
speedup crezca de manera ilimitada.