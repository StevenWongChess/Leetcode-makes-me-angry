class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size(), f = 0, ans;
        for (int i = 0; i < n; ++i)
        {
            f += i * nums[i];
        }
        ans = f;
        for (int i = 0; i < n - 1; ++i)
        {
            f += nums[i] * n - sum;
            ans = max(ans, f);
        }
        return ans;
    }
};