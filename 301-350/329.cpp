class Solution {
public:
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j] > 0)
            return dp[i][j];;
        ++dp[i][j];
        int m = matrix.size(), n = matrix[0].size();
        for(auto [dx, dy]: directions){
            auto x = i + dx, y = j + dy;
            if(x >= 0 && x < m && y >= 0 && y < n  && matrix[x][y] > matrix[i][j]){
                dp[i][j] = max(dp[i][j], dfs(dp, matrix, x, y) + 1);
            }
        }
        return dp[i][j];
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
               ans = max(ans, dfs(dp, matrix, i, j));
            }
        }
        return ans;
    }
};