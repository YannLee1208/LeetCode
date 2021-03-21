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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int ldepth = minDepth(root->left);
        int rdepth = minDepth(root->right);

        if (ldepth == 0)
            return rdepth + 1;

        if (rdepth == 0)
            return ldepth + 1;

        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

