#include <iostream>

struct LNode {
    int data;
    LNode* next;
    LNode(int val) : data(val), next(nullptr) {}
};

// 创建链表，无关题目
LNode* createList() {
    LNode* head = new LNode(0);
    LNode* tail = head;
    for (int i = 1; i <= 10; i++) {
        LNode* node = new LNode(i);
        tail->next = node;
        tail = node;
    }
    return head;
}

// return 1:找到了；return 0:没找到
int find_node(LNode* head, int k, int& ans) {
    if (!head || k <= 0)
        return 0;  // 增加健壮性检查

    int count = k;
    // 快慢指针
    LNode* first = head->next;
    LNode* second = head->next;
    while (count--) {
        if (first) {
            first = first->next;
        } else {
            // k 大于链表长度，直接返回未找到
            return 0;
        }
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    if (second) {
        ans = second->data;
        return 1;
    } else
        return 0;
}

int main() {
    int k;
    std::cin >> k;
    LNode* List = createList();
    int ans = 0;
    if (find_node(List, k, ans)) {
        std::cout << ans << std::endl;
        return 1;
    } else {
        std::cout << "Not Find" << std::endl;
        return 0;
    }
}