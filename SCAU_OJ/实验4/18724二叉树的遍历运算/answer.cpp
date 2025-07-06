#include <iostream>
#include <string>
void find_post_order(const std::string &pre,const std::string &in) {    
    if (pre.empty()) return;

    char root_node = pre[0];
    // std::string::size_type 相当于 unsigned long，只是方便人观察
    std::string::size_type root_index_in_inorder = in.find(root_node);
    std::string::size_type left_subtree_size = root_index_in_inorder;

    std::string left_pre = pre.substr(1,left_subtree_size);
    std::string left_in = in.substr(0,left_subtree_size);
    find_post_order(left_pre, left_in);

    std::string right_pre = pre.substr(1+left_subtree_size);
    std::string right_in = in.substr(1+root_index_in_inorder);
    find_post_order(right_pre, right_in);

    std::cout << root_node;

}

int main() {
    std::string pre_order,in_order;
    std::cin >> pre_order >> in_order;
    find_post_order(pre_order, in_order);
    std::cout << std::endl;
}