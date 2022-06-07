class Solution
{
public:
    vector<vector<int> > ans;
    void dfs(vector<int> &nums, int n, int k)
    {
        if (k >= n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = k; i < n; ++i)
        {
            swap(nums[k], nums[i]);
            dfs(nums, n, k + 1);
            swap(nums[k], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &nums)
    {
        int n = nums.size();
        dfs(nums, n, 0);

        return ans;
    }
};