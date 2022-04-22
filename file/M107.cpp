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
    int level = 0;
    void dfs(TreeNode* root, vector<vector<int>>& ans){
        if(!root)
            return;
        if(ans.size() <= level)
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        level++;
        dfs(root->left, ans);
        dfs(root->right, ans);
        level--;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> list;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                list.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(list);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};