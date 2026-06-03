#include <iostream>
#include "Complejo.h"
#include "Punto.h"
#include "Empleado.h"
#include "Contador.h"
#include "Buffer.h"

int main() {
    std::cout << "=== Parte 1: Sobrecarga de operadores ===" << std::endl;

    Complejo c1(2, 3);
    Complejo c2(4, -1);
    Complejo c3 = c1 + c2;
    std::cout << "Complejo operator+: " << c1 << " + " << c2 << " = " << c3 << std::endl;

    Punto p1(3, 5);
    Punto p2(3, 5);
    Punto p3(4, 9);
    std::cout << "Punto operator== p1 == p2: " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "Punto operator== p1 == p3: " << (p1 == p3 ? "true" : "false") << std::endl;

    Empleado empleado(101, "Ana Lopez", 15000);
    std::cout << "Empleado operator<<: " << empleado << std::endl;

    Contador contador(7);
    Contador anterior = contador++;
    std::cout << "Contador operator++(int): antes = " << anterior << ", despues = " << contador << std::endl;

    Buffer b1("Hola");
    Buffer b2("Mundo");
    b1 = b2;
    std::cout << "Buffer operator=: " << b1 << std::endl;

    return 0;
}
