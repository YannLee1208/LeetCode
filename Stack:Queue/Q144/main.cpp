#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Classic Non-Recursive algorithm for preorder traversal
// Time Complexity: O(n), n is the node number in the tree
// Space Complexity: O(h), h is the height of the tree
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == nullptr)
            return res;

        // pair中的 bool false代表go命令， true代表print命令
        stack<pair<TreeNode*, bool> > stack;

        stack.push(make_pair(root, false));
        while(!stack.empty()){
            auto node = stack.top().first;
            auto visited = stack.top().second;
            stack.pop();

            if(visited)
                res.push_back(node->val);
            else{
                if(node->right)
                    stack.push(make_pair(node->right, false));
                if(node->left)
                    stack.push(make_pair(node->left, false));
                stack.push(make_pair(root, true));
            }
        }

        return res;
    }
};