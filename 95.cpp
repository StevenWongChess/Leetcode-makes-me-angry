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
    vector<TreeNode*> find(int l, int r){
        if(l > r)
            return {nullptr};
        vector<TreeNode*> ans;
        for(int i = l; i <= r; i++){
            vector<TreeNode*> l_tree = find(l, i - 1);
            vector<TreeNode*> r_tree = find(i + 1, r);
            for(auto left: l_tree){
                for(auto right: r_tree){
                    TreeNode* root = new TreeNode(i, left, right);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return find(1, n);
    }
};