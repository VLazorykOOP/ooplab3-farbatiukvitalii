#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
using namespace std;

class Rhombus {
private:
    double side;
    double diag;
    int color;

public:
    Rhombus();
    Rhombus(double s, double d, int c);

    void setSide(double s);
    void setDiag(double d);
    void setColor(int c);

    double getSide() const;
    double getDiag() const;
    int getColor() const;

    double area() const;
    double perimeter() const;

    void print() const;
};

#endif
