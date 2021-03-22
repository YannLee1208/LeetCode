#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if (root == nullptr)
           return true;

       return helper(root->left, root->right);
    }

    bool helper(TreeNode* l, TreeNode* r){
        if (l == nullptr && r == nullptr)
            return true;
        else if (l == nullptr || r == nullptr)
            return false;
        else{
            return l->val == r->val && helper(l->right, r->left) && helper(l->left, r->right);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
