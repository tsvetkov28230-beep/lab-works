#include "triad.h"
#include "time.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    Triad t1(5, 10, 15);
    Triad t2(5, 10, 15);
    Triad t3(5, 10, 20);
    Triad t4(5, 15, 10);
    Triad t5(10, 5, 15);

    cout << "Сравнение триад:" << endl;
    cout << "t1: "; t1.print();
    cout << "t2: "; t2.print();
    cout << "t3: "; t3.print();
    cout << "t4: "; t4.print();
    cout << "t5: "; t5.print();

    cout << "\nРезультаты сравнения:" << endl;
    cout << "t1 == t2: " << (t1 == t2) << endl;
    cout << "t1 != t3: " << (t1 != t3) << endl;
    cout << "t1 < t3: " << (t1 < t3) << endl;
    cout << "t3 > t1: " << (t3 > t1) << endl;
    cout << "t1 < t4: " << (t1 < t4) << endl;
    cout << "t4 > t1: " << (t4 > t1) << endl;
    cout << "t1 <= t2: " << (t1 <= t2) << endl;
    cout << "t1 >= t2: " << (t1 >= t2) << endl;
    cout << "t1 <= t3: " << (t1 <= t3) << endl;
    cout << "t5 >= t1: " << (t5 >= t1) << endl;

    Time time1(10, 30, 45, true);
    Time time2(10, 30, 45, true);
    Time time3(10, 30, 46, true);
    Time time4(10, 31, 45, true);
    Time time5(11, 30, 45, true);

    cout << "\nСравнение времени:" << endl;
    cout << "time1: "; time1.print();
    cout << "time2: "; time2.print();
    cout << "time3: "; time3.print();
    cout << "time4: "; time4.print();
    cout << "time5: "; time5.print();

    cout << "\nРезультаты сравнения времени:" << endl;
    cout << "time1 == time2: " << (time1 == time2) << endl;
    cout << "time1 != time3: " << (time1 != time3) << endl;
    cout << "time1 < time3: " << (time1 < time3) << endl;
    cout << "time3 > time1: " << (time3 > time1) << endl;
    cout << "time1 < time4: " << (time1 < time4) << endl;
    cout << "time1 < time5: " << (time1 < time5) << endl;

    Time morning(8, 0, 0, true);
    Time afternoon(2, 0, 0, false);

    cout << "\nСравнение утреннего и дневного времени:" << endl;
    cout << "morning: "; morning.print();
    cout << "afternoon: "; afternoon.print();
    cout << "morning < afternoon: " << (morning < afternoon) << endl;
    cout << "morning.getHour24(): " << morning.getHour24() << endl;
    cout << "afternoon.getHour24(): " << afternoon.getHour24() << endl;

    Time t6 = Time(0, 0, 0);
    Time t7 = Time(23, 59, 59);
    Time t8 = Time(12, 0, 0, false);

    cout << "\nСравнение специальных времен:" << endl;
    cout << "t6 (00:00:00): "; t6.print();
    cout << "t7 (23:59:59): "; t7.print();
    cout << "t8 (12:00:00 PM): "; t8.print();

    cout << "t6 < t7: " << (t6 < t7) << endl;
    cout << "t6 < t8: " << (t6 < t8) << endl;
    cout << "t8 < t7: " << (t8 < t7) << endl;

    cout << "\nСравнение через указатели базового класса:" << endl;
    Triad* ptr1 = new Triad(1, 2, 3);
    Triad* ptr2 = new Triad(1, 2, 4);

    cout << "ptr1: " << string(*ptr1) << endl;
    cout << "ptr2: " << string(*ptr2) << endl;
    cout << "*ptr1 < *ptr2: " << (*ptr1 < *ptr2) << endl;

    delete ptr1;
    delete ptr2;

    return 0;
}