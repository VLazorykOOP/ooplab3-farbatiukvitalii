#include "IntVector.h"

int IntVector::count = 0;

IntVector::IntVector() : size(1), state(0) {
    arr = new int[1]{0};
    count++;
}

IntVector::IntVector(int n) : size(n), state(0) {
    if (n <= 0) { size = 1; }
    arr = new int[size]{0};
    count++;
}

IntVector::IntVector(int n, int value) : size(n), state(0) {
    if (n <= 0) { size = 1; }
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = value;
    count++;
}

IntVector::IntVector(const IntVector& v) {
    size = v.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = v.arr[i];
    state = v.state;
    count++;
}

IntVector& IntVector::operator=(const IntVector& v) {
    if (this == &v) return *this;
    delete[] arr;
    size = v.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = v.arr[i];
    state = v.state;
    return *this;
}

IntVector::~IntVector() {
    delete[] arr;
    count--;
}

void IntVector::set(int index, int value) {
    if (index < 0 || index >= size) { state = -1; return; }
    arr[index] = value;
}

int IntVector::get(int index) {
    if (index < 0 || index >= size) { state = -1; return 0; }
    return arr[index];
}

IntVector IntVector::add(const IntVector& v) {
    int n = size < v.size ? size : v.size;
    IntVector t(n);
    for (int i = 0; i < n; i++) t.arr[i] = arr[i] + v.arr[i];
    return t;
}

IntVector IntVector::sub(const IntVector& v) {
    int n = size < v.size ? size : v.size;
    IntVector t(n);
    for (int i = 0; i < n; i++) t.arr[i] = arr[i] - v.arr[i];
    return t;
}

IntVector IntVector::mul(short k) {
    IntVector t(size);
    for (int i = 0; i < size; i++) t.arr[i] = arr[i] * k;
    return t;
}

bool IntVector::greater(const IntVector& v) {
    return size > v.size;
}

bool IntVector::less(const IntVector& v) {
    return size < v.size;
}

bool IntVector::equal(const IntVector& v) {
    return size == v.size;
}

void IntVector::print() {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int IntVector::getCount() { return count; }
