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
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return nullptr;
        int value = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
        TreeNode* now = new TreeNode(value, mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr), mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr));
        return now;
    }
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        TreeNode* top = new TreeNode(root1->val + root2->val, mergeTrees(root1->left, root2->left), mergeTrees(root1->right, root2->right));
        return top;
    }
};