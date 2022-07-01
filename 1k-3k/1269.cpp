class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        int MOD = 1000000000 + 7;
        int size = min(arrLen - 1, steps / 2) + 1;
        vector<int> dp(size, 0);
        dp[0] = 1;

        for (int i = 0; i < steps; ++i)
        {
            int left = 0;
            for (int j = 0; j < size; ++j)
            {
                int tmp = dp[j];
                dp[j] += left;
                dp[j] %= MOD;
                if (j != size - 1)
                {
                    dp[j] += dp[j + 1];
                    dp[j] %= MOD;
                }
                left = tmp;
            }
        }

        return dp[0];
    }
};