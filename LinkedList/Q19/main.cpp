#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;
        ListNode *q = dummyHead->next;
        for (int i = 0; i < n; ++i) {
            q = q->next;
        }

        while (q != nullptr){
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
