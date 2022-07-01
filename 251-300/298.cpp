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
    int ans = 0;
    void dfs(TreeNode *root, TreeNode *p, int l)
    {
        if (!root)
            return;
        if (!p || root->val != p->val + 1)
        {
            l = 1;
        }
        else
        {
            ++l;
        }
        ans = max(ans, l);
        dfs(root->left, root, l);
        dfs(root->right, root, l);
    }

    int longestConsecutive(TreeNode *root)
    {
        dfs(root, nullptr, 0);
        return ans;
    }
};