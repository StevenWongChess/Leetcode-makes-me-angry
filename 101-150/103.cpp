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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;
        if (!root)
            return ans;
        bool odd = true;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            int n = q.size();
            vector<int> line(n);
            for (int i = 0; i < n; ++i)
            {
                auto r = q.front();
                q.pop();
                if (odd)
                {
                    line[i] = r->val;
                }
                else
                {
                    line[n - 1 - i] = r->val;
                }
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            ans.push_back(line);
            odd = !odd;
        }

        return ans;
    }
};