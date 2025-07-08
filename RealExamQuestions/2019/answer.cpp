#include "include/create.hpp"
#include "include/print.hpp"
#include "include/struct.hpp"
void reverseList(LNode<int>* head) {
    LNode<int>* cur = head->next;
    LNode<int>* next = nullptr;
    LNode<int>* pre = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = pre;
}

LNode<int>* ListPartition(LNode<int>* head) {
    if (!head || !head->next)
        return nullptr;
    LNode<int>* fast = head;
    LNode<int>* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    LNode<int>* newHead = new LNode<int>(0);
    newHead->next = slow->next;
    slow->next = nullptr;
    return newHead;
}

LNode<int>* mergeList(LNode<int>* head1, LNode<int>* head2) {
    LNode<int>* cur1 = head1->next;
    LNode<int>* cur2 = head2->next;
    LNode<int>* next1 = nullptr;
    LNode<int>* next2 = nullptr;
    while (cur1 && cur2) {
        next1 = cur1->next;
        next2 = cur2->next;
        cur1->next = cur2;
        cur2->next = next1;
        cur1 = next1;
        cur2 = next2;
    }
    return head1;
}

int main() {
    LNode<int>* List = createList(11);
    std::cout << "original: ";
    printList(List);
    LNode<int>* head1 = List;
    LNode<int>* head2 = ListPartition(List);
    reverseList(head2);
    LNode<int>* ans = mergeList(head1, head2);
    std::cout << "ans: ";
    printList(ans);
}