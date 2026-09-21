# Taller Ley de Amdahl y Validación de Recursos

## Universidad de Pamplona

**Facultad de Ingenierías y Arquitectura**  
**Programa de Ingeniería de Sistemas**  
**Asignatura: Fundamentos de Computación Paralela y Distribuida**  
**Docente: Juan Alejandro Carrillo Jaimes**

---

## Descripción

Este repositorio contiene el desarrollo del taller relacionado con la
**Ley de Amdahl y la validación de recursos de hardware**.

El objetivo del taller es analizar el comportamiento de aplicaciones
secuenciales y paralelas mediante la identificación de los recursos
disponibles en el procesador, la medición de tiempos de ejecución y el
cálculo del speedup obtenido al utilizar diferentes cantidades de hilos.

Para las pruebas prácticas se utilizan programas escritos en lenguaje C
y paralelización mediante OpenMP.

---

## Contenido del taller

El taller se encuentra dividido en cinco ejercicios:

### Ejercicio 1
**Identificación de Cores y Procesadores Lógicos**

Se identifican los núcleos físicos y los procesadores lógicos disponibles
en el equipo utilizado para realizar las pruebas.

### Ejercicio 2
**Cálculo de Speedup Experimental**

Se comparan los tiempos de ejecución de una versión secuencial y una
versión paralela de un programa de búsqueda de números primos.

### Ejercicio 3
**Estimación de la Fracción Paralelizable**

Se utiliza la Ley de Amdahl para estimar qué porcentaje del programa
puede ejecutarse de manera paralela.

### Ejercicio 4
**Predicción Teórica del Speedup**

Se calcula el speedup teórico para diferentes cantidades de hilos
utilizando una fracción paralelizable determinada.

### Ejercicio 5
**Comparación Práctica vs. Teórica**

Se comparan los resultados experimentales obtenidos en la ejecución
del programa con los valores teóricos predichos mediante la Ley de Amdahl.

---

## Estructura del repositorio

```text
FP_PD_02_TALLER_LEY_AMDAHL_Cmd/
│
├── README.md
│
├── Ejercicio_01/
│   ├── README.md
│   └── evidencia_cpu.png
│
├── Ejercicio_02/
│   └── README.md
│
├── Ejercicio_03/
│   └── README.md
│
├── Ejercicio_04/
│   └── README.md
│
├── Ejercicio_05/
│   └── README.md
│
├── primes_number_parallel.c
└── primes_number_sequential.c
```

---

## Código fuente utilizado

Los programas utilizados para realizar las pruebas se encuentran
desarrollados en lenguaje C.

### Programa secuencial

`primes_number_sequential.c`

Este programa realiza una búsqueda de números primos utilizando una
ejecución secuencial.

### Programa paralelo

`primes_number_parallel.c`

Este programa utiliza OpenMP para distribuir el ciclo de búsqueda de
números primos entre múltiples hilos de ejecución.

---

## Herramientas utilizadas

- Visual Studio Code
- GCC
- OpenMP
- Windows PowerShell
- Git
- GitHub

---

## Entregable final

El desarrollo completo del taller será consolidado posteriormente en un
único archivo PDF que incluirá:

- Desarrollo y explicación de cada ejercicio.
- Capturas de pantalla de las ejecuciones.
- Resultados experimentales.
- Cálculos realizados.
- Tablas y gráficas.
- Comparación entre speedup teórico y experimental.
- Enlace al repositorio donde se encuentra alojado el código fuente.

---

## Nota

En este repositorio se almacenan únicamente archivos de código fuente,
documentación y evidencias necesarias para el desarrollo del taller.

No se incluyen archivos ejecutables o binarios generados durante la
compilación.