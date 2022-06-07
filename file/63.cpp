class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i)
        {
            int left = i == 0 ? 1 : 0;
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                    left = 0;
                }
                else
                {
                    dp[j] += left;
                    left = dp[j];
                }
            }
        }

        return dp[n - 1];
    }
};