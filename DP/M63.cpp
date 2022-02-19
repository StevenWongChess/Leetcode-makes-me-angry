class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            int left = 0;
            for(int j = 0; j < n; j++){
                dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j] + left;
                left = dp[j];
            }
        }
        return dp[n - 1];
    }
};