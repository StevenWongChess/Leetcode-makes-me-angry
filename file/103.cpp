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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> s; s.push(root);
        bool odd = true;
        while(!s.empty()){
            int n = s.size();
            vector<int> line(n);
            for(int i = 0; i < n; i++){
                auto r = s.front(); s.pop();
                if(odd)
                    line[i] = r->val;
                else
                    line[n - 1 - i] = r->val;
                if(r->left)
                    s.push(r->left);
                if(r->right)
                    s.push(r->right);
            }
            ans.push_back(line);
            odd = !odd;
        }
        return ans;
    }
};