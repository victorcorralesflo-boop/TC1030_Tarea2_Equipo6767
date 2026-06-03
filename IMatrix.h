#ifndef BUFFER_H
#define BUFFER_H

#include <cstring>
#include <iostream>

class Buffer {
private:
    char* datos;
    int tamanio;

public:
    Buffer(const char* texto = "") {
        tamanio = std::strlen(texto);
        datos = new char[tamanio + 1];
        std::strcpy(datos, texto);
    }

    Buffer(const Buffer& otro) {
        tamanio = otro.tamanio;
        datos = new char[tamanio + 1];
        std::strcpy(datos, otro.datos);
    }

    Buffer& operator=(const Buffer& otro) {
        if (this != &otro) {
            delete[] datos;
            tamanio = otro.tamanio;
            datos = new char[tamanio + 1];
            std::strcpy(datos, otro.datos);
        }
        return *this;
    }

    const char* getDatos() const {
        return datos;
    }

    ~Buffer() {
        delete[] datos;
    }

    friend std::ostream& operator<<(std::ostream& os, const Buffer& buffer) {
        os << buffer.datos;
        return os;
    }
};

#endif
