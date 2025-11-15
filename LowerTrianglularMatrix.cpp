#include <iostream>
using namespace std;
#include "LowerTriangularMatrix.hpp"
LowerTriangularMatrix::LowerTriangularMatrix(const int size) : SquareMatrix(size) {}
LowerTriangularMatrix::LowerTriangularMatrix(LowerTriangularMatrix const& other) : SquareMatrix(other) {}
LowerTriangularMatrix LowerTriangularMatrix::operator+(const LowerTriangularMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    LowerTriangularMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) { 
            result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}
LowerTriangularMatrix LowerTriangularMatrix::operator-(const LowerTriangularMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    LowerTriangularMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) { 
            result.setElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}
LowerTriangularMatrix LowerTriangularMatrix::operator*(const LowerTriangularMatrix& other) const {
    if (cols != other.rows) {
        cout<<"matrix dimensions are not right"<<endl;
    }
    LowerTriangularMatrix result(rows);
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
bool LowerTriangularMatrix::operator==(const LowerTriangularMatrix& other) const {
    if(rows!=other.rows||cols!=other.cols){
        return false;
    }
    return this->elements==other.elements;
}
double LowerTriangularMatrix::getElement(const int row, const int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout<<"out of range"<<endl;
    }        
    if (row < col) {
        return 0.0;
    }
    int ind = (row * (row + 1)) / 2 + col;
    return elements[ind];
}
void LowerTriangularMatrix::setElement(const int row, const int col, const double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout<<"out of range"<<endl;
    }
    if(row<col && value != 0.0){
        cout<<"upper tri is zero"<<endl;
    }
    if (row>=col){
        int ind = (row * (row + 1)) / 2 + col;
        elements[ind] = value;
    }
}
