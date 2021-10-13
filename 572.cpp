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
    bool ans = true;
    bool same(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        if(root->val == subRoot->val){
            return same(root->left, subRoot->left) && same(root->right, subRoot->right);
        }  
        else{
            return false;
        }
    }
    bool sub(TreeNode* root, TreeNode* subRoot){
        if(!root)
            return false;
        return same(root, subRoot) || sub(root->left, subRoot) || sub(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return sub(root, subRoot);
    }
};