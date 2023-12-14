#include <cstdio>
#include <iostream>


using namespace std;

class Matrix
{
private:
    double* data;
    int numRows;
    int numCols;
public:
    Matrix():
    data(nullptr), numRows(0), numCols(0)
    {};

    Matrix(const double* other, int numRows1, int numCols1)
    {
        numCols = numCols1;
        numRows = numRows1;
        data = new double[numCols1*numRows1];
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                data[i*numCols+j] = other[i*numCols+j]; 
            }
        }
    }
    // Task 7
    double operator()(int row, int col) const
    {
        return data[(row)*(numCols) + col];
    }
    double& operator()(int row, int col){
        return data[(row)*(numCols) + col];
    }

    //
    Matrix(const Matrix &other){
        numCols = other.numCols;
        numRows = other.numRows;
        data = new double[numCols*numRows];
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                data[i*numCols+j] = other.data[i*numCols+j]; 
            }
        }
    }
    Matrix& operator=(const Matrix &other){
        if (data){
            numRows = 0;
            numCols = 0;
            delete[] data;
        }
        numCols = other.numCols;
        numRows = other.numRows;
        data = new double[numCols*numRows];
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                data[i*numCols+j] = other.data[i*numCols+j]; 
            }
        }
        return *this;
    } //
    ~Matrix()
    {
        if (data){
            delete[] data;
        }
    }
    void Print() const;
};

void Matrix :: Print() const
{
    for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                cout << data[i*numCols+j] << " "; 
            }
            cout << endl;
        }
}

int main()
{
    int rows = 3;
    int cols = 3;
    double* matrix;
    cout << "ВВедите элементы матрицы: " << endl;
    matrix = new double[rows*cols];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
           cin >> matrix[i*cols+j]; 
        }
    }
    Matrix A(matrix, rows, cols);
    Matrix B;
    B = A;
    B.Print();
    Matrix D(A);
    cout << B(2, 2) << " " << A(1, 1) << endl;
    B(2,2) = 10;
    B.Print();
    D.Print();
    delete[] matrix;
    return 0;
}

