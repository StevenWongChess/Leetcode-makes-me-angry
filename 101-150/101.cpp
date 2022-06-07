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
class Solution
{
public:
    //     bool isSame(TreeNode* l, TreeNode* r){
    //         if(!l && !r){
    //             return true;
    //         }
    //         if(!l || !r){
    //             return false;
    //         }

    //         return l->val == r->val && isSame(l->left, r->right) && isSame(l->right, r->left);
    //     }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            auto l = q.front();
            q.pop();
            auto r = q.front();
            q.pop();
            if (!l && !r)
                continue;
            if (!l || !r || l->val != r->val)
                return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
        // if(!root)
        //     return true;
        // return isSame(root->left, root->right);
    }
};