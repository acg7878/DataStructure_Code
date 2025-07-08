#ifndef STRUCT_HPP
#define STRUCT_HPP

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

#endif  // STRUCT_HPP
