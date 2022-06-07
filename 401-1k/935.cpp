class Solution
{
public:
    int knightDialer(int n)
    {
        vector<int> dp(10, 1);
        int MOD = 1000000000 + 7;
        vector<vector<int> > steps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}};

        for (int i = 1; i < n; ++i)
        {
            vector<int> next(10, 0);
            for (int i = 0; i < 10; ++i)
            {
                for (auto j : steps[i])
                {
                    next[i] += dp[j];
                    next[i] %= MOD;
                }
            }
            swap(next, dp);
        }
        int ans = 0;
        for (auto i : dp)
        {
            ans += i;
            ans %= MOD;
        }
        return ans;
    }
};