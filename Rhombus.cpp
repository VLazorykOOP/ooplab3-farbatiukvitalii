#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus() : side(1), diag(1), color(0) {}

Rhombus::Rhombus(double s, double d, int c) {
    setSide(s);
    setDiag(d);
    setColor(c);
}

void Rhombus::setSide(double s) {
    side = (s > 0 ? s : 1);
}

void Rhombus::setDiag(double d) {
    diag = (d > 0 ? d : 1);
}

void Rhombus::setColor(int c) {
    color = (c >= 0 ? c : 0);
}

double Rhombus::getSide() const { return side; }
double Rhombus::getDiag() const { return diag; }
int Rhombus::getColor() const { return color; }

double Rhombus::area() const {
    return (diag / 2.0) * sqrt(4 * side * side - diag * diag / 4.0);
}

double Rhombus::perimeter() const {
    return 4 * side;
}

void Rhombus::print() const {
    cout << "Romb: side=" << side 
         << " diag=" << diag 
         << " color=" << color
         << " Area=" << area() 
         << " Perimeter=" << perimeter()
         << endl;
}
