#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto {
private:
    double x;
    double y;

public:
    Punto(double x = 0, double y = 0)
        : x(x), y(y) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    bool operator==(const Punto& otro) const {
        return x == otro.x && y == otro.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

#endif
