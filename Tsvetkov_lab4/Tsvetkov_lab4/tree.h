#pragma once

#include "TreeNode.h"
#include "PathList.h"

class Tree {
private:
    TreeNode* root;

    void findAllPathsRecursive(TreeNode* node,
        int target,
        int currentSum,
        Path& currentPath,
        PathList& allPaths);
    void destroyTree(TreeNode* node);
    TreeNode* copyTree(TreeNode* node);
    void printTreeRecursive(TreeNode* node, int depth);

public:
    Tree();
    Tree(const Tree& other);
    ~Tree();
    Tree& operator=(const Tree& other);

    void insert(int value);
    void buildFromArray(int* values, int count);
    void buildExampleTree();
    PathList findAllPaths(int target);
    void printAllPaths(int target);
    void printTree();
};