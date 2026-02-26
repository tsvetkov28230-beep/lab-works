#include <iostream>
#include "root.h"
#include "linear.h"
#include "square.h"

using namespace std;

void demo(Root& r) {
    r.calculate();
    r.display();
}

int main() {
    setlocale(LC_ALL, "Ru");
    Root* eq[4];

    eq[0] = new Linear(2, -6);
    eq[1] = new Square(1, -5, 6);
    eq[2] = new Linear(0, 5);
    eq[3] = new Square(2, 0, 1);
    Linear l1, l2;
    l1 = l2;
    return 0;
    for (int i = 0; i < 4; i++) {
        eq[i]->calculate();
        eq[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete eq[i];
    }

    return 0;
}