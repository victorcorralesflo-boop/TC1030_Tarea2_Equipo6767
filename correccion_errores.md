# TC1030 - Tarea 2: Sobrecarga de operadores y polimorfismo

## Integrantes

- Nombre completo 1
- Nombre completo 2

## Descripción

En esta tarea se aplican conceptos importantes de programación orientada a objetos en C++.  
La primera parte trabaja con sobrecarga de operadores, lo cual permite que clases propias utilicen operadores como `+`, `==`, `<<`, `++` y `=` de forma clara y natural.  

La segunda parte corresponde al Bloque B de polimorfismo, donde se implementa una clase `MatrixOp`, una función plantilla genérica `maxValue<T>()` y una interfaz `IMatrix` con el método virtual `determinant()`.

## Estructura del repositorio

```txt
TC1030_Tarea2_EquipoXX/
│
├── README.md
├── Makefile
│
├── include/
│   ├── Complejo.h
│   ├── Punto.h
│   ├── Empleado.h
│   ├── Contador.h
│   ├── Buffer.h
│   ├── IMatrix.h
│   ├── MatrixOp.h
│   └── TemplateUtils.h
│
├── src/
│   ├── main_sobrecarga.cpp
│   └── main_polimorfismo.cpp
│
├── tests/
│   └── pruebas_minimas.cpp
│
└── docs/
    ├── evidencia_ejecucion.md
    ├── correccion_errores.md
    └── diagrama_clases.md
```

## Parte 1: Sobrecarga de operadores

| Concepto | Operador | Clase implementada | Descripción |
|---|---|---|---|
| Operador binario | `+` | `Complejo` | Suma dos números complejos componente por componente. |
| Comparación | `==` | `Punto` | Compara si dos puntos tienen las mismas coordenadas. |
| Salida a consola | `<<` | `Empleado` | Permite imprimir un empleado directamente con `cout`. |
| Post-incremento | `++` | `Contador` | Incrementa el valor del contador después de devolver el valor anterior. |
| Asignación | `=` | `Buffer` | Copia correctamente el contenido de un buffer usando copia profunda. |

## Parte 2: Polimorfismo - Bloque B

### B1: Sobrecarga de operadores en MatrixOp

Se agregaron los operadores `operator+` y `operator-` a la clase `MatrixOp`.  
Ambos operadores validan que las matrices tengan las mismas dimensiones y devuelven una nueva matriz resultado sin modificar las matrices originales.

### B2: Función plantilla genérica

Se implementó la función plantilla `maxValue<T>()`, que recibe un arreglo y su tamaño para devolver el valor máximo.  
La función valida que el arreglo no sea nulo y que el tamaño sea válido.

### B3: Herencia y métodos virtuales

Se creó la interfaz `IMatrix` con el método virtual puro `determinant()`.  
La clase `MatrixOp` hereda de `IMatrix` e implementa el cálculo del determinante, permitiendo usar polimorfismo mediante un apuntador `IMatrix*`.

## Instrucciones de compilación y ejecución

### Compilar todo con Makefile

```bash
make
```

### Ejecutar Parte 1

En Windows:

```bash
./sobrecarga.exe
```

En Mac/Linux:

```bash
./sobrecarga
```

### Ejecutar Parte 2

En Windows:

```bash
./polimorfismo.exe
```

En Mac/Linux:

```bash
./polimorfismo
```

### Ejecutar pruebas mínimas

En Windows:

```bash
./pruebas.exe
```

En Mac/Linux:

```bash
./pruebas
```

### Compilación manual

```bash
g++ -std=c++20 src/main_sobrecarga.cpp -Iinclude -o sobrecarga
g++ -std=c++20 src/main_polimorfismo.cpp -Iinclude -o polimorfismo
g++ -std=c++20 tests/pruebas_minimas.cpp -Iinclude -o pruebas
```

## Evidencia de ejecución

La evidencia se encuentra documentada en:

```txt
docs/evidencia_ejecucion.md
```

## Corrección de errores

La documentación de errores corregidos se encuentra en:

```txt
docs/correccion_errores.md
```

## Diagrama de clases

El diagrama de clases de la parte de polimorfismo se encuentra en:

```txt
docs/diagrama_clases.md
```

## Reflexión del equipo

En esta tarea aprendimos que la sobrecarga de operadores ayuda a que las clases sean más expresivas y fáciles de usar. También comprendimos que el polimorfismo permite diseñar programas más flexibles, ya que una clase puede ser utilizada mediante una interfaz común.

Lo más retador fue validar correctamente los casos de error, especialmente en la asignación con copia profunda y en las operaciones entre matrices. Dividimos el trabajo separando la parte de sobrecarga de operadores y la parte de polimorfismo, además de documentar la evidencia y las pruebas mínimas.

## Checklist final

- [x] Código fuente completo.
- [x] README profesional.
- [x] Evidencia de ejecución.
- [x] Pruebas mínimas.
- [x] Diagrama de clases.
- [x] Documentación de corrección de errores.
- [ ] Participación visible de ambos integrantes mediante commits.
