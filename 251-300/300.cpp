class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), it = 0;
        vector<int> dp(n + 1, 0);
        dp[0] = -10001;

        for (auto i : nums)
        {
            if (i > dp[it])
            {
                ++it;
                dp[it] = i;
            }
            else
            {
                int l = 1, r = it, pos = 0;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (dp[mid] < i)
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                dp[pos + 1] = i;
            }
        }
        return it;
    }
};