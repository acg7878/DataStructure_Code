#ifndef THREADED_BINARY_TREE_HPP
#define THREADED_BINARY_TREE_HPP

#include <functional>
template <typename T, typename Compare = std::less<T>>
class ThreadBinaryTree {
   private:
    struct ThreadedNode {
        T data;
        ThreadedNode* lchild;
        ThreadedNode* rchild;
        bool lflag;
        bool rflag;
        ThreadedNode(const T& value)
            : data(value),
              lchild(nullptr),
              rchild(nullptr),
              lflag(false),
              rflag(false) {}
    };

    ThreadedNode* root;
    Compare compare;

    void inorderThreading(ThreadedNode* node, ThreadedNode*& prev) {
        if (node == nullptr)
            return;

        inorderThreading(node->lchild, prev);
        if (node->lchild == nullptr) {
            node->lchild = prev;
            node->lflag = true;
        }
        if (prev != nullptr && prev->rchild == nullptr) {
            prev->rchild = node;
            prev->rflag = true;
        }
        prev = node;
        inorderThreading(node->rchild, prev);
    }

   public:
    ThreadBinaryTree() : root(nullptr) {}
    //~ThreadBinaryTree() { clear(); }

    // void insert(const T& value) {
    //     ThreadedNode* newNode = new ThreadedNode(value);

    //     if(root==nullptr) {
    //         root = newNode;
    //         return;
    //     }

    //     ThreadedNode* current = root;
    //     ThreadedNode* parent = nullptr;

    //     while (current != nullptr) {
    //         parent = current;
    //         if (compare(value,current->data)) {

    //         }
    //     }
    // }
};

#endif