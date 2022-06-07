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
class Solution
{
public:
    TreeNode *dfs(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        auto left = dfs(nums, l, mid - 1);
        auto right = dfs(nums, mid + 1, r);
        auto node = new TreeNode(nums[mid], left, right);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return dfs(nums, 0, n - 1);
    }
};