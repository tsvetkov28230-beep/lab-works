#include <iostream>
#include "pair.h"
#include "money.h"
#include "fraction.h"

using namespace std;

void demo(Pair& p) {
    p.display(cout);
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Pair* arr[4];

    arr[0] = new Money(150, 75);
    arr[1] = new Money(85, 30);
    arr[2] = new Fraction(3, 750);
    arr[3] = new Fraction(1, 250);

    for (int i = 0; i < 4; i++) {
        arr[i]->display(cout);
        cout << endl;
    }

    Pair* sum = arr[0]->add(*arr[1]);
    cout << "\nСумма первого и второго: ";
    sum->display(cout);
    cout << endl;
    delete sum;

    Pair* diff = arr[2]->subtract(*arr[3]);
    cout << "Разность третьего и четвертого: ";
    diff->display(cout);
    cout << endl;
    delete diff;

    Money m1;
    cout << "Введите рубли и копейки: ";
    m1.input(cin);
    m1.display(cout);

    cout << "Введите целую и дробную часть (0-999): ";
    Fraction f1;
    f1.input(cin);
    cout << "Дробь: ";
    f1.display(cout);
    cout << endl;


    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    return 0;
}