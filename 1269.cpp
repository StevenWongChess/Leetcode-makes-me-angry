class Solution {
public:
    int numWays(int steps, int arrLen) {
        int size = min(steps, arrLen - 1);
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < steps; i++){
            int prev = 0;
            for(int j = 0; j <= size; j++){
                int tmp = dp[j];
                int sum = ((j > 0 ? prev : 0) + (j < size ? dp[j + 1] : 0)) % 1000000007;
                dp[j] += sum;
                dp[j] = dp[j] % 1000000007;
                prev = tmp;
            }
        }
        return dp[0];
    }
};