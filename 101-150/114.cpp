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
    void flatten(TreeNode *root)
    {
        TreeNode *it = root;

        while (it)
        {
            if (it->left)
            {
                auto prev = it->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = it->right;
                it->right = it->left;
                auto tmp = it->left;
                it->left = nullptr;
                it = tmp;
            }
            else
            {
                it = it->right;
            }
        }
    }
};