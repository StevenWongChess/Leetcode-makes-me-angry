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
    double diff = DBL_MAX;
    int ans = -1;
    void dfs(TreeNode *root, double target)
    {
        if (!root)
            return;
        if (root->val == target)
        {
            diff = 0;
            ans = target;
        }
        else if (root->val > target)
        {
            double tmp = root->val - target;
            if (tmp < diff)
            {
                diff = tmp;
                ans = root->val;
            }
            dfs(root->left, target);
        }
        else
        {
            double tmp = target - root->val;
            if (tmp < diff)
            {
                diff = tmp;
                ans = root->val;
            }
            dfs(root->right, target);
        }
    }

    int closestValue(TreeNode *root, double target)
    {
        dfs(root, target);
        return ans;
    }
};