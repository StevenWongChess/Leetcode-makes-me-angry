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
    void dfs(TreeNode* root, bool flag){
        if(!root)
            return;
        if(flag && !root->left && !root->right)
            sum += root->val;
        if(root->left)
            dfs(root->left, true);
        if(root->right)
            dfs(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, false);
        return sum;
    }
};