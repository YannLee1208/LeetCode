#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {

        if (node == nullptr)
            return;

        if (node->next == nullptr) {
            delete node;
            node = nullptr;
            return;
        }

        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;

        delete next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
