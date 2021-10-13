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
    int count = 0;
    void dfs(TreeNode* root, int sum){
        if(sum == 0)
            count++;
        if(root->left)
            dfs(root->left, sum - root->left->val);
        if(root->right)
            dfs(root->right, sum - root->right->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        dfs(root, targetSum - root->val);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};