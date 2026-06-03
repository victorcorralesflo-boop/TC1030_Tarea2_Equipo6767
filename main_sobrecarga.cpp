#ifndef TEMPLATEUTILS_H
#define TEMPLATEUTILS_H

#include <stdexcept>

template <typename T>
T maxValue(T* arreglo, int tamanio) {
    if (arreglo == nullptr) {
        throw std::invalid_argument("El arreglo no puede ser nulo.");
    }

    if (tamanio <= 0) {
        throw std::invalid_argument("El tamanio debe ser mayor que cero.");
    }

    T maximo = arreglo[0];

    for (int i = 1; i < tamanio; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }

    return maximo;
}

#endif
