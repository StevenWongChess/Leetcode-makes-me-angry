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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        
        if(root->val == key){
            if(root->left == nullptr){
                TreeNode* tmp = root->right;
                delete(root);
                return tmp;
            }
            else if(root->right == nullptr){
                TreeNode* tmp = root->left;
                delete(root);
                return tmp;
            }
            else{
                TreeNode* it = root->right;
                while(it->left){
                    it = it->left;
                }
                root->val = it->val;
                root->right = deleteNode(root->right, it->val);
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};