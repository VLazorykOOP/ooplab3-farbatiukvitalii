#include "Rhombus.h"
#include "IntVector.h"
#include "DoubleMatrix.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== ROMBUS =====\n";
    Rhombus r(5, 6, 3);
    r.print();

    cout << "\n===== INT VECTOR =====\n";
    IntVector a(5, 2), b(5, 3);
    IntVector c = a.add(b);
    c.print();

    cout << "Objects count: " << IntVector::getCount() << endl;

    cout << "\n===== DOUBLE MATRIX =====\n";
    DoubleMatrix m1(4,3,1.5);
    DoubleMatrix m2(4,3,2.0);
    DoubleMatrix m3 = m1.add(m2);
    m3.print();

    return 0;
}
