class Solution
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > &updates)
    {
        int n = length;
        vector<int> dp(n);
        for (auto i : updates)
        {
            dp[i[0]] += i[2];
            if (i[1] < n - 1)
            {
                dp[i[1] + 1] -= i[2];
            }
        }
        for (int i = 1; i < n; ++i)
        {
            dp[i] += dp[i - 1];
        }
        return dp;
    }
};