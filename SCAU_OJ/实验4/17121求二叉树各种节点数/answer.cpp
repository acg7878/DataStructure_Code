#include <iostream>
#include <vector>

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

void count_degree(BNode* root, std::vector<int>& counts) {
    if (!root)
        return;
    if (root->lchild && root->rchild)
        counts[2]++;
    else if (root->lchild || root->rchild)
        counts[1]++;
    else
        counts[0]++;
    count_degree(root->lchild, counts);
    count_degree(root->rchild, counts);
}

int main() {
    std::string input;
    std::cin >> input;
    int index = 0;
    BNode* root = createTree(input, index);
    std::vector<int> counts(3, 0);
    count_degree(root, counts);
    for (int i = 2; i >= 0; --i) {
        std::cout << counts[i] << std::endl;
    }
}