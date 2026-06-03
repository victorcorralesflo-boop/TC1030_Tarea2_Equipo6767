#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

class Complejo {
private:
    double real;
    double imaginario;

public:
    Complejo(double real = 0, double imaginario = 0)
        : real(real), imaginario(imaginario) {}

    double getReal() const {
        return real;
    }

    double getImaginario() const {
        return imaginario;
    }

    Complejo operator+(const Complejo& otro) const {
        return Complejo(real + otro.real, imaginario + otro.imaginario);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complejo& c) {
        os << "(" << c.real;
        if (c.imaginario >= 0) {
            os << " + " << c.imaginario << "i";
        } else {
            os << " - " << -c.imaginario << "i";
        }
        os << ")";
        return os;
    }
};

#endif
