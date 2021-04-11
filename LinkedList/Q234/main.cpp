#include <iostream>
#include "stack"
#include "vector"
#include "string"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr)
            return true;

        int len = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }

        bool isOdd;
        if (len % 2 == 0)
            isOdd = true;
        else
            isOdd = false;

        std::stack<ListNode *> s;
        cur = head;
        for (int i = 0; i < len / 2; ++i) {
            s.push(cur);
            cur = cur->next;
        }

        if (!isOdd)
            cur = cur->next;

        cur = cur->next;
        while (!s.empty()) {
            ListNode *node = s.top();
            s.pop();
            if (node->val != cur->val)
                return false;

            cur = cur->next;
        }

        return true;

    }

    bool isPalindrome2(ListNode *head) {
        if (head == nullptr)
            return true;

        std::vector<int> v;
        ListNode *cur = head;
        while (cur != nullptr) {
            v.push_back(cur->val);
            cur = cur->next;
        }

        int l = 0, r = v.size() - 1;

        while (l < r)
            if (v[l++] != v[r--])
                return false;

        return true;
    }

    bool isPalindrome3(ListNode *head) {
        ListNode *temp = head;
        std::string s = "";
        while (temp != nullptr) {
            s += char(temp->val);
            temp = temp->next;
        }
        std::string rev = s;
        reverse(s.begin(), s.end());
        if (s == rev)
            return true;
        else
            return false;
    }
};