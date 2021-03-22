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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *evenHead = head->next;

        ListNode *oddCur = head;
        ListNode *evenCur = head->next;

        while (evenCur != nullptr) {
            if (evenCur->next == nullptr) {
                break;
            } else {
                oddCur->next = evenCur->next;
                oddCur = oddCur->next;


                evenCur->next = oddCur->next;
                evenCur = evenCur->next;
            }
        }
        oddCur->next = evenHead;

        return head;

    }
};
