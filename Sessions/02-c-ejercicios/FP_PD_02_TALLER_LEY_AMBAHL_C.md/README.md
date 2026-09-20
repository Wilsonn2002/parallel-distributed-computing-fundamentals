# Taller Ley de Amdahl y Validación de Recursos

## Universidad de Pamplona

**Facultad de Ingenierías y Arquitectura**  
**Programa de Ingeniería de Sistemas**  
**Asignatura: Fundamentos de Computación Paralela y Distribuida**  
**Docente: Juan Alejandro Carrillo Jaimes**

---

# Introducción

El presente taller tiene como finalidad reforzar conceptos relacionados con
programación paralela, validación de recursos de hardware y aplicación de la
Ley de Amdahl.

A lo largo del desarrollo se realizarán diferentes pruebas utilizando los
recursos disponibles en el computador, con el propósito de identificar las
características del procesador, ejecutar programas secuenciales y paralelos,
medir sus tiempos de ejecución y posteriormente analizar el rendimiento
obtenido al utilizar diferentes cantidades de hilos.

Los resultados presentados corresponden a ejecuciones realizadas directamente
en el equipo utilizado para desarrollar el taller.

---

# Ejercicio 1. Identificación de Cores y Procesadores Lógicos

## Objetivo

Identificar la cantidad de núcleos físicos y procesadores lógicos disponibles
en la CPU del computador y comprender la diferencia entre ambos recursos.

El taller solicita consultar esta información mediante PowerShell para
determinar los valores correspondientes a `NumberOfCores` y
`NumberOfLogicalProcessors`.

---

## Comando utilizado

Para consultar las características del procesador se ejecutó el siguiente
comando en Windows PowerShell:

```powershell
Get-CimInstance Win32_Processor | Select-Object Name, NumberOfCores, NumberOfLogicalProcessors
```

---

## Resultado obtenido

La ejecución del comando produjo el siguiente resultado:

```text
Name                                      NumberOfCores NumberOfLogicalProcessors
----                                      ------------- -------------------------
Intel(R) Core(TM) i5-10210U CPU @ 1.60GHz      4                  8
```

Por lo tanto, las características encontradas en el equipo son:

- **Procesador:** Intel(R) Core(TM) i5-10210U CPU @ 1.60GHz
- **Número de núcleos físicos:** 4
- **Número de procesadores lógicos:** 8

---

## Interpretación de los resultados

El computador utilizado para realizar el taller posee un procesador
**Intel Core i5-10210U**, el cual dispone de **4 núcleos físicos** y
**8 procesadores lógicos**.

Los núcleos físicos corresponden a las unidades reales de procesamiento
presentes dentro del procesador. Cada núcleo tiene la capacidad de ejecutar
instrucciones y realizar operaciones de procesamiento.

Los procesadores lógicos, por otra parte, representan las unidades de
ejecución que el sistema operativo puede utilizar para administrar los hilos
de los programas.

En este caso, el sistema operativo reconoce 8 procesadores lógicos aunque
el procesador solamente posee 4 núcleos físicos.

Esto significa que cada núcleo físico puede trabajar con dos hilos de
ejecución.

---

## Hyper-Threading

La diferencia entre la cantidad de núcleos físicos y procesadores lógicos
se debe a la tecnología de multihilo disponible en el procesador.

En los procesadores Intel esta tecnología se conoce como
**Hyper-Threading**.

Hyper-Threading permite que un núcleo físico pueda gestionar más de un hilo
de ejecución, de manera que el sistema operativo puede aprovechar mejor los
recursos internos disponibles en cada núcleo.

En este equipo se tiene la siguiente relación:

```text
4 núcleos físicos
        ↓
2 hilos por núcleo
        ↓
8 procesadores lógicos
```

Por esta razón, Windows reconoce un total de 8 procesadores lógicos.

---

## Análisis

La presencia de 8 procesadores lógicos permite que el sistema pueda manejar
una mayor cantidad de hilos de ejecución de manera concurrente.

Sin embargo, es importante señalar que un procesador lógico no equivale a
tener un núcleo físico adicional.

Aunque el sistema reconoce 8 unidades lógicas de procesamiento, físicamente
el procesador sigue teniendo solamente 4 núcleos.

Por esta razón, ejecutar un programa utilizando 8 hilos no significa que su
rendimiento necesariamente será el doble del obtenido utilizando 4 hilos.

El rendimiento dependerá de diferentes factores, entre ellos:

- La cantidad de código que pueda ejecutarse en paralelo.
- La cantidad de hilos utilizados.
- La sobrecarga necesaria para crear y administrar los hilos.
- El uso de los recursos compartidos del procesador.
- La capacidad de los núcleos físicos.
- La eficiencia del programa paralelo.

Esta característica será especialmente importante en los siguientes
ejercicios, donde se compararán los tiempos de ejecución de un programa
secuencial con una versión paralela utilizando OpenMP.

También permitirá observar si aumentar progresivamente la cantidad de hilos
produce una reducción proporcional del tiempo de ejecución.

---

## Conclusión del Ejercicio 1

Mediante PowerShell fue posible identificar los recursos de procesamiento
disponibles en el equipo utilizado para desarrollar el taller.

El procesador **Intel Core i5-10210U** cuenta con **4 núcleos físicos** y
**8 procesadores lógicos**.

La existencia de un mayor número de procesadores lógicos se relaciona con
el uso de Hyper-Threading, tecnología que permite que cada núcleo físico
gestione más de un hilo de ejecución.

No obstante, disponer de 8 procesadores lógicos no equivale a disponer de
8 núcleos físicos. Por esta razón, el aumento en el número de hilos no
garantiza un incremento proporcional del rendimiento.

Esta información servirá como referencia para analizar posteriormente el
comportamiento del programa paralelo y los valores de speedup obtenidos
mediante la Ley de Amdahl.

---

# Ejercicio 2. Cálculo de Speedup Experimental

_Pendiente de desarrollo._