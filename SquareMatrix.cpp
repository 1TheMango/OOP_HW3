#include <iostream>
using namespace std;
#include "SquareMatrix.hpp"
SquareMatrix::SquareMatrix(const int size) : Matrix(size, size) {}
SquareMatrix::SquareMatrix(SquareMatrix const& other) : Matrix(other) {}
SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    SquareMatrix result(rows);
    for (int i = 0; i < rows * cols; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}
SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    SquareMatrix result(rows);
    for (int i = 0; i < rows * cols; ++i) {
        result.elements[i]=elements[i]-other.elements[i];
    }
    return result;
}
SquareMatrix SquareMatrix::operator*(const SquareMatrix& other) const {
    if (cols != other.rows) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    SquareMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < cols; ++k) {
                sum += getElement(i, k) * other.getElement(k, j);
            }
            result.setElement(i, j, sum);
        }
    }
    return result;
}
bool SquareMatrix::operator==(const SquareMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows*cols; ++i) {
        if (elements[i] != other.elements[i]) {
            return false;  
        }
    }
    return true;
}
double SquareMatrix::getElement(const int row, const int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout<<"out of range"<<endl;
    }           
    return elements[row*cols+col]; 
}
void SquareMatrix::setElement(const int row, const int col, const double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout<<"out of range"<<endl;
    }
    elements[row*cols+col]=value;
} 
