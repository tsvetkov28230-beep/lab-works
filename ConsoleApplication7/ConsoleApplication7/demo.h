#pragma once
#ifndef DEMO_H
#define DEMO_H

#include "pair.h"

// Функция, демонстрирующая виртуальный вызов
void demonstrateVirtualCall(Pair& p) {
    p.display();
}

#endif