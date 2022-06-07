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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *it = root;

        while (it)
        {
            if (it->right)
            {
                TreeNode *prev = it->right;
                while (prev->left && prev->left != it)
                {
                    prev = prev->left;
                }
                if (prev->left)
                {
                    prev->left = nullptr;
                    it = it->left;
                }
                else
                {
                    ans.push_back(it->val);
                    prev->left = it;
                    it = it->right;
                }
            }
            else
            {
                ans.push_back(it->val);
                it = it->left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};