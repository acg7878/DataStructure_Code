#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct BNode {
  int data;
  BNode* lchild;
  BNode* rchild;
  BNode(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

BNode* createTree(int n, std::vector<std::pair<int, int>> pairs) {
  std::vector<bool> is_child(n + 1, false);
  std::vector<BNode*> nodes(n + 1);
  for (int i = 1; i <= n; i++) {
    nodes[i] = new BNode(i);
  }
  for (auto& pair : pairs) {
    is_child[pair.second] = true;
    if (nodes[pair.first]->lchild) {
      nodes[pair.first]->rchild = nodes[pair.second];
    } else {
      nodes[pair.first]->lchild = nodes[pair.second];
    }
  }
  BNode* root = nullptr;
  for (int i = 1; i <= n; i++) {
    if (!is_child[i]) {
      root = nodes[i];
      break;
    }
  }
  return root;
}

int find_max_track(BNode* root, int& diameter) {
  if (root == nullptr)
    return 0;
  int left_depth = find_max_track(root->lchild, diameter);
  int right_depth = find_max_track(root->rchild, diameter);
  diameter = std::max(diameter, left_depth + right_depth);
  return 1 + std::max(left_depth, right_depth);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> pairs;
  for (int i = 1; i < n; i++) {
    int first, second;
    std::cin >> first >> second;
    pairs.emplace_back(first, second);
  }
  BNode* root = createTree(n, pairs);
  int diameter = 0;
  find_max_track(root, diameter);
  std::cout << diameter << std::endl;
}