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
    void flatten(TreeNode* root) {
        TreeNode* it = root;
        while(it){
            if(it->left){
                TreeNode* top = it->left;
                TreeNode* down = top;
                while(down->right){
                    down = down->right;
                }
                down->right = it->right;
                it->left = nullptr;
                it->right = top;
            }
            it = it->right;
        }
    }
};