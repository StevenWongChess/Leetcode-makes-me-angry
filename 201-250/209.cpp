class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(), l = 0, ans = n + 1, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];

            while (l <= i && sum >= target)
            {
                ans = min(ans, i - l + 1);
                sum -= nums[l];
                ++l;
            }
        }

        return ans > n ? 0 : ans;
    }
};