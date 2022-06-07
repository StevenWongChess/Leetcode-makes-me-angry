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
    int sum = 0;
    void dfs(TreeNode *root, int n)
    {
        if (!root)
            return;
        n += root->val;
        if (!root->left && !root->right)
        {
            sum += n;
            return;
        }
        if (root->left)
            dfs(root->left, n * 10);
        if (root->right)
            dfs(root->right, n * 10);
    }

    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return sum;
    }
};