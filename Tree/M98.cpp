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
    bool dfs(TreeNode* root, long l, long r){
        if(!root)
            return true;
        long mid = root->val;
        if(mid <= l || mid >= r)
            return false;
        return dfs(root->left, l , mid) && dfs(root->right, mid, r);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
    // vector<int> v;
    // bool isValidBST(TreeNode* root) {
    //     dfs(root);
    //     for(int i = 1; i < v.size(); i++){
    //         if(v[i - 1] >= v[i])
    //             return false;
    //     }
    //     return true;
    // }

    // void dfs(TreeNode* root){
    //     if(!root)
    //         return;
    //     dfs(root->left);
    //     v.push_back(root->val);
    //     dfs(root->right);
    // }
};