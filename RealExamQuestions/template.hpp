#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <random>
#include <vector>
// ---------- struct begin-----------
template <typename T>
struct LNode {
    T data;
    LNode<T>* next;
    LNode() : data(), next(nullptr) {}
    LNode(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
struct BNode {
    T data;
    BNode<T>* lchild;
    BNode<T>* rchild;
    BNode(const T& val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

// ---------- struct end-------------

// ---------- create begin-----------
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
// ---------- create end ------------

// 打印 vector 信息的辅助函数
void print_vector_info(const std::string& name, const std::vector<int>& vec) {
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
#endif  // TEMPLATE_HPP