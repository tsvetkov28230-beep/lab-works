#include "Deque.h"
#include <iostream>

template<typename T>
void printDeque(Deque<T>& dq, const std::string& name, std::ostream& out)
{
    out << "Дек " << name << " (размер " << dq.size() << "): ";

    if (dq.isEmpty())
    {
        out << "пуст";
    }
    else
    {
        Deque<T> temp;
        while (!dq.isEmpty())
        {
            std::cout << dq.front() << " ";
            temp.pushBack(dq.front());
            dq.popFront();
        }

        while (!temp.isEmpty())
        {
            dq.pushBack(temp.front());
            temp.popFront();
        }
    }
    out << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    Deque<int> dq1;

    std::cout << "1. Добавляем элементы в дек1:" << std::endl;
    dq1.pushBack(10);
    dq1.pushFront(20);
    dq1.pushBack(30);
    dq1.pushFront(40);
    dq1.pushBack(50);
    printDeque(dq1, "dq1", std::cout);

    std::cout << "\n2. Удаляем из начала и конца:" << std::endl;
    dq1.popFront();
    dq1.popBack();
    printDeque(dq1, "dq1", std::cout);

    std::cout << "\n3. Копируем дек1 в дек2:" << std::endl;
    Deque<int> dq2 = dq1;
    printDeque(dq1, "dq1 (оригинал)", std::cout);
    printDeque(dq2, "dq2 (копия)", std::cout);

    std::cout << "\n4. Работа со строковым деком:" << std::endl;
    Deque<std::string> dq3;
    dq3.pushBack("я");
    dq3.pushFront("мир");
    dq3.pushBack("люблю");
    dq3.pushFront("весь");
    printDeque(dq3, "dq3 (строки)", std::cout);

    std::cout << "\n5. Дек из одинаковых элементов:" << std::endl;
    Deque<double> dq4(2.71, 4);
    printDeque(dq4, "dq4 (4 x 2.71)", std::cout);

    std::cout << "\n6. Изменяем элементы дека:" << std::endl;
    dq4.front() = 1.0;
    dq4.back() = 9.0;
    Deque<double> temp = dq4;
    temp.popFront();
    temp.popBack();
    temp.front() = 5.0;
    temp.back() = 7.0;
    dq4 = temp;
    printDeque(dq4, "dq4 (после изменений)", std::cout);

    std::cout << "\n7. Присваивание:" << std::endl;
    Deque<double> dq5;
    dq5 = dq4;
    printDeque(dq4, "dq4 (исходный)", std::cout);
    printDeque(dq5, "dq5 (после присваивания)", std::cout);

    std::cout << "\n8. Тест с символами (добавляем с двух сторон):" << std::endl;
    Deque<char> dq6;
    dq6.pushFront('A');
    dq6.pushBack('B');
    dq6.pushFront('C');
    dq6.pushBack('D');
    dq6.pushFront('E');
    printDeque(dq6, "dq6 (символы)", std::cout);

    std::cout << "\n9. Очистка дека:" << std::endl;
    while (!dq6.isEmpty())
    {
        dq6.popFront();
    }
    printDeque(dq6, "dq6 (после очистки)", std::cout);

    std::cout << "\n10. Тест пустого дека:" << std::endl;
    Deque<int> emptyDq;
    printDeque(emptyDq, "emptyDq", std::cout);
    try
    {
        std::cout << "Попытка получить front(): ";
        emptyDq.front();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n11. Добавляем много элементов:" << std::endl;
    Deque<int> dq7;
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            dq7.pushBack(i);
        else
            dq7.pushFront(i);
    }
    printDeque(dq7, "dq7 (1-10)", std::cout);

    std::cout << "\n12. Извлекаем все элементы с конца:" << std::endl;
    std::cout << "Порядок извлечения: ";
    while (!dq7.isEmpty())
    {
        std::cout << dq7.back() << " ";
        dq7.popBack();
    }
    std::cout << std::endl;
    printDeque(dq7, "dq7 (после извлечения)", std::cout);

    return 0;
}