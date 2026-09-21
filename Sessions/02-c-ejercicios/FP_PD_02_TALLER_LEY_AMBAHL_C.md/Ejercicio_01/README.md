# Ejercicio 1. Identificación de Cores y Procesadores Lógicos

## Objetivo

Identificar la cantidad de núcleos físicos y procesadores lógicos
disponibles en el procesador del equipo utilizado para desarrollar el
taller.

También se busca comprender la diferencia entre ambos recursos y analizar
el efecto del uso de tecnologías de procesamiento multihilo.

---

## Procedimiento

Para consultar las características del procesador se ejecutó el siguiente
comando en Windows PowerShell:

```powershell
Get-CimInstance Win32_Processor | Select-Object Name, NumberOfCores, NumberOfLogicalProcessors
```

Este comando permite obtener:

- Nombre del procesador.
- Número de núcleos físicos.
- Número de procesadores lógicos.

---

## Resultado obtenido

La ejecución del comando produjo el siguiente resultado:

```text
Name                                      NumberOfCores NumberOfLogicalProcessors
----                                      ------------- -------------------------
Intel(R) Core(TM) i5-10210U CPU @ 1.60GHz      4                  8
```

Por lo tanto, el equipo utilizado presenta las siguientes características:

| Característica | Resultado |
|---|---:|
| Procesador | Intel Core i5-10210U |
| Frecuencia indicada | 1.60 GHz |
| Núcleos físicos | 4 |
| Procesadores lógicos | 8 |

---

## Evidencia de ejecución

La siguiente captura muestra el resultado obtenido directamente desde
Windows PowerShell:

![Evidencia de identificación del procesador](Evidencia_Powershell.docx)

---

## Análisis

El procesador utilizado para realizar las pruebas es un
**Intel Core i5-10210U**, el cual dispone de **4 núcleos físicos** y
**8 procesadores lógicos**.

Los núcleos físicos corresponden a las unidades reales de procesamiento
presentes en la CPU. Cada núcleo tiene la capacidad de ejecutar instrucciones
y procesar tareas.

Por otro lado, los procesadores lógicos representan las unidades de ejecución
que el sistema operativo puede utilizar para distribuir los diferentes hilos
de los programas.

En este caso existe una diferencia entre ambas cantidades:

```text
Núcleos físicos:       4
Procesadores lógicos:  8
```

Esto significa que el sistema puede manejar hasta dos hilos de ejecución
por cada núcleo físico.

En los procesadores Intel esta característica está asociada con la tecnología
**Hyper-Threading**.

Hyper-Threading permite que un núcleo físico pueda gestionar más de un hilo
de ejecución de forma concurrente, permitiendo aprovechar mejor algunos de
los recursos internos del procesador.

La relación presente en este equipo puede representarse de la siguiente
manera:

```text
4 núcleos físicos
       ↓
2 hilos por núcleo
       ↓
8 procesadores lógicos
```

Sin embargo, un procesador lógico no representa un núcleo físico adicional.

Por esta razón, aunque el sistema operativo pueda trabajar con 8 hilos, no
significa que el equipo tenga físicamente 8 núcleos.

Tampoco significa que utilizar 8 hilos vaya a generar automáticamente el
doble de rendimiento que utilizar 4.

El rendimiento de una aplicación paralela depende de factores como:

- La cantidad de código que puede paralelizarse.
- La cantidad de hilos utilizados.
- La sobrecarga generada por la creación y coordinación de los hilos.
- La disponibilidad de núcleos físicos.
- El uso compartido de recursos internos del procesador.
- La eficiencia del algoritmo utilizado.

Esta diferencia entre núcleos físicos y procesadores lógicos será relevante
en los siguientes ejercicios, especialmente cuando se comparen los tiempos
de ejecución obtenidos utilizando diferentes cantidades de hilos mediante
OpenMP.

---

## Interpretación

A partir de los resultados obtenidos puede establecerse que el procesador
dispone de capacidad para ejecutar múltiples hilos de manera concurrente.

Los 8 procesadores lógicos serán visibles para OpenMP y para el sistema
operativo como unidades disponibles para distribuir hilos.

Sin embargo, al existir únicamente 4 núcleos físicos, después de utilizar
estos recursos físicos los hilos adicionales deberán compartir algunos
recursos del procesador.

Por esta razón, en las pruebas posteriores no necesariamente se observará
una reducción lineal del tiempo de ejecución al aumentar el número de hilos.

---

## Conclusión

Mediante el comando ejecutado en Windows PowerShell se identificó que el
equipo utilizado para desarrollar el taller posee un procesador
**Intel Core i5-10210U**, compuesto por **4 núcleos físicos y
8 procesadores lógicos**.

La diferencia entre ambos valores se relaciona con el uso de
Hyper-Threading, que permite que cada núcleo físico gestione más de un
hilo de ejecución.

Esta característica permite incrementar el grado de concurrencia disponible
para aplicaciones paralelas. Sin embargo, los procesadores lógicos comparten
recursos de los núcleos físicos, por lo que aumentar el número de hilos no
garantiza un incremento proporcional del rendimiento.

Estos recursos serán utilizados posteriormente para evaluar el comportamiento
del programa paralelo y analizar los valores de speedup mediante la
Ley de Amdahl.