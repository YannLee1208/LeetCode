#include <iostream>
#include "vector"
#include "queue"
#include "stack"
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            vector<int> level;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            res.push_back(level);
        }

        reverse(res.begin(), res.end());
        return res;
    }

    vector<vector<int>> levelOrderBottom2(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        stack<vector<int>> s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            vector<int> level;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            s.push(level);
        }

        while (!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }

};


