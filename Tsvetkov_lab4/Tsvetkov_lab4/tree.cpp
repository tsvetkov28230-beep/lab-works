#include "Tree.h"
#include <iostream>

Tree::Tree() : root(nullptr) {}

Tree::Tree(const Tree& other) : root(nullptr) {
    *this = other;
}

Tree::~Tree() {
    destroyTree(root);
}

Tree& Tree::operator=(const Tree& other) {
    if (this != &other) {
        destroyTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

void Tree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

TreeNode* Tree::copyTree(TreeNode* node) {
    if (!node) return nullptr;

    TreeNode* newNode = new TreeNode(node->val);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

void Tree::buildExampleTree() {
    destroyTree(root);

    root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->left->left = new TreeNode(1);
    root->right->right = new TreeNode(4);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(9);
}

void Tree::insert(int value) {
    if (!root) {
        root = new TreeNode(value);
        return;
    }

    TreeNode* current = root;
    while (current) {
        if (!current->left) {
            current->left = new TreeNode(value);
            break;
        }
        else if (!current->right) {
            current->right = new TreeNode(value);
            break;
        }
        else {
            if (current->left && (!current->left->left || !current->left->right)) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
    }
}

void Tree::buildFromArray(int* values, int count) {
    destroyTree(root);

    for (int i = 0; i < count; i++) {
        insert(values[i]);
    }
}

void Tree::findAllPathsRecursive(TreeNode* node,
    int target,
    int currentSum,
    Path& currentPath,
    PathList& allPaths) {
    if (!node) return;

    currentPath.addValue(node->val);
    currentSum += node->val;

    if (!node->left && !node->right) {
        if (currentSum == target) {
            allPaths.addPath(&currentPath);
        }
    }
    else {
        findAllPathsRecursive(node->left, target, currentSum, currentPath, allPaths);
        findAllPathsRecursive(node->right, target, currentSum, currentPath, allPaths);
    }

    currentPath.removeLast();
}

PathList Tree::findAllPaths(int target) {
    PathList allPaths;
    Path currentPath;

    findAllPathsRecursive(root, target, 0, currentPath, allPaths);

    return allPaths;
}

void Tree::printAllPaths(int target) {
    PathList paths = findAllPaths(target);

    if (paths.getSize() == 0) {
        std::cout << "Пути с суммой " << target << " не найдены." << std::endl;
        return;
    }

    std::cout << "Все пути с суммой " << target << ":" << std::endl;
    paths.printAll();
}

void Tree::printTreeRecursive(TreeNode* node, int depth) {
    if (!node) return;

    printTreeRecursive(node->right, depth + 1);

    for (int i = 0; i < depth; i++) {
        std::cout << "   ";
    }
    std::cout << node->val << std::endl;

    printTreeRecursive(node->left, depth + 1);
}

void Tree::printTree() {
    if (!root) {
        std::cout << "Дерево пустое." << std::endl;
        return;
    }
    std::cout << "Структура дерева:" << std::endl;
    printTreeRecursive(root, 0);
}