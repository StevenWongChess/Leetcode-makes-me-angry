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
    vector<string> ans;
    vector<int> words;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        words.push_back(root->val);
        if (!root->left && !root->right)
        {
            string line = to_string(words[0]);
            int m = words.size();
            for (int i = 1; i < m; ++i)
            {
                line += ("->" + to_string(words[i]));
            }
            ans.push_back(line);
        }
        dfs(root->left);
        dfs(root->right);
        words.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};