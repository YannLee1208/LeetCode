#include <iostream>


using namespace std;

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
    int maxDepth(TreeNode* root) {

        if (!root)
            return 0;

        int leftMaxDepth = maxDepth(root->left);
        int rightMaxDepth = maxDepth(root->right);
        return max(leftMaxDepth, rightMaxDepth) + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
