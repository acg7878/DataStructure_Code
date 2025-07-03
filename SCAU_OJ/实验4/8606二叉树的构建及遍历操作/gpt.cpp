#include <iostream>
#include <string>

// 二叉树节点结构
struct BiTNode {
  char data;
  BiTNode* lchild;  // 左孩子指针（原始指针）
  BiTNode* rchild;  // 右孩子指针（原始指针）

  // 构造函数，初始化节点数据和指针
  BiTNode(char val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

// 递归构建二叉树（先序遍历字符串）
// 参数：输入字符串、当前处理索引（引用传递，用于递归中更新位置）
// 返回：构建的子树根节点指针
BiTNode* createBiTree(const std::string& input, size_t& index) {
  // 索引越界或遇到'#'，表示空节点
  if (index >= input.length() || input[index] == '#') {
    index++;  // 跳过当前'#'
    return nullptr;
  }

  // 创建当前节点
  char val = input[index++];
  BiTNode* node = new BiTNode(val);  // 手动分配内存

  // 递归构建左、右子树
  node->lchild = createBiTree(input, index);
  node->rchild = createBiTree(input, index);

  return node;
}

// 先序遍历（根->左->右）
void preOrderTraverse(BiTNode* T) {
  if (T != nullptr) {
    std::cout << T->data;         // 访问根节点
    preOrderTraverse(T->lchild);  // 遍历左子树
    preOrderTraverse(T->rchild);  // 遍历右子树
  }
}

// 中序遍历（左->根->右）
void inOrderTraverse(BiTNode* T) {
  if (T != nullptr) {
    inOrderTraverse(T->lchild);  // 遍历左子树
    std::cout << T->data;        // 访问根节点
    inOrderTraverse(T->rchild);  // 遍历右子树
  }
}

// 后序遍历（左->右->根）
void postOrderTraverse(BiTNode* T) {
  if (T != nullptr) {
    postOrderTraverse(T->lchild);  // 遍历左子树
    postOrderTraverse(T->rchild);  // 遍历右子树
    std::cout << T->data;          // 访问根节点
  }
}

// 释放二叉树内存（后序遍历方式，避免内存泄漏）
void destroyBiTree(BiTNode*& T) {
  if (T != nullptr) {
    destroyBiTree(T->lchild);  // 释放左子树
    destroyBiTree(T->rchild);  // 释放右子树
    delete T;                  // 释放当前节点
    T = nullptr;               // 避免野指针
  }
}

int main() {
  std::string line;
  std::cin >> line;  // 输入先序遍历字符串（如 "ABD##E##CF##G##"）

  size_t index = 0;
  BiTNode* root = createBiTree(line, index);  // 构建二叉树

  // 执行三种遍历并输出结果
  preOrderTraverse(root);
  std::cout << std::endl;

  inOrderTraverse(root);
  std::cout << std::endl;

  postOrderTraverse(root);
  std::cout << std::endl;

  // 释放内存，防止泄漏
  destroyBiTree(root);

  return 0;
}