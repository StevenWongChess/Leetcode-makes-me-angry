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
    int depth(TreeNode *root)
    {
        int ans = 0;
        while (root)
        {
            ++ans;
            root = root->left;
        }
        return ans;
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        if (l == r)
        {
            return (1 << l) + countNodes(root->right);
        }
        else
        {
            return (1 << r) + countNodes(root->left);
        }
    }
};