#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
private:
    // successor 代表 反转完毕后 head下一个节点应该连什么
    ListNode* successor = nullptr;
    ListNode* reverseBetween(ListNode* head, int n){
        // 从head开始 reverse 第1...n 个节点 返回reverse后的头节点
        if (head == nullptr || n == 1) {
            successor = head->next;
            return head;
        }

        ListNode *res = reverseBetween(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return res;


    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if (m == 1)
            return reverseBetween(head, n);

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
