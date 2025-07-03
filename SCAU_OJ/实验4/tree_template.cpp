#include <iostream>

struct BNode {
    char data;
    BNode* lchild;
    BNode* rchild;
    BNode(char val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

BNode* createTree(std::string input, int& index) {
    if (index >= input.length() || input[index] == '#') {
        index++;
        return nullptr;
    }
    char val = input[index++];
    BNode* node = new BNode(val);
    node->lchild = createTree(input, index);
    node->rchild = createTree(input, index);
    return node;
}