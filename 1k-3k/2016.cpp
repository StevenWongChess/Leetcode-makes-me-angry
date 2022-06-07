class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int prefix_min = nums[0];
        int ans = -1;
        for (int i = 1; i < n; ++i)
        {
            auto diff = nums[i] - prefix_min;
            if (diff > 0)
                ans = max(ans, diff);
            prefix_min = min(prefix_min, nums[i]);
        }
        return ans;
    }
};