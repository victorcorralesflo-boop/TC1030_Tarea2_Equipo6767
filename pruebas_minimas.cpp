#include <iostream>
#include "MatrixOp.h"
#include "TemplateUtils.h"

int main() {
    std::cout << "=== Parte 2: Bloque B - Polimorfismo ===" << std::endl;

    MatrixOp A({
        {1, 2},
        {3, 4}
    });

    MatrixOp B({
        {5, 6},
        {7, 8}
    });

    MatrixOp suma = A + B;
    MatrixOp resta = A - B;

    std::cout << "B1 - A + B:" << std::endl;
    suma.print();

    std::cout << "B1 - A - B:" << std::endl;
    resta.print();

    int enteros[] = {4, 9, 2, 7, 1};
    double decimales[] = {3.2, 8.5, 1.1, 6.7};

    std::cout << "B2 - maxValue<int>: " << maxValue(enteros, 5) << std::endl;
    std::cout << "B2 - maxValue<double>: " << maxValue(decimales, 4) << std::endl;

    IMatrix* matriz = &A;
    std::cout << "B3 - Determinante usando IMatrix*: " << matriz->determinant() << std::endl;

    return 0;
}
