#ifndef CONTADOR_H
#define CONTADOR_H

#include <iostream>

class Contador {
private:
    int valor;

public:
    Contador(int valor = 0)
        : valor(valor) {}

    int getValor() const {
        return valor;
    }

    Contador operator++(int) {
        Contador temporal = *this;
        valor++;
        return temporal;
    }

    friend std::ostream& operator<<(std::ostream& os, const Contador& contador) {
        os << contador.valor;
        return os;
    }
};

#endif
