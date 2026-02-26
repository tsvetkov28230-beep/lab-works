#pragma once

#include "root.h"

// Функция, демонстрирующая виртуальный вызов
void demonstrateVirtualCall(Root& root) {
    root.calculate();
    root.display();
}