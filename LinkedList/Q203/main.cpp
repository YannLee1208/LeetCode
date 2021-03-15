#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr)
            return head;

        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while (cur->next != nullptr) {

            if (cur->next->val == val) {
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            } else
                cur = cur->next;
        }

        ListNode * retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
