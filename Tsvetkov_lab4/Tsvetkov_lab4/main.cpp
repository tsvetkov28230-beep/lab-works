#include "Tree.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Ru");
    Tree tree;

    tree.buildExampleTree();


    tree.printTree();
    std::cout << std::endl;

    int target = 27;
    tree.printAllPaths(target);

    return 0;
}