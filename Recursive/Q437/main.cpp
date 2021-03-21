#include <iostream>
#include "queue"

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
         TreeNode(int *arr, int n){
             queue<TreeNode*> q;
             val = arr[0];
             q.push(this);
             int index = 1;
             while (!q.empty() && index < n){
                TreeNode* node = q.front();
                q.pop();
                if (arr[index] != INT_MAX) {
                    auto *l = new TreeNode(arr[index]);
                    node->left = l;
                    q.push(l);
                }
                 index++;

                if (index < n && arr[index] != INT_MAX){
                    auto* r = new TreeNode(arr[index]);
                    node->right = r;
                    q.push(r);
                }
                index++;
             }
         }
     };

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {

        if ( root == nullptr)
            return 0;

        int res = findPath( root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        return res;
    }

    // 错误
//    int pathSum2(TreeNode* root, int sum) {
//
//        if ( root == nullptr)
//            return 0;
//
//        int res = 0;
//        if (sum == root->val) {
//            res += 1;
//            cout << root->val<< endl;
//           cout << root->left << " " << root->right->val << endl;
//        }
//
//        res += pathSum2(root->left, sum);
//        res += pathSum2(root->right, sum);
//        res += pathSum2(root->left, sum - root->val);
//        res += pathSum2(root->right, sum - root->val);
//
//        return res;
//
//    }

private:

    // 包含node的路径
    int findPath(TreeNode* node, int num){

        if (node == nullptr)
            return 0;

        int res = 0;
        if (node->val == num)
            res += 1;

        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);

        return res;
    }
};

int main(){
    int arr[] = {10,5,-3,3,2,INT_MAX,11,3,-2,INT_MAX,1};
    int n = 11;
    TreeNode* root = new TreeNode(arr, 11);
    Solution().pathSum2(root, 8);

}
