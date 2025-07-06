#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max

// 题目给定的节点结构
struct BNode {
    int data;
    BNode* lchild;
    BNode* rchild;
    BNode(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

/**
 * @brief 递归计算子树深度，并更新全局直径
 * @param node 当前子树的根节点
 * @param diameter 全局直径的引用，用于在递归中更新
 * @return 返回以 node 为根的子树的最大深度
 */
int calculate_depth_and_update_diameter(BNode* node, int& diameter) {
    // 基准情况：空树的深度为0
    if (node == nullptr) {
        return 0;
    }

    // 1. 递归计算左、右子树的深度
    int left_depth = calculate_depth_and_update_diameter(node->lchild, diameter);
    int right_depth = calculate_depth_and_update_diameter(node->rchild, diameter);

    // 2. 更新全局直径
    // 穿过当前节点的最长路径 = 左子树深度 + 右子树深度
    // 用它来挑战并更新全局最大直径
    diameter = std::max(diameter, left_depth + right_depth);

    // 3. 返回当前子树的深度
    // 当前子树深度 = 1 (当前节点) + 左右子树深度的较大值
    return 1 + std::max(left_depth, right_depth);
}

int main() {
    // 提高cin/cout性能
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    // 首先检查输入是否成功
    if (!(std::cin >> n)) {
        return 0;
    }

    // 如果节点数小于等于1，直径为0
    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 节点编号为1到n，所以我们需要一个大小为 n+1 的vector来存储节点指针
    // 索引0不使用，方便与节点编号直接对应
    std::vector<BNode*> nodes(n + 1);
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new BNode(i);
    }

    // 使用一个布尔数组来标记哪些节点是子节点，以便后续找到根节点
    // 根节点是唯一一个不作为任何其他节点的子节点的节点
    std::vector<bool> is_child(n + 1, false);

    // 读取 n-1 条边来构建树
    for (int i = 0; i < n - 1; ++i) {
        int parent_val, child_val;
        std::cin >> parent_val >> child_val;

        BNode* parent_node = nodes[parent_val];
        BNode* child_node = nodes[child_val];

        // 根据题意 "x第一次出现时y为左孩子"
        // 我们可以通过检查 lchild 是否为空来实现
        if (parent_node->lchild == nullptr) {
            parent_node->lchild = child_node;
        } else {
            parent_node->rchild = child_node;
        }
        // 标记 child_val 是一个子节点
        is_child[child_val] = true;
    }

    // 寻找根节点
    BNode* root = nullptr;
    for (int i = 1; i <= n; ++i) {
        if (!is_child[i]) {
            root = nodes[i];
            break;
        }
    }

    int diameter = 0;
    // 从根节点开始递归，计算深度并更新直径
    calculate_depth_and_update_diameter(root, diameter);

    std::cout << diameter << std::endl;
    
    // 释放动态分配的内存（好习惯，虽然在线评测系统不强制）
    for (int i = 1; i <= n; ++i) {
        delete nodes[i];
    }

    return 0;
}
