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
    void recoverTree(TreeNode *root)
    {
        TreeNode *it = root, *last = nullptr, *a = nullptr, *b = nullptr;
        while (it)
        {
            if (it->left)
            {
                TreeNode *prev = it->left;
                while (prev->right && prev->right != it)
                {
                    prev = prev->right;
                }
                if (prev->right)
                {
                    if (last && last->val > it->val)
                    {
                        if (!a)
                            a = last;
                        b = it;
                    }
                    last = it;

                    prev->right = nullptr;
                    it = it->right;
                }
                else
                {
                    prev->right = it;
                    it = it->left;
                }
            }
            else
            {
                if (last && last->val > it->val)
                {
                    if (!a)
                        a = last;
                    b = it;
                }
                last = it;

                it = it->right;
            }
        }

        swap(a->val, b->val);
    }
};