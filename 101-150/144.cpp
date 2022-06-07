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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *it = root;

        while (it)
        {
            if (it->left)
            {
                TreeNode *prev = it->left;
                while (prev->right && prev->right != it)
                {
                    prev = prev->right;
                }

                if (prev->right)
                {
                    prev->right = nullptr;
                    it = it->right;
                }
                else
                {
                    ans.push_back(it->val);
                    prev->right = it;
                    it = it->left;
                }
            }
            else
            {
                ans.push_back(it->val);
                it = it->right;
            }
        }

        return ans;
    }

    // void dfs(vector<int>& ans, TreeNode* root){
    //     if(!root)
    //         return;
    //     ans.push_back(root->val);
    //     dfs(ans, root->left);
    //     dfs(ans, root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     dfs(ans, root);
    //     return ans;
    // }
};