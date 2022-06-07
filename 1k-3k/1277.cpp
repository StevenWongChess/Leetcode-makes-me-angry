class Solution
{
public:
    int countSquares(vector<vector<int> > &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i)
        {
            int left = dp[0];
            dp[0] = matrix[i][0] == 1 ? 1 : 0;
            ans += dp[0];

            for (int j = 1; j < n; ++j)
            {
                int tmp = dp[j];
                if (matrix[i][j] == 1)
                {
                    dp[j] = min(min(dp[j], dp[j - 1]), left) + 1;
                }
                else
                {
                    dp[j] = 0;
                }
                left = tmp;
                ans += dp[j];
            }
        }

        return ans;
    }
};