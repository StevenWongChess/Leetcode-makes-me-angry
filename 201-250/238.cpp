class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size(), prefix = 1;
        vector<int> ans(n, 1);

        for (int i = 0; i < n; ++i)
        {
            ans[i] *= prefix;
            prefix *= nums[i];
        }
        prefix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] *= prefix;
            prefix *= nums[i];
        }

        return ans;
    }
};