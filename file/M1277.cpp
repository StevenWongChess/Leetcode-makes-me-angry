class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++){
            int left = dp[0];
            dp[0] = matrix[i][0];
            ans += dp[0];
            for(int j = 1; j < n; j++){
                int tmp = dp[j];
                dp[j] = matrix[i][j] == 1 ? min(min(dp[j], dp[j - 1]), left) + 1 : 0;
                left = tmp;
                ans += dp[j];
            }
        }
        return ans;
    }
};