#include <iostream>
#include <string>

/**
 * @brief 通过先序和中序遍历序列，递归地输出后序遍历序列
 * 
 * @param pre 先序遍历序列的子串
 * @param in 中序遍历序列的子串
 */
void find_post_order(const std::string& pre, const std::string& in) {
    // 递归基准情况：如果序列为空，说明是空树，直接返回
    if (pre.empty()) {
        return;
    }

    // 1. 从先序遍历序列中找到当前的根节点（总是第一个元素）
    char root_node = pre[0];

    // 2. 在中序遍历序列中找到根节点的位置，以划分左右子树
    // std::string::size_type 是用于表示字符串大小和索引的安全类型
    std::string::size_type root_index_in_inorder = in.find(root_node);

    // 3. 根据根节点的位置，确定左右子树的大小
    std::string::size_type left_subtree_size = root_index_in_inorder;
    // 右子树的大小可以通过总大小减去左子树大小和根节点得出
    // std::string::size_type right_subtree_size = in.length() - left_subtree_size - 1;

    // 4. 递归地处理左右子树
    // 参数是原字符串的子串(substr)，这会创建临时字符串对象。
    // 对于小规模数据（长度<=30），性能可以接受。
    // 对于大规模数据，更优的方法是传递指针或索引来避免复制。

    // 递归处理左子树
    // 左子树的先序序列是pre中根节点之后，长度为left_subtree_size的部分
    std::string left_pre = pre.substr(1, left_subtree_size);
    // 左子树的中序序列是in中根节点之前的部分
    std::string left_in = in.substr(0, left_subtree_size);
    find_post_order(left_pre, left_in);

    // 递归处理右子树
    // 右子树的先序序列是pre中左子树先序序列之后的所有部分
    std::string right_pre = pre.substr(1 + left_subtree_size);
    // 右子树的中序序列是in中根节点之后的所有部分
    std::string right_in = in.substr(root_index_in_inorder + 1);
    find_post_order(right_pre, right_in);

    // 5. 访问（输出）根节点，这是后序遍历的最后一步
    std::cout << root_node;
}

int main() {
    // 提高cin/cout的性能
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string pre_order, in_order;

    std::cin >> pre_order >> in_order;
    find_post_order(pre_order, in_order);
    std::cout << std::endl;

    return 0;
}
