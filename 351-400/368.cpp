class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxsize = 1, element = nums[0];

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > maxsize)
            {
                maxsize = dp[i];
                element = nums[i];
            }
        }

        vector<int> ans;
        for (int i = n - 1; i >= 0; --i)
        {
            if (dp[i] == maxsize && element % nums[i] == 0)
            {
                ans.push_back(nums[i]);
                element = nums[i];
                maxsize--;
                if (maxsize <= 0)
                    break;
            }
        }

        return ans;
    }
};