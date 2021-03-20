#include <iostream>
#include "vector"
#include "queue"

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root == nullptr)
            return res;

        q.push(root);
        int tmp;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                tmp = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            res.emplace_back(tmp);
        }

        return res;

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
