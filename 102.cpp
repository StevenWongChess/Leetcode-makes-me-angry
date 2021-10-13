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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans = {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp = {};
            for(int i = 0; i < size; i++){
                TreeNode* u = q.front();
                tmp.push_back(u->val);
                q.pop();
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};