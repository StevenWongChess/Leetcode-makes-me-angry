class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> dp{0};
        for (int i = 0; i < n; ++i)
        {
            int n = dp.size();
            for (int j = 0; j < n; ++j)
            {
                dp.push_back(dp[n - 1 - j] + n);
            }
        }

        return dp;
    }
};