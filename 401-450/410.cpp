class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<long>> dp(n + 1, vector<long>(k + 1, LONG_MAX));
        vector<long> prefix(n + 1, 0);
        for(int i = 0; i < n; ++i){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= min(i, k); ++j){
                for(int t = 0; t < i; ++t){
                    dp[i][j] = min(dp[i][j], max(dp[t][j - 1], prefix[i] - prefix[t]));
                }
            }
        }

        return dp[n][k];
    }
};