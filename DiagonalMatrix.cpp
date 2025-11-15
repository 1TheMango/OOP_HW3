#include "DiagonalMatrix.hpp"
#include "SquareMatrix.hpp"
#include <iostream>
using namespace std;

DiagonalMatrix::DiagonalMatrix(const int size) : SquareMatrix(size) {}
DiagonalMatrix::DiagonalMatrix(DiagonalMatrix const& other) : SquareMatrix(other) {}
DiagonalMatrix DiagonalMatrix::operator+(const DiagonalMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    DiagonalMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        result.setElement(i, i, this->getElement(i, i) + other.getElement(i, i));
    }
    return result;
}
DiagonalMatrix DiagonalMatrix::operator-(const DiagonalMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    DiagonalMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        result.setElement(i, i, this->getElement(i, i) - other.getElement(i, i));
    }
    return result;
}
DiagonalMatrix DiagonalMatrix::operator*(const DiagonalMatrix& other) const {
    if (cols != other.rows) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    DiagonalMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        result.setElement(i, i, this->getElement(i, i) * other.getElement(i, i));
    }
    return result;
}
bool DiagonalMatrix::operator==(const DiagonalMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        if (this->getElement(i, i) != other.getElement(i, i)) {
            return false;  
        }
    }
    return true;
}
double DiagonalMatrix::getElement(const int row, const int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout<<"out of range"<<endl;
    }           
    if (row != col) {
        return 0.0;
    }
    return elements[row*cols+col]; 
}
void DiagonalMatrix::setElement(const int row, const int col, const double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout<<"out of range"<<endl;
    }
    if (row != col && value != 0.0) {
        cout<<"only diagonal elements can be non-zero in a diagonal matrix"<<endl;
    } else {
        elements[row*cols+col]=value;
    }
}
