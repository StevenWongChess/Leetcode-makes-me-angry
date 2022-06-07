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
    unordered_map<int, int> dict;
    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int a, int b, int c, int d)
    {
        if (a > b || c > d)
        {
            return nullptr;
        }

        int index = dict[postorder[d]];
        auto l = dfs(inorder, postorder, a, index - 1, c, c + index - 1 - a);
        auto r = dfs(inorder, postorder, index + 1, b, d - b + index, d - 1);
        TreeNode *root = new TreeNode(postorder[d], l, r);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        for (int i = 0; i < n; ++i)
        {
            dict[inorder[i]] = i;
        }

        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};