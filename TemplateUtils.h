#ifndef MATRIXOP_H
#define MATRIXOP_H

#include "IMatrix.h"
#include <iostream>
#include <stdexcept>
#include <vector>

class MatrixOp : public IMatrix {
private:
    std::vector<std::vector<double>> data;

    double determinantRecursive(const std::vector<std::vector<double>>& matrix) const {
        int n = matrix.size();

        if (n == 1) {
            return matrix[0][0];
        }

        if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }

        double det = 0;

        for (int col = 0; col < n; col++) {
            std::vector<std::vector<double>> submatrix;

            for (int i = 1; i < n; i++) {
                std::vector<double> row;
                for (int j = 0; j < n; j++) {
                    if (j != col) {
                        row.push_back(matrix[i][j]);
                    }
                }
                submatrix.push_back(row);
            }

            double sign = (col % 2 == 0) ? 1 : -1;
            det += sign * matrix[0][col] * determinantRecursive(submatrix);
        }

        return det;
    }

public:
    MatrixOp() = default;

    MatrixOp(const std::vector<std::vector<double>>& data)
        : data(data) {
        if (data.empty() || data[0].empty()) {
            throw std::invalid_argument("La matriz no puede estar vacia.");
        }

        int columns = data[0].size();

        for (const auto& row : data) {
            if ((int)row.size() != columns) {
                throw std::invalid_argument("Todas las filas deben tener el mismo numero de columnas.");
            }
        }
    }

    int rows() const {
        return data.size();
    }

    int cols() const {
        return data.empty() ? 0 : data[0].size();
    }

    MatrixOp operator+(const MatrixOp& other) const {
        if (rows() != other.rows() || cols() != other.cols()) {
            throw std::invalid_argument("No se pueden sumar matrices de dimensiones diferentes.");
        }

        std::vector<std::vector<double>> result = data;

        for (int i = 0; i < rows(); i++) {
            for (int j = 0; j < cols(); j++) {
                result[i][j] += other.data[i][j];
            }
        }

        return MatrixOp(result);
    }

    MatrixOp operator-(const MatrixOp& other) const {
        if (rows() != other.rows() || cols() != other.cols()) {
            throw std::invalid_argument("No se pueden restar matrices de dimensiones diferentes.");
        }

        std::vector<std::vector<double>> result = data;

        for (int i = 0; i < rows(); i++) {
            for (int j = 0; j < cols(); j++) {
                result[i][j] -= other.data[i][j];
            }
        }

        return MatrixOp(result);
    }

    double determinant() const override {
        if (rows() != cols()) {
            throw std::invalid_argument("El determinante solo existe para matrices cuadradas.");
        }

        return determinantRecursive(data);
    }

    void print() const {
        for (const auto& row : data) {
            for (double value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif
