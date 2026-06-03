# Diagrama de clases - Polimorfismo

## Diagrama en Mermaid

```mermaid
classDiagram
    class IMatrix {
        <<interface>>
        +determinant() double
        +~IMatrix()
    }

    class MatrixOp {
        -vector~vector~double~~ data
        -determinantRecursive(matrix) double
        +MatrixOp()
        +MatrixOp(data)
        +rows() int
        +cols() int
        +operator+(other) MatrixOp
        +operator-(other) MatrixOp
        +determinant() double
        +print() void
    }

    IMatrix <|-- MatrixOp
```

## Explicación

La clase `IMatrix` funciona como una interfaz porque contiene el método virtual puro `determinant()`.  
La clase `MatrixOp` hereda de `IMatrix` e implementa dicho método, por lo que se puede usar polimorfismo en tiempo de ejecución mediante un apuntador de tipo `IMatrix*`.

Ejemplo:

```cpp
IMatrix* matriz = &A;
cout << matriz->determinant();
```
