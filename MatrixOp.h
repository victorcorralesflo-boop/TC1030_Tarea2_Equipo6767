#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
private:
    int id;
    std::string nombre;
    double sueldo;

public:
    Empleado(int id = 0, std::string nombre = "", double sueldo = 0)
        : id(id), nombre(nombre), sueldo(sueldo) {}

    friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado) {
        os << "Empleado[ID: " << empleado.id
           << ", Nombre: " << empleado.nombre
           << ", Sueldo: $" << empleado.sueldo << "]";
        return os;
    }
};

#endif
