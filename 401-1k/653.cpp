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
    stack<TreeNode *> stack_l;
    stack<TreeNode *> stack_r;
    void leftmost(stack<TreeNode *> &stack, TreeNode *node)
    {
        while (node)
        {
            stack.push(node);
            node = node->left;
        }
    };
    void rightmost(stack<TreeNode *> &stack, TreeNode *node)
    {
        while (node)
        {
            stack.push(node);
            node = node->right;
        }
    };

    bool findTarget(TreeNode *root, int k)
    {
        TreeNode *l = root;
        TreeNode *r = root;

        while (true)
        {
            leftmost(stack_l, l);
            rightmost(stack_r, r);
            if (stack_l.empty() || stack_r.empty())
                return false;
            auto l_top = stack_l.top();
            auto r_top = stack_r.top();
            if (l_top->val == r_top->val)
                return false;

            int sum = l_top->val + r_top->val;
            if (sum == k)
                return true;
            else if (sum < k)
            {
                stack_l.pop();
                l = l_top->right;
            }
            else
            {
                stack_r.pop();
                r = r_top->left;
            }
        }

        return false;
    }
};