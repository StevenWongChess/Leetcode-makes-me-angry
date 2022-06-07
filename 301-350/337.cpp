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
    // rob, nrob
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        return {
            root->val + l.second + r.second,
            max(l.first, l.second) + max(r.first, r.second)};
    }

    int rob(TreeNode *root)
    {
        auto i = dfs(root);
        return max(i.first, i.second);
    }
};