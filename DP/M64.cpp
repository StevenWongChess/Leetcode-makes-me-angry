class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < m; i++){
            int left = i == 0 ? 0 : INT_MAX;
            for(int j = 0; j < n; j++){
                dp[j] = min(left, dp[j]) + grid[i][j];
                left = dp[j];
            }
        }
        return dp[n - 1];
    }
};