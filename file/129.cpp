/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int tmp = 0;
    void dfs(TreeNode* root){
        if(!root)
            return;
        tmp = 10 * tmp + root->val;
        if(!root->left && !root->right)
            sum += tmp;
        dfs(root->left);
        dfs(root->right);
        tmp /= 10;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};