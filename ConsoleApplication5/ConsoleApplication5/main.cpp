#include "triangle.h"
#include "rightangled.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    Triangle t1(5, 6, 7);
    cout << "t1:" << endl;
    t1.print();

    t1.changeSides(1, 2, 3);
    cout << "\nt1 после changeSides(1, 2, 3):" << endl;
    t1.print();

    Triangle t2(10, 11, 12);
    cout << "\nt2:" << endl;
    t2.print();

    t2.changeSides(-2, -1, 0);
    cout << "\nt2 после changeSides(-2, -1, 0):" << endl;
    t2.print();

    RightAngled r1(6, 8, 10);
    cout << "\nr1:" << endl;
    r1.print();

    r1.changeSides(1, 1, sqrt(2 * 2 + 2 * 2) - 10);
    cout << "\nr1 после changeSides(1, 1, delta):" << endl;
    r1.print();

    RightAngled r2(5, 12, 13);
    cout << "\nr2:" << endl;
    r2.print();

    r2.changeSides(2, 2, sqrt(7 * 7 + 14 * 14) - 13);
    cout << "\nr2 после changeSides(2, 2, delta):" << endl;
    r2.print();

    try {
        Triangle bad(3, 4, 5);
        cout << "\nПопытка некорректного изменения сторон:" << endl;
        bad.changeSides(1, 1, 10);
    }
    catch (...) {
        cout << "Ошибка перехвачена!" << endl;
    }

    Triangle t3(7, 8, 9);
    cout << "\nt3 до изменения:" << endl;
    t3.print();

    t3.changeSides(0.5, -0.5, 0.2);
    cout << "\nt3 после changeSides(0.5, -0.5, 0.2):" << endl;
    t3.print();

    return 0;
}