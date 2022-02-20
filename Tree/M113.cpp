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
    vector<vector<int>> ans;
    vector<int> l;
    void dfs(TreeNode* root, int targetSum) {
        if(!root)
            return;
        if(!root->left && !root->right && targetSum == root->val){
            ans.push_back(l);
            return;
        }
        if(root->left){
            l.push_back(root->left->val);
            dfs(root->left, targetSum - root->val);
            l.pop_back();
        }
        if(root->right){
            l.push_back(root->right->val);
            dfs(root->right, targetSum - root->val);
            l.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root)
            l.push_back(root->val);
        dfs(root, targetSum);
        return ans;
    }
};