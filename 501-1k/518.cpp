class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(auto j: coins){
            for(int i = 1; i <= amount; i++){
                if(i >= j){
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[amount];
    }
};