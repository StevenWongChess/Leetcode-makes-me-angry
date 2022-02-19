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
    int ith = 0;
    int ans = -1;
    void dfs(TreeNode* root, int k){
        if(!root)
            return;
        dfs(root->left, k);
        ith++;
        if(ith == k){
            ans = root->val;
            return;
        }
        dfs(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};