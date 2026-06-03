# Evidencia de ejecución

## Parte 1: Sobrecarga de operadores

Comando de compilación:

```bash
g++ -std=c++20 src/main_sobrecarga.cpp -Iinclude -o sobrecarga
```

Comando de ejecución:

```bash
./sobrecarga
```

Salida esperada:

```txt
=== Parte 1: Sobrecarga de operadores ===
Complejo operator+: (2 + 3i) + (4 - 1i) = (6 + 2i)
Punto operator== p1 == p2: true
Punto operator== p1 == p3: false
Empleado operator<<: Empleado[ID: 101, Nombre: Ana Lopez, Sueldo: $15000]
Contador operator++(int): antes = 7, despues = 8
Buffer operator=: Mundo
```

## Parte 2: Bloque B - Polimorfismo

Comando de compilación:

```bash
g++ -std=c++20 src/main_polimorfismo.cpp -Iinclude -o polimorfismo
```

Comando de ejecución:

```bash
./polimorfismo
```

Salida esperada:

```txt
=== Parte 2: Bloque B - Polimorfismo ===
B1 - A + B:
6 8
10 12
B1 - A - B:
-4 -4
-4 -4
B2 - maxValue<int>: 9
B2 - maxValue<double>: 8.5
B3 - Determinante usando IMatrix*: -2
```

## Pruebas mínimas

Comando de compilación:

```bash
g++ -std=c++20 tests/pruebas_minimas.cpp -Iinclude -o pruebas
```

Comando de ejecución:

```bash
./pruebas
```

Salida esperada:

```txt
Todas las pruebas minimas pasaron correctamente.
```
