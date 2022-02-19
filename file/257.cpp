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
    vector<string> ans;
    string v_to_str(vector<int> v){
        if(v.empty())
            return "";
        string ret = to_string(v[0]);
        for(int i = 1; i < v.size(); i++)
            ret += ("->" + to_string(v[i]));
        return ret;
    }
    void dfs(TreeNode* root, vector<int> v){
        if(!root)
            return;
        v.push_back(root->val);
        if(!root->left && !root->right)
            ans.push_back(v_to_str(v));
        if(root->left)
            dfs(root->left, v);
        if(root->right)
            dfs(root->right, v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {    
        dfs(root, {});
        return ans;
    }
};