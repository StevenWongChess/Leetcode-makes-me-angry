class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix_max(n), postfix_min(n);
        prefix_max[0] = nums[0];
        for (int i = 1; i <= n - 3; ++i)
        {
            prefix_max[i] = max(nums[i], prefix_max[i - 1]);
        }
        postfix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 2; --i)
        {
            postfix_min[i] = min(nums[i], postfix_min[i + 1]);
        }

        int ans = 0;
        for (int i = 1; i <= n - 2; ++i)
        {
            if (prefix_max[i - 1] < nums[i] && nums[i] < postfix_min[i + 1])
                ans += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                ++ans;
        }

        return ans;
    }
};