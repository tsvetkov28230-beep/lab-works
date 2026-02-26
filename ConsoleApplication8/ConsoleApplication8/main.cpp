#include "Deque.h"
#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "Ru");
    Deque<int> intDeque;

    std::cout << "Добавляем элементы: 10 в конец, 20 в начало, 30 в конец" << std::endl;
    intDeque.pushBack(10);
    intDeque.pushFront(20);
    intDeque.pushBack(30);

    std::cout << "Размер: " << intDeque.size() << std::endl;
    std::cout << "Пуст ли? " << (intDeque.isEmpty() ? "Да" : "Нет") << std::endl;
    std::cout << "Первый элемент: " << intDeque.front() << std::endl;
    std::cout << "Последний элемент: " << intDeque.back() << std::endl;

    std::cout << "\nУдаляем из начала" << std::endl;
    intDeque.popFront();
    std::cout << "Теперь первый элемент: " << intDeque.front() << std::endl;
    std::cout << "Размер: " << intDeque.size() << std::endl;

    std::cout << "\nКопирование Deque<int>" << std::endl;
    Deque<int> intDeque2 = intDeque;
    std::cout << "Размер копии: " << intDeque2.size() << std::endl;
    std::cout << "Первый элемент копии: " << intDeque2.front() << std::endl;

    std::cout << "\nТестирование Deque<std::string>" << std::endl;
    Deque<std::string> stringDeque;

    stringDeque.pushBack("Hello");
    stringDeque.pushFront("World");
    stringDeque.pushBack("from");
    stringDeque.pushFront("C++");

    std::cout << "Размер строкового дека: " << stringDeque.size() << std::endl;
    std::cout << "Элементы в порядке от начала к концу (извлекаем по одному):" << std::endl;

    while (!stringDeque.isEmpty())
    {
        std::cout << stringDeque.front() << " ";
        stringDeque.popFront();
    }
    std::cout << std::endl;
    std::cout << "Размер после извлечения всех: " << stringDeque.size() << std::endl;

    std::cout << "\nТестирование Deque<double> с конструктором заполнения" << std::endl;
    Deque<double> doubleDeque(3.14, 5);

    std::cout << "Создаем дек из 5 элементов по 3.14" << std::endl;
    std::cout << "Размер: " << doubleDeque.size() << std::endl;
    std::cout << "Первый элемент: " << doubleDeque.front() << std::endl;
    std::cout << "Последний элемент: " << doubleDeque.back() << std::endl;

    std::cout << "\nИзменяем первый и последний элементы:" << std::endl;
    doubleDeque.front() = 1.11;
    doubleDeque.back() = 9.99;
    std::cout << "Первый элемент теперь: " << doubleDeque.front() << std::endl;

    std::cout << "\nТестирование оператора присваивания" << std::endl;
    Deque<double> anotherDoubleDeque;
    anotherDoubleDeque = doubleDeque;
    std::cout << "Размер после присваивания: " << anotherDoubleDeque.size() << std::endl;

    std::cout << "\nТестирование обработки ошибок" << std::endl;
    Deque<int> emptyDeque;

    try
    {
        std::cout << "Пытаемся получить элемент из пустого дека..." << std::endl;
        int value = emptyDeque.front();
        std::cout << "Значение: " << value << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Пытаемся удалить из пустого дека..." << std::endl;
        emptyDeque.popBack();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }

    std::cout << "\nТестирование добавления/удаления с обоих концов" << std::endl;
    Deque<char> charDeque;

    std::cout << "Добавляем 'A' в начало, 'B' в конец, 'C' в начало, 'D' в конец" << std::endl;
    charDeque.pushFront('A');
    charDeque.pushBack('B');
    charDeque.pushFront('C');
    charDeque.pushBack('D');

    std::cout << "Размер: " << charDeque.size() << std::endl;
    std::cout << "Элементы (извлекаем с конца): ";
    while (!charDeque.isEmpty())
    {
        std::cout << charDeque.back() << " ";
        charDeque.popBack();
    }
    std::cout << std::endl;

    return 0;
}