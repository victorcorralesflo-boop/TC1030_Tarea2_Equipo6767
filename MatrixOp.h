#ifndef IMATRIX_H
#define IMATRIX_H

class IMatrix {
public:
    virtual double determinant() const = 0;
    virtual ~IMatrix() = default;
};

#endif
