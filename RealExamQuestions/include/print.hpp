#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <vector>
#include "struct.hpp"  // Include the struct definitions

// 打印 vector 信息的辅助函数
inline void print_vector_info(const std::string& name,
                              const std::vector<int>& vec) {
    long long sum = 0;
    std::cout << name << " (size=" << vec.size() << "): ";
    for (int x : vec) {
        std::cout << x << " ";
        sum += x;
    }
    std::cout << "| Sum = " << sum << std::endl;
}

template <typename T>
void printList(LNode<T>* head) {
    if (!head || !head->next) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    LNode<T>* cur = head->next;
    while (cur) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "nullptr" << std::endl;
}

#endif  // PRINT_HPP
