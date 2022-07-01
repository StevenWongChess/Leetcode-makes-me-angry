/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *it = root;
        while (it)
        {
            if (it->val > p->val && it->val > q->val)
                it = it->left;
            else if (it->val < p->val && it->val < q->val)
                it = it->right;
            else
                return it;
        }

        return nullptr;
    }
};