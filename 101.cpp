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
    //iterative
    bool judge(TreeNode* root){
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* a = q.front(); q.pop();
            TreeNode* b = q.front(); q.pop();
            if(!a && !b)
                continue;
            if(!a || !b || a->val != b->val)
                return false;
            q.push(a->left);
            q.push(b->right);
            q.push(a->right);
            q.push(b->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root){
        return judge(root);
    }

    // recursive
    // bool judge(TreeNode* l, TreeNode* r){
    //     if(!l && !r)
    //         return true;
    //     if(!l || !r)
    //         return false;
    //     return l->val == r->val && judge(l->left, r->right) && judge(l->right, r->left);
    // }
    // bool isSymmetric(TreeNode* root) {
    //     return !root || judge(root->left, root->right);
    // }
};