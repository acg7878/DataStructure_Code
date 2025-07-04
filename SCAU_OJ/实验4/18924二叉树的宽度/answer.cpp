#include <iostream>
#include <map>
#include <queue>
#include <vector>

struct BNode {
    int data;
    BNode* lchild;
    BNode* rchild;
    BNode(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

BNode* createTree(int n, std::vector<std::pair<int, int>> pairs) {
    std::vector<BNode*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new BNode(i);
    }
    for (auto it : pairs) {
        int key = it.first;
        int value = it.second;
        if (nodes[key]->lchild)
            nodes[key]->rchild = nodes[value];
        else
            nodes[key]->lchild = nodes[value];
    }

    return nodes[1];
}

void calWeigh(BNode* root, int level, std::vector<int>& counts) {
    if (!root)
        return;
    counts[level]++;
    calWeigh(root->lchild, level + 1, counts);
    calWeigh(root->rchild, level + 1, counts);
    return;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> pairs;
    for (int i = 1; i <= n - 1; i++) {
        int first, second;
        std::cin >> first >> second;
        pairs.emplace_back(first, second);
    }
    BNode* root = createTree(n, pairs);
    std::vector<int> counts(n, 0);
    calWeigh(root, 0, counts);
    int max = -1;
    for (int num : counts) {
        if (num > max)
            max = num;
    }
    std::cout << max << std::endl;
}