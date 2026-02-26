#include "TreeNode.h"

TreeNode::TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}