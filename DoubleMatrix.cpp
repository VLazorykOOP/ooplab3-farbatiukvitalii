#include "DoubleMatrix.h"

DoubleMatrix::DoubleMatrix() : rows(4), cols(3), state(0) {
    m = new double*[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols]{0};
    }
}

DoubleMatrix::DoubleMatrix(int n) : rows(n), cols(n), state(0) {
    m = new double*[rows];
    for (int i = 0; i < rows; i++)
        m[i] = new double[cols]{0};
}

DoubleMatrix::DoubleMatrix(int r, int c, double value) 
    : rows(r), cols(c), state(0) 
{
    m = new double*[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
        for (int j = 0; j < cols; j++) m[i][j] = value;
    }
}

DoubleMatrix::DoubleMatrix(const DoubleMatrix& o) {
    rows = o.rows;
    cols = o.cols;
    state = o.state;

    m = new double*[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
        for (int j = 0; j < cols; j++) m[i][j] = o.m[i][j];
    }
}

DoubleMatrix& DoubleMatrix::operator=(const DoubleMatrix& o) {
    if (this == &o) return *this;
    for (int i = 0; i < rows; i++) delete[] m[i];
    delete[] m;

    rows = o.rows;
    cols = o.cols;
    state = o.state;

    m = new double*[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
        for (int j = 0; j < cols; j++) m[i][j] = o.m[i][j];
    }

    return *this;
}

DoubleMatrix::~DoubleMatrix() {
    for (int i = 0; i < rows; i++) delete[] m[i];
    delete[] m;
}

void DoubleMatrix::set(int i, int j, double value) {
    if (i < 0 || j < 0 || i >= rows || j >= cols) return;
    m[i][j] = value;
}

double DoubleMatrix::get(int i, int j) {
    if (i < 0 || j < 0 || i >= rows || j >= cols) return 0;
    return m[i][j];
}

DoubleMatrix DoubleMatrix::add(const DoubleMatrix& b) {
    DoubleMatrix t(rows, cols, 0);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t.m[i][j] = m[i][j] + b.m[i][j];
    return t;
}

DoubleMatrix DoubleMatrix::sub(const DoubleMatrix& b) {
    DoubleMatrix t(rows, cols, 0);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t.m[i][j] = m[i][j] - b.m[i][j];
    return t;
}

DoubleMatrix DoubleMatrix::mul(double k) {
    DoubleMatrix t(rows, cols, 0);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t.m[i][j] = m[i][j] * k;
    return t;
}

bool DoubleMatrix::greater(const DoubleMatrix& b) {
    return rows * cols > b.rows * b.cols;
}

bool DoubleMatrix::less(const DoubleMatrix& b) {
    return rows * cols < b.rows * b.cols;
}

bool DoubleMatrix::equal(const DoubleMatrix& b) {
    return rows == b.rows && cols == b.cols;
}

void DoubleMatrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << m[i][j] << " ";
        cout << endl;
    }
}
