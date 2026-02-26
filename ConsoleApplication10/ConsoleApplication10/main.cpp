#include "List.h"
#include <iostream>
#include <sstream>

int main()
{
    setlocale(LC_ALL, "Ru");

    List<int> lst;

    lst.pushBack(1);
    lst.pushFront(2);
    lst.pushBack(3);

    std::cout << "Создан список: " << lst << std::endl;

    std::cout << "\nВставка по итератору:" << std::endl;
    auto it = lst.begin();
    ++it;
    lst.insert(it, 99);
    std::cout << "После вставки: " << lst << std::endl;

    std::cout << "\nУдаление по итератору:" << std::endl;
    it = lst.begin();
    ++it;
    lst.erase(it);
    std::cout << "После удаления: " << lst << std::endl;

    std::cout << "\nПростое слияние:" << std::endl;
    List<int> lst2;
    lst2.pushBack(100);
    lst2.pushBack(200);
    std::cout << "Второй список: " << lst2 << std::endl;

    lst.splice(lst2);
    std::cout << "После слияния: " << lst << std::endl;
    std::cout << "Второй список после слияния: " << lst2 << std::endl;

    std::cout << "\nСлияние отсортированных:" << std::endl;
    List<int> sorted1;
    sorted1.pushBack(10);
    sorted1.pushBack(30);
    sorted1.pushBack(50);

    List<int> sorted2;
    sorted2.pushBack(20);
    sorted2.pushBack(40);
    sorted2.pushBack(60);

    std::cout << "Первый: " << sorted1 << std::endl;
    std::cout << "Второй: " << sorted2 << std::endl;

    sorted1.merge(sorted2);
    std::cout << "После merge: " << sorted1 << std::endl;

    std::cout << "\nИтерация:" << std::endl;
    std::stringstream input("a b c");
    List<std::string> words;
    input >> words;

    std::cout << "Строковый список: ";
    for (auto it = words.begin(); it != words.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\nОбработка ошибок:" << std::endl;
    List<int> empty;
    try
    {
        empty.erase(empty.begin());
    }
    catch (const std::exception& e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}