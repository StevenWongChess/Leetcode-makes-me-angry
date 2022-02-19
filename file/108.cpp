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
    TreeNode* assign(vector<int>& nums, int l, int r){
        if(l > r)
            return nullptr;
        int mid = (l + r) / 2;
        return new TreeNode(nums[mid], assign(nums, l, mid - 1), assign(nums, mid + 1, r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return assign(nums, 0, nums.size() - 1);
    }
};