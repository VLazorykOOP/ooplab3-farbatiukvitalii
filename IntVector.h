#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
using namespace std;

class IntVector {
private:
    int *arr;
    int size;
    int state;
    static int count;

public:
    IntVector();
    IntVector(int n);
    IntVector(int n, int value);
    IntVector(const IntVector& v);
    IntVector& operator=(const IntVector& v);
    ~IntVector();

    void set(int index, int value = 0);
    int get(int index);

    IntVector add(const IntVector& v);
    IntVector sub(const IntVector& v);
    IntVector mul(short k);

    bool greater(const IntVector& v);
    bool less(const IntVector& v);
    bool equal(const IntVector& v);

    void print();
    static int getCount();
};

#endif
