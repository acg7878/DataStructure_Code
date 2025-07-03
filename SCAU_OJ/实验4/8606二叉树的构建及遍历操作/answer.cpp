#include <iostream>
#include <string>

struct BNode {
    char data;
    BNode* lchild;
    BNode* rchild;
    BNode(char val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

BNode* createTree(const std::string& input, int& index) {
    if (index >= (int)input.length() || input[index] == '#') {
        index++;
        return nullptr;
    }
    char val = input[index++];
    BNode* node = new BNode(val);
    node->lchild = createTree(input, index);
    node->rchild = createTree(input, index);
    return node;
}

void preOrder(BNode* T) {
    if (T != nullptr) {
        std::cout << T->data;
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(BNode* T) {
    if (T == nullptr)
        return;
    inOrder(T->lchild);
    std::cout << T->data;
    inOrder(T->rchild);
}

void postOrder(BNode* T) {
    if (T == nullptr)
        return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    std::cout << T->data;
}

int main() {
    std::string input;
    std::cin >> input;

    int index = 0;
    BNode* root = createTree(input, index);
    preOrder(root);
    std::cout << std::endl;
    inOrder(root);
    std::cout << std::endl;
    postOrder(root);
    return 0;
}