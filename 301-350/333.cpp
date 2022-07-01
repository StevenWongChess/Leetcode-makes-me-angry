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
    vector<int> dfs(TreeNode *root)
    {
        if (!root)
        {
            return {INT_MAX, INT_MIN, 0, 1};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left[3] == 1 && right[3] == 1 && left[1] < root->val && right[0] > root->val)
        {
            ans = max(ans, left[2] + right[2] + 1);
            return {left[2] == 0 ? root->val : left[0], right[2] == 0 ? root->val : right[1], left[2] + right[2] + 1, 1};
        }
        else
        {
            return {0, 0, 0, 0};
        }
    }

    int largestBSTSubtree(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};