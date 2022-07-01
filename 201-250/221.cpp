class Solution
{
public:
    int maximalSquare(vector<vector<char> > &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < m; ++i)
        {
            int top_left = 0;
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    int tmp = dp[j + 1];
                    dp[j + 1] = min(min(dp[j + 1], dp[j]), top_left) + 1;
                    top_left = tmp;
                    ans = max(ans, dp[j + 1]);
                }
                else
                {
                    dp[j + 1] = 0;
                }
            }
        }

        return ans * ans;
    }
};