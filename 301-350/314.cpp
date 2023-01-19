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
    void dfs(int& l, int& r, TreeNode* root, int idx){
        if(!root)
            return;
        l = min(l, idx);
        r = max(r, idx);
        dfs(l, r, root->left, idx - 1);
        dfs(l, r, root->right, idx + 1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)
            return {};
        int l = 0, r = 0;
        dfs(l, r, root, 0);
        l = -l;
            
        vector<vector<int>> ans(l + r + 1);
        queue<pair<TreeNode*, int>> q;
        q.push({root, l});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(!x){
                continue;
            }
            if(ans[y].size() == 0){
                ans[y] = {x->val};
            }
            else{
                ans[y].push_back(x->val);
            }
            // if(x->left){
                q.push({x->left, y - 1});
            // }
            // if(x->right){
                q.push({x->right, y + 1});
            // }
        }
        
        return ans;
    }
};