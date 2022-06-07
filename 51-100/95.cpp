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
    vector<TreeNode *> dfs(int l, int r)
    {
        if (l > r)
            return {nullptr};
        vector<TreeNode *> ans;
        for (int i = l; i <= r; ++i)
        {
            auto left = dfs(l, i - 1);
            auto right = dfs(i + 1, r);
            for (auto a : left)
            {
                for (auto b : right)
                {
                    auto node = new TreeNode(i, a, b);
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return dfs(1, n);
    }
};