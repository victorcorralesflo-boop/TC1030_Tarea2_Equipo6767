# Corrección de errores detectados

## 1. Operador de asignación en Buffer

### Error detectado

Una implementación incorrecta de `operator=` puede generar copia superficial, provocando que dos objetos apunten a la misma zona de memoria.

### Corrección aplicada

Se implementó copia profunda:

- Se valida que el objeto no se esté asignando a sí mismo.
- Se libera la memoria anterior.
- Se reserva nueva memoria.
- Se copia el contenido del otro objeto.

```cpp
Buffer& operator=(const Buffer& otro) {
    if (this != &otro) {
        delete[] datos;
        tamanio = otro.tamanio;
        datos = new char[tamanio + 1];
        std::strcpy(datos, otro.datos);
    }
    return *this;
}
```

## 2. Post-incremento en Contador

### Error detectado

El post-incremento debe devolver el valor anterior y después aumentar el contador.

### Corrección aplicada

Se creó un objeto temporal antes de incrementar el valor.

```cpp
Contador operator++(int) {
    Contador temporal = *this;
    valor++;
    return temporal;
}
```

## 3. Validación de dimensiones en MatrixOp

### Error detectado

Sumar o restar matrices con dimensiones diferentes puede producir errores lógicos o accesos inválidos.

### Corrección aplicada

Antes de realizar `operator+` y `operator-`, se valida que ambas matrices tengan el mismo número de filas y columnas.

```cpp
if (rows() != other.rows() || cols() != other.cols()) {
    throw std::invalid_argument("No se pueden operar matrices de dimensiones diferentes.");
}
```

## 4. Validación de arreglo en maxValue<T>()

### Error detectado

La función podría recibir un arreglo nulo o un tamaño inválido.

### Corrección aplicada

Se agregaron validaciones antes de recorrer el arreglo.

```cpp
if (arreglo == nullptr) {
    throw std::invalid_argument("El arreglo no puede ser nulo.");
}

if (tamanio <= 0) {
    throw std::invalid_argument("El tamanio debe ser mayor que cero.");
}
```

## 5. Determinante en MatrixOp

### Error detectado

El determinante solo puede calcularse en matrices cuadradas.

### Corrección aplicada

Se agregó una validación para lanzar una excepción cuando la matriz no sea cuadrada.

```cpp
if (rows() != cols()) {
    throw std::invalid_argument("El determinante solo existe para matrices cuadradas.");
}
```
