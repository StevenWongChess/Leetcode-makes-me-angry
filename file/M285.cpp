/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *parent = nullptr;
    TreeNode *ans = nullptr;
    void dfs(TreeNode *root, TreeNode *p)
    {
        if (p == root)
        {
            if (!p->right)
            {
                ans = parent;
            }
            else
            {
                auto it = p->right;
                while (it->left)
                {
                    it = it->left;
                }
                ans = it;
            }
        }
        else if (root->val > p->val)
        {
            parent = root;
            dfs(root->left, p);
        }
        else
        {
            dfs(root->right, p);
        }
    }
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        dfs(root, p);
        return ans;
    }
};