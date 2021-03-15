//
// Created by yann on 2021/3/10.
//

#ifndef Q206_SOLUTION_H
#define Q206_SOLUTION_H

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr)
//            return head;
//
//        ListNode *pre = head;
//        ListNode *cur = head->next;
//        if (cur == nullptr)
//            return head;
//
//        ListNode *next = cur->next;
//        head->next = nullptr;
//        while (next != nullptr){
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//            next = next->next;
//        }
//
//        cur->next = pre;
//
//        return cur;

        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;


    }
};

#endif //Q206_SOLUTION_H
