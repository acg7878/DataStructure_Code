#include "../template.hpp"

void reverseList(LNode<int>* head) {}

LNode<int>* ListPartition(LNode<int>* head) {
    LNode<int>* fast = head->next;
    LNode<int>* slow = head->next;
    LNode<int>* slowPre = head;
    while (fast->next) {
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
        slowPre = slow;
        slow = slow->next;
    }
    slowPre->next = nullptr;
    LNode<int>* newHead = new LNode(0);
    newHead->next = slow;
    return newHead;
}

int main() {
    LNode<int>* List = createList();
    LNode<int>* head1 = List;
    LNode<int>* head2 = ListPartition(List);
}