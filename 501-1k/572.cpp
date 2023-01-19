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
    bool same(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return true;
        if (!r1 || !r2)
            return false;
        return r1->val == r2->val && same(r1->left, r2->left) && same(r1->right, r2->right);
    }
    bool dfs(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        return same(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return dfs(root, subRoot);
    }
};