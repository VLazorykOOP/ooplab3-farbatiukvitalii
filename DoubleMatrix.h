#ifndef DOUBLEMATRIX_H
#define DOUBLEMATRIX_H

#include <iostream>
using namespace std;

class DoubleMatrix {
private:
    double **m;
    int rows;
    int cols;
    int state;

public:
    DoubleMatrix();
    DoubleMatrix(int n);
    DoubleMatrix(int r, int c, double value);
    DoubleMatrix(const DoubleMatrix& other);
    DoubleMatrix& operator=(const DoubleMatrix& other);
    ~DoubleMatrix();

    void set(int i, int j, double value);
    double get(int i, int j);

    DoubleMatrix add(const DoubleMatrix& b);
    DoubleMatrix sub(const DoubleMatrix& b);
    DoubleMatrix mul(double k);

    bool greater(const DoubleMatrix& b);
    bool less(const DoubleMatrix& b);
    bool equal(const DoubleMatrix& b);

    void print();
};

#endif

