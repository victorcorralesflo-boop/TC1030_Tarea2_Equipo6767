#include <cassert>
#include <iostream>
#include "Complejo.h"
#include "Punto.h"
#include "Empleado.h"
#include "Contador.h"
#include "Buffer.h"
#include "MatrixOp.h"
#include "TemplateUtils.h"

int main() {
    Complejo c1(1, 2);
    Complejo c2(3, 4);
    Complejo c3 = c1 + c2;
    assert(c3.getReal() == 4);
    assert(c3.getImaginario() == 6);

    Punto p1(1, 1);
    Punto p2(1, 1);
    Punto p3(2, 3);
    assert(p1 == p2);
    assert(!(p1 == p3));

    Contador contador(5);
    Contador anterior = contador++;
    assert(anterior.getValor() == 5);
    assert(contador.getValor() == 6);

    Buffer b1("A");
    Buffer b2("B");
    b1 = b2;
    assert(std::string(b1.getDatos()) == "B");

    MatrixOp A({{1, 2}, {3, 4}});
    MatrixOp B({{5, 6}, {7, 8}});
    MatrixOp C = A + B;
    MatrixOp D = A - B;

    int numeros[] = {1, 8, 3};
    assert(maxValue(numeros, 3) == 8);

    IMatrix* matriz = &A;
    assert(matriz->determinant() == -2);

    std::cout << "Todas las pruebas minimas pasaron correctamente." << std::endl;
    return 0;
}
