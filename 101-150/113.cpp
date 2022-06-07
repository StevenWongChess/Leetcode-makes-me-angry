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
    vector<vector<int> > ans;
    vector<int> list;
    void dfs(TreeNode *root, int targetSum)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            if (targetSum == root->val)
                ans.push_back(list);
            return;
        }
        if (root->left)
        {
            list.push_back(root->left->val);
            dfs(root->left, targetSum - root->val);
            list.pop_back();
        }
        if (root->right)
        {
            list.push_back(root->right->val);
            dfs(root->right, targetSum - root->val);
            list.pop_back();
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int targetSum)
    {
        if (root)
        {
            list.push_back(root->val);
            dfs(root, targetSum);
        }
        return ans;
    }
};