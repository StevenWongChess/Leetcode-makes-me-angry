class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> v(n + 2);
        v[0] = v[n + 1] = 1;
        for(int i = 0; i < n; ++i){
            v[i + 1] = nums[i];
        }
        
        for(int i = n - 1; i >= 0; --i){
            for(int j = i + 2; j <= n + 1; ++j){
                for(int k = i + 1; k < j; ++k){
                    int sum = v[i] * v[j] * v[k];
                    sum += dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        
        return dp[0][n + 1];
    }
};