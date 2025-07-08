#ifndef CREATE_HPP
#define CREATE_HPP

#include <random>
#include <vector>
#include "struct.hpp"  // Include the struct definitions

std::vector<int> createArr(int size = 10, int min_val = 1, int max_val = 100) {
    std::vector<int> arr;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_val, max_val);

    arr.reserve(size);
    for (int i = 0; i < size; ++i) {
        arr.push_back(distrib(gen));
    }
    return arr;
}

LNode<int>* createList(int size = 10, int min_val = 1, int max_val = 100) {
    if (size <= 0)
        return nullptr;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_val, max_val);

    // 创建头节点
    LNode<int>* head = new LNode<int>(distrib(gen));
    LNode<int>* current = head;

    // 创建剩余节点并连接
    for (int i = 1; i <= size; ++i) {
        current->next = new LNode<int>(distrib(gen));
        current = current->next;
    }

    return head;
}

#endif  // CREATE_HPP
