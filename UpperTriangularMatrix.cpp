#include <iostream>
using namespace std;
#include "UpperTriangularMatrix.hpp"
UpperTriangularMatrix::UpperTriangularMatrix(const int size):SquareMatrix(size){}
UpperTriangularMatrix::UpperTriangularMatrix(UpperTriangularMatrix const& other):SquareMatrix(other){}
UpperTriangularMatrix UpperTriangularMatrix::operator+(const UpperTriangularMatrix& other)const{
    if(rows!=other.rows||cols!=other.cols){
        cout<<"matrix dimensions are not right"<<endl;
    }
    UpperTriangularMatrix result(rows);
    for(int i=0;i<rows;i++){
        for(int j=i;j<cols;j++){
            result.setElement(i,j,this->getElement(i,j)+other.getElement(i,j));
        }
    }
    return result;
}
UpperTriangularMatrix UpperTriangularMatrix::operator-(const UpperTriangularMatrix& other)const{
    if(rows!=other.rows||cols!=other.cols){
        cout<<"matrix dimensions are not right"<<endl;
    }
    UpperTriangularMatrix result(rows);
    for(int i=0;i<rows;i++){
        for(int j=i;j<cols;j++){
            result.setElement(i,j,this->getElement(i,j)-other.getElement(i,j));
        }
    }
    return result;
}
UpperTriangularMatrix UpperTriangularMatrix::operator*(const UpperTriangularMatrix& other)const{
    if(cols!=other.rows){
        cout<<"matrix dimensions are not right"<<endl;
    }
    UpperTriangularMatrix resultantmatrix(rows);
    for(int i=0;i<rows;i++){
        for(int j=i;j<other.cols;j++){
            double sumone=0.0;
            for(int k=i;k<=j;k++){
                sumone+=getElement(i,k)*other.getElement(k,j);
            }
            resultantmatrix.setElement(i,j,sumone);
        }
    }
    return resultantmatrix;
}
bool UpperTriangularMatrix::operator==(const UpperTriangularMatrix& other)const{
    if(rows!=other.rows||cols!=other.cols){
        return false;
    }
    for(int i=0;i<rows;i++){
        for(int j=i;j<cols;j++){
            if(this->getElement(i,j)!=other.getElement(i,j)){
                return false;
            }
        }
    }
    return true;
}
double UpperTriangularMatrix::getElement(const int row,const int col)const{
    if(row<0||row>=rows||col<0||col>=cols){
        cout<<"out of range"<<endl;
    }
    return elements[(rows*row)+col +(row*(row+1))/2];
}
void UpperTriangularMatrix::setElement(const int row,const int col,const double value){
    if(row<0||row>=rows||col<0||col>=cols){
        cout<<"out of range"<<endl;
    }
    else{
        elements[(rows*row)+col +(row*(row+1))/2]=value;
    }
}