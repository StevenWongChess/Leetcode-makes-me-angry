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
    unordered_map<long, int> dict;
    int count = 0;
    void dfs(TreeNode* root, int target, long prefix){
        if(!root)
            return;
        prefix += root->val;
        if(dict.find(prefix - target) != dict.end()){
            count += dict[prefix - target];
        }
        
        ++dict[prefix];
        dfs(root->left, target, prefix);
        dfs(root->right, target, prefix);
        --dict[prefix];
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        dict[0] = 1;
        dfs(root, targetSum, 0);
        return count;
    }
};