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
    unordered_map<int, int> dict;
    
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int a, int b, int c, int d){
        if(a > b || c > d){
            return nullptr;
        }
        
        int index = dict[preorder[a]];
        auto l = dfs(preorder, inorder, a + 1, index - c + a, c, index - 1);
        auto r = dfs(preorder, inorder, index - c + a + 1, b, index + 1, d);     
        TreeNode* root = new TreeNode(preorder[a], l, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; ++i){
            dict[inorder[i]] = i;
        }
        
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};