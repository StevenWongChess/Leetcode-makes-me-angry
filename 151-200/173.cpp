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
class BSTIterator
{
public:
    TreeNode *it;
    stack<TreeNode *> s;

    BSTIterator(TreeNode *root)
    {
        it = root;
    }

    int next()
    {
        while (it)
        {
            s.push(it);
            it = it->left;
        }

        it = s.top();
        s.pop();
        auto ans = it->val;
        it = it->right;
        return ans;
    }

    bool hasNext()
    {
        return it || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */