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
    bool isSymmetric(TreeNode* root){
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root->left); q.push(root->right);
        while(!q.empty()){
            TreeNode* l = q.front(); q.pop();
            TreeNode* r = q.front(); q.pop();
            if(!l && !r)
                continue;
            if(!l || !r || l->val != r->val)
                return false;
            q.push(l->left); q.push(r->right);
            q.push(l->right); q.push(r->left);
        }
        return true;
    }
    // bool judge(TreeNode* l, TreeNode* r){
    //     if(!l && !r)
    //         return true;
    //     if(!l || !r || l->val != r->val)
    //         return false;
    //     return judge(l->left, r->right) && judge(l->right, r->left);
    // }
    // bool isSymmetric(TreeNode* root){
    //     return !root || judge(root->left, root->right);
    // }
};